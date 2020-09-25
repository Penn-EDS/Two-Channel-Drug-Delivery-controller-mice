//************************************************************************
/*
 Servo.cpp - Interrupt driven Servo library for Arduino using 16 bit timers
 Copyright (c) 2009 Michael Margolis.  All right reserved.
 Revision date: 08/18/2011(Michelle Yu)

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
//************************************************************************

/*
 A servo is activated by creating an instance of the Servo class passing 
 the desired pin to the attach() method. The servos are pulsed in the 
 background using the value most recently written using the write() method

 Note that analogWrite of PWM on pins associated with the timer are 
 disabled when the first servo is attached. Timers are seized as needed in 
 groups of 8 servos - 16 servos use two timers, 24 servos will use three.

 For the PIC32, the three timers that are used are (in order):
 Timer4 (for 1 through 8 servos)
 Timer5 (for 9 through 16 servos)
 Timer3 (for 17 through 24 servos)
 Note: These timers (and their prescale value) is set up in int.c

 Be careful that other libraries do not use any of the timers that you need 
 for your servos.

 The methods are:

 Servo - Class for manipulating servo motors connected to Arduino pins.

 attach(pin ) - Attaches a servo motor to an i/o pin.
 attach(pin, min, max  ) - Attaches to a pin setting min and max values in 
              microseconds default min is 544, max is 2400

 write()      - Sets the servo angle in degrees.  (invalid angle that is 
              valid as pulse in microseconds is treated as microseconds)
 writeMicroseconds() - Sets the servo pulse width in microseconds
 read()       - Gets the last written servo pulse width as an angle between 
              0 and 179.
 readMicroseconds()   - Gets the last written servo pulse width in 
              microseconds.
 attached()   - Returns true if there is a servo attached.
 detach()     - Stops an attached servos from pulsing its i/o pin.

*/
//************************************************************************
//* Edit History
//************************************************************************
//* Aug 21, 2011  <GeneApperson> fixed floating point issue by changing 
//*               to integer math
//* Sep  1, 2011  <MLS> Cleaning up formatting
//* Sep  1, 2011  <MLS> Cleaning up formatting
//* Sep  1, 2011  <MLS> issue #112, changed assignment to compare in finISR
//* Sep  5, 2011  <GeneApperson> added include of plib.h to fix compile 
//*               errors introduced when plib.h was removed from 
//*               HardwareSerial.h
//* Sep 18, 2012  <BPS> Fixed math problem with refresh interval, and
//*               expanded nbr to 7 bits for pins above 63 (MAX32 has 83)
//*               And adjusted trim to 1 tick (measured and adjusted)
//* Feb  7, 2013  <GeneApperson> Removed dependency on Microchip plib 
//*               library
//* Sep  9, 2018  <BPS> Made library aware of CPU speed so it can run on
//*               wider array of chipKIT boards
//************************************************************************

#include "Servo.h"

extern "C" {
  #include "int.h"
}

// All timers are set up to be clocked at PCLK/32, but this code does not
// initialize them. That's done in the core Arduino code (int.c in this case)
// On 80MHz chipKIT boards, timers are running at 1.25 MHz (divide  by 64)
// On 48Mhz chipKIT boards, timers are running at 1.5 MHz (divide by 32)
// On 40MHz chipKIT boards, timers are running at 1.25 MHz (divide by 32)

/// TODO: What would be great is if this could be re-written to be dynamic.
/// getPeripheralClock() can be used along with reading the actual divider
/// value currently set in the timer to compute the proper value for abort
/// usToTicks() function, which could then properly (dynamically) adjust to
/// the CPU clock being sped up or down and the timer prescaler changing.

// converts microseconds to tick
#if F_CPU == 40000000UL
  #define usToTicks(_us)      (((_us)*5)/4)
#elif F_CPU == 48000000UL
  #define usToTicks(_us)      (((_us)*3)/2)
#elif F_CPU == 80000000UL
  #define usToTicks(_us)      (((_us)*5)/4)
#elif F_CPU == 200000000UL  // untested
  #define usToTicks(_us)      (((_us)*25)/8)
#else
  #define usToTicks(_us)      (((_us)*5)/4)
  #warning Servo.cpp detected unsupported CPU clock speed. Defaulting to 80MHz.
#endif

// converts from ticks back to microseconds
#if F_CPU == 40000000UL
  #define ticksToUs(_ticks)   ((((unsigned)(_ticks))*4)/5)
#elif F_CPU == 48000000UL
  #define ticksToUs(_ticks)   ((((unsigned)(_ticks))*2)/3)
#elif F_CPU == 80000000UL
  #define ticksToUs(_ticks)   ((((unsigned)(_ticks))*5)/4)
#elif F_CPU == 200000000UL  // untested
  #define ticksToUs(_ticks)   ((((unsigned)(_ticks))*8)/25)
#else
  #define ticksToUs(_ticks)   ((((unsigned)(_ticks))*5)/4)
#endif

// compensation ticks to trim adjust for digitalWrite delays
// 12 August 200
#define TRIM_DURATION       1

// static array of servo structures
static servo_t servos[MAX_SERVOS];
// channel for the current servo
int channel[3];

// the total number of attached servos
uint8_t ServoCount = 0;

// minimum value in uS for this servo
#define SERVO_MIN() (MIN_PULSE_WIDTH - this->min * 4)
// maximum value in uS for this servo
#define SERVO_MAX() (MAX_PULSE_WIDTH - this->max * 4)
// macro to access servo index by timer and channel
#define SERVO_INDEX(_timer,_channel) ((_timer*SERVOS_PER_TIMER) + _channel)
// returns the timer controlling this servo
#define SERVO_INDEX_TO_TIMER(_servo_nbr) ((int)(_servo_nbr / SERVOS_PER_TIMER))
// macro to access servo class by timer and channel
#define SERVO(_timer,_channel) (servos[SERVO_INDEX(_timer,_channel)])
/************ static functions common to all instances ***********************/

//************************************************************************
// Note: PIC32 timers (TMRn) reset to zero when they match PRn.
void handle_interrupts(int timer, volatile unsigned int *TMRn, volatile unsigned int *PRn)
{
  // Store the number of ticks since the first rising edge for this timer
  static uint32_t AccumulatedTicks[3] = {0,0,0};

  // Test for invalid timer number
  if (timer >= 3)
  {
    return;
  }

  // If this value is -1, then we have just finished with the time from 
  // the end of the last pulse and need to start with the first servo 
  // index on this timer again.
  if ( channel[timer] < 0 )
  {
    // Clear the accumulated time for this timer on first rising edge
    AccumulatedTicks[timer] = 0;
  }
  else
  {
    // If this is not the first pulse, then set the old pin low
    if ( SERVO_INDEX(timer,channel[timer]) < ServoCount && SERVO(timer,channel[timer]).Pin.isActive == true )
    {
      // pulse this channel low if activated
      digitalWrite( SERVO(timer,channel[timer]).Pin.nbr, LOW);
    }
  }

  // increment to the next channel
  channel[timer]++;
  // If we have not run out of channels (on this timer),
  if ( SERVO_INDEX(timer,channel[timer]) < ServoCount && channel[timer] < SERVOS_PER_TIMER)
  {
    // Then set the time we want to fire next (the width for this channel)
    *PRn  = SERVO(timer,channel[timer]).ticks;
    // Set this channel's pin high if its active
    // check if activated
    if (SERVO(timer,channel[timer]).Pin.isActive == true)
    {
      // its an active channel so pulse it high
      digitalWrite( SERVO(timer,channel[timer]).Pin.nbr, HIGH);
    }
    // Add the time we are about to spend on this channel
    AccumulatedTicks[timer] += *PRn;
  }
  else
  {
    // Otherwise, finished all channels so next fire needs to be at 
    // REFRESH_INTERVAL - AccumulatedTicks
    if (AccumulatedTicks[timer] < (usToTicks(REFRESH_INTERVAL) - 4))
    {
      *PRn  = (unsigned int)(usToTicks(REFRESH_INTERVAL)) - AccumulatedTicks[timer];
    }
    else
    {
      // at least REFRESH_INTERVAL has elapsed
      *PRn  = *TMRn + 4;
    }
    // this will get incremented at the end of the refresh period to 
    // start again at the first channel
    channel[timer] = -1;
  }
}

//************************************************************************
static void finISR(int timer)
{
  //disable use of the given timer
  if (timer == TIMER3)
  {
    // disable T3 interrupt
    IEC0bits.T3IE = 0;
  }
  if (timer == TIMER4)
  {
    // disable T4 interrupt
    IEC0bits.T4IE = 0;
  }
  if (timer == TIMER5)
  {
    // disable T5 interrupt
    IEC0bits.T5IE = 0;
  }
}

//************************************************************************
static boolean isTimerActive(int timer)
{
  // returns true if any servo is active on this timer
  for (uint8_t channel=0; channel < SERVOS_PER_TIMER; channel++)
  {
    if (SERVO(timer,channel).Pin.isActive == true)
    {
      return true;
    }
  }
  return false;
}

/****************** end of static functions ******************************/

Servo::Servo()
{
  if (ServoCount < MAX_SERVOS)
  {
    /// TODO: Really, we need to search through servos[] for the first one
    /// that is not being used, rather than always use ServoCount as the
    /// index. What happens if you create 24 servos, then destroy one
    /// and create another. Right now that would fail, even though you
    /// weren't actively using 24 servos.

    // assign a servo index to this instance
    this->servoIndex = ServoCount++;
    // store default to neutral position
    servos[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);
  }
  else
  {
    // too many servos
    this->servoIndex = INVALID_SERVO ;
  }
}

//************************************************************************
uint8_t Servo::attach(int pin)
{
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

//************************************************************************
uint8_t Servo::attach(int pin, int min, int max)
{
  if (this->servoIndex < ServoCount)
  {
    // set servo pin to output
    pinMode(pin, OUTPUT);
    servos[this->servoIndex].Pin.nbr = pin;
    // resolution of min/max is 4 uS
    this->min = (MIN_PULSE_WIDTH - min)/4;
    this->max = (MAX_PULSE_WIDTH - max)/4;
    // initialize the timer if it has not already been initialized
    int timer = SERVO_INDEX_TO_TIMER(this->servoIndex);
    if (isTimerActive(timer) == false)
    {
      initISR(timer);
    }
    // this must be set after the check for isTimerActive
    servos[this->servoIndex].Pin.isActive = true;

    return this->servoIndex;
  }
    else
    {
      // return bogus value if this->ServoIndex is invalid
      return(INVALID_SERVO);
    }
}

//************************************************************************
void Servo::detach()
{
  servos[this->servoIndex].Pin.isActive = false;
  int timer = SERVO_INDEX_TO_TIMER(servoIndex);
  if (isTimerActive(timer) == false)
  {
    finISR(timer);
  }
}

//************************************************************************
void Servo::write(int value)
{
  if (value < MIN_PULSE_WIDTH)
  {
    // treat values less than 544 as angles in degrees (valid values in 
    // microseconds are handled as microseconds)
    if (value < 0)
    {
      value = 0;
    }
    if (value > 179)
    {
      value = 179;
    }

    value = map(value, 0, 179, SERVO_MIN(), SERVO_MAX());
  }
  this->writeMicroseconds(value);
}

//************************************************************************
void Servo::writeMicroseconds(int value)
{
  // calculate and store the values for the given channel
  byte channel = this->servoIndex;
  // ensure channel is valid
  if ( (channel < MAX_SERVOS) )
  {
    // ensure pulse width is valid
    if ( value < SERVO_MIN() )
    {
      value = SERVO_MIN();
    }
    else if ( value > SERVO_MAX() )
    {
      value = SERVO_MAX();
    }

    value = value - TRIM_DURATION;
    // convert to ticks after compensating for interrupt overhead
    value = usToTicks(value);

    unsigned int status;
    status = disableInterrupts();
    servos[channel].ticks = value;
    restoreInterrupts(status);
  }
}

//************************************************************************
int Servo::read() // return the value as degrees
{
  return map( this->readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);
}

//************************************************************************
int Servo::readMicroseconds()
{
  unsigned int pulsewidth;
  if ( this->servoIndex != INVALID_SERVO )
  {
    // 12 aug 2009
    pulsewidth = ticksToUs(servos[this->servoIndex].ticks) + TRIM_DURATION;
  }
  else
  {
    pulsewidth  = 0;
  }

  return pulsewidth;
}

//************************************************************************
bool Servo::attached()
{
  return servos[this->servoIndex].Pin.isActive;
}
