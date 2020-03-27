#include "RTClib.h"
#include "Arduino.h"
#define lcd Serial1 // with lcd serial1
RTC_DS1307 rtc;

//-----Scanner and SD functions and librarys----
#include <usbhid.h>
#include <usbhub.h>
#include <hiduniversal.h>
#include <hidboot.h>
#include <SPI.h>
#include <SD.h>
File myFile;

const int SDcs = 22;  //SD slave pin 
const int USBcs=10;   //USB slave pin
int readed = 0;
String barcodeword="";
String username="";
String animalname="";
String drugname="";

class MyParser : public HIDReportParser {
  public:
    MyParser();
    void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
  protected:
    uint8_t KeyToAscii(bool upper, uint8_t mod, uint8_t key);
    virtual void OnKeyScanned(bool upper, uint8_t mod, uint8_t key);
    virtual void OnScanFinished();
};

MyParser::MyParser() {}

void MyParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
  // If error or empty, return
  if (buf[2] == 1 || buf[2] == 0) return;

  for (uint8_t i = 7; i >= 2; i--) {
    // If empty, skip
    if (buf[i] == 0) continue;

    // If enter signal emitted, scan finished
    if (buf[i] == UHS_HID_BOOT_KEY_ENTER) {
      OnScanFinished();
    }

    // If not, continue normally
    else {
      // If bit position not in 2, it's uppercase words
      OnKeyScanned(i > 2, buf, buf[i]);
    }

    return;
  }
}

uint8_t MyParser::KeyToAscii(bool upper, uint8_t mod, uint8_t key) {
  // Letters
  if (VALUE_WITHIN(key, 0x04, 0x1d)) {
    if (upper) return (key - 4 + 'A');
     else return (key - 4 + 'A');
  }

  // Numbers
  else if (VALUE_WITHIN(key, 0x1e, 0x27)) {
    return ((key == UHS_HID_BOOT_KEY_ZERO) ? '0' : key - 0x1e + '1');
  }

  return 0;
}

void MyParser::OnKeyScanned(bool upper, uint8_t mod, uint8_t key) {
  uint8_t ascii = KeyToAscii(upper, mod, key);
  //Serial.print((char)ascii);
 barcodeword += (char)ascii;
}

void MyParser::OnScanFinished() {
  readed = 1;
}

USB          Usb;
USBHub       Hub(&Usb);
HIDUniversal Hid(&Usb);
MyParser     Parser;

// 
// Use this Preprocessor directive during debugging
// It will print stuff @ the Serial port
// Comment this out and we will be out the DEBUG mode
//
//#define DEBUG

// Hardware (global) variables

int BB = 3; // Button B to pin 3
int BC = 6; // Button C to pin 6
int BD = 5; // Button D to pin 5
int BA = 4; // Button A to pin 4

int vape1=9;   // Pin 9 assigned to vape1 signal
int vape2=2;  // Pin 2 assigned to vape2 signal
int LED1=12;   // LED1
int LED2=11;   // LED2

// Button Status variables
// Buttons are Active Low: Go to logic 0 when pressed
int ButtonA = 0;
int ButtonB = 0;
int ButtonC = 0;
int ButtonD = 0;

int ButtonDstate=LOW;

//**  Flags for while loops
int J=0;
int M=1;
int L1=0;
int L2=0;

// Wheel variables

int W1 = 8; //wheel 1 to pin 8
int Wheel1State = 0;         
int lastWheel1State = 0; 
int W1Step=0; // eight times is one turn
int W1Turn=0;
unsigned long wheel1stopcountertimemilis=0;
int R1=0;
//
int W2 = 7;  // wheel 2 to pin 7
int Wheel2State = 0;         
int lastWheel2State = 0; 
int W2Step=0; // eight times is one turn
int W2Turn=0;
unsigned long wheel2stopcountertimemilis=0;
int R2=0;

int Step = 8;
unsigned int XrCycles = 10000;

// Passive mode variables with default values
int Puffmiliseconds = 150;
unsigned long  PuffIntmin = 1;  //** Puff interval minutes with 1minute default val
unsigned long PuffIntsec = 0;  //** Puff inteval sec

int PuffMaxQuantity=10;
int Numpuffcounter=1; 

int drug=0;           //flag to know if enter 
int fivemindelay=5;
int fivemincounter = 1;
int fiveminprintcounter=0;
unsigned long onemincounter=0;
unsigned long puffIntinmiliseconds;
unsigned long puffIntcounter=0;

// Active mode variables with default values
int primingpuff = 1;            //  1 YES   0 NO
int whichvapepriming = 1;       // if priming yes, Which one?
int vapepriming=0;              // variable part of the which priming loop
int LEDpriming=0;               // variable part of the which priming loop
int LEDstatuspriming=0;         // variable part of the which priming loop

int whichvapeactive=1;

unsigned long Postresponsetimeout=5;       // Seconds
unsigned long Postresponsetimeoutmilis=0;   // miliseconds 


int LED1status = 1;               // LED1 status: 1=ON 0=OFF
int LED2status = 1;             // LED2 status: 1=ON 0=OFF

unsigned long SessionLengthMinutes = 2;
unsigned long SessionLengthHours = 0;
unsigned long SessionLengthInMiliseconds = 0;
unsigned long previoustime = 0;
unsigned long previoustime2 = 0;
unsigned long milisleft = 0;
float minutesleft = 0.0; 
unsigned long previousSeccionTimeout=0;

int ifSessionTimeOut=1;
unsigned long SessionTimeOutmin = 3;
unsigned long SessionTimeOutsec = 0;
unsigned long SessionTimeOutmilis = 0;


unsigned int fixedresponseratio = 5;
unsigned int SpinNottriggercheck = 0;

unsigned long ArithmeticConstant = 2;
unsigned long ArithmeticConstantSum1 = 0;
unsigned long ArithmeticConstantSum2 = 0;

unsigned long RG1=1;
unsigned long RG2=1;
unsigned long WG1=1;
unsigned long WG2=1;

void setup()
{
    Serial.begin(9600);
    lcd.begin(9600);
    pinMode(W1, INPUT_PULLUP);  //wheel1 pin 8, 20K pullup
    pinMode(W2, INPUT_PULLUP);  //wheel2 pin 7
    pinMode(BA, INPUT_PULLUP); // button A
    pinMode(BB,INPUT_PULLUP); // button B
    pinMode(BC,INPUT_PULLUP); // button C
    pinMode(BD,INPUT_PULLUP); // button D
    pinMode(vape1,OUTPUT);    // vape 1 pin 9 
    pinMode(vape2,OUTPUT);    // vape 2 pin 2
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
  
    // ** to use in Active mode **// 
    Wheel1State=digitalRead(W1);
    Wheel2State=digitalRead(W2);
    lastWheel1State = Wheel1State;
    lastWheel2State = Wheel2State;
  
    // set  backlight on("ON")  or off("OFF")
    LCDBacklight("ON");
  
    // set the size of the display if it isn't 16x2 (you only have to do this once)
    LCDSize( 20, 4);
      
    // set auto line wrap on("ON")  or off("OFF")
    LCD_Auto_Line_Wrap("ON");
    
    // set the contrast, 200 is a good place to start, adjust as desired
    LCDcontrast(200);  
    
    // set the brightness - we'll max it (255 is max brightness)
    LCDBrightness(250); 

    // turn off/on cursors on("ON")  or off("OFF")
    LCDcursor_Enable_Disable("ON");

    // clear LCD
    LCDclear();
  
    // go 'home'
    LCDHome();
     
    delay(1500);

    lcd.println("DRUG ACTIVE_PASSIVE");
    lcd.println("Administration And");            // to print the custom character, 'write' the location
    lcd.print("Monitoring Device");
    delay(10);

    // set cursor position 
     LCDSetCursorPosition(18,3);
     delay(2000);
     
    // Move Cursor. For forware Write "F" and for Back Write "B" 
    //LCDMoveCursor("F") 
      delay(1000);
      LCDRGBColor(0,255,0);
      delay(2000);
      LCDclear();

      if (! rtc.begin()) {
        LCDclear();
        LCDHome();
        lcd.print("Couldn't find RTC");
           while (1);
       }

       if (! rtc.isrunning()) {
          LCDclear();
          LCDHome();
          lcd.print("RTC is NOT running!");
           while (1);
         }

  //Use one of this to Function to set the date/time of the RTC. After uplouding the code, COMMENT this two lines and RE-Upload the CODE. 
         //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // following line sets the RTC to the date & time this sketch was compiled
                  
                  //OR

         //rtc.adjust(DateTime(2020, 3, 25, 14, 59, 0));  // This line sets the RTC with an explicit date & time, for example to set: January 21, 2014 at 3am you would call:  rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0)); like this rtc.adjust(DateTime(year, month, day, military hour, minutes, seconds));


//---------USB host initialization--------
          pinMode(USBcs,OUTPUT);
          pinMode(SDcs,OUTPUT);

          digitalWrite(SDcs,HIGH);
          digitalWrite(USBcs,LOW);
        
          if (Usb.Init() == -1) {
            Serial.println("OSC did not start.");
            }
        
          delay( 200 );
        
          Hid.SetReportParser(0, &Parser);
        
          digitalWrite(USBcs,HIGH);
          digitalWrite(SDcs,LOW);
        //--------USB initialization Done-------
        
          delay(1000);
          
        //------SD card initialization------------   
          if (!SD.begin(SDcs)) {
            Serial.println("SD initialization failed!");
            while (1);
            }
        
          Serial.println("SD initialization done.");
          
           myFile = SD.open("test.txt", FILE_WRITE);
           myFile.close();
        
          digitalWrite(SDcs,HIGH);
          digitalWrite(USBcs,LOW);
         //------SD card initialization DONE------------ 

}


void loop() {
//***** MAIN Menu 
  main:

    UserName();
    AnimalName();
    DrugName();
    
    LCDclear();
    LCDHome();
    lcd.print(" For Passive press A ");
    LCDSetCursorPosition(1,2);
    lcd.print(" For Active  press B ");
    LCDSetCursorPosition(2,3);
    delay(200);

    //
    // Loop to select the operation type: Pasive of Active  
    //
    while(1){
      
      
      // PASSIVE LOOP
      if ((ButtonA = digitalRead(BA))==LOW){  
        Passreview:
          delay(200);
          PuffLengthselect();
          delay(200);
          PuffIntSelect();
          delay(200);
          PuffMaxNum();
        //REVIEW PASSIVE PARAMETERS OR RUN
          LCDclear();
          LCDHome();
          lcd.print(" Press: A to Review ");
          lcd.print(" Press: B to Start ");
          while(1){
              delay(200);
              
              if ( (ButtonA=digitalRead(BA)) == LOW){
                  delay(200);
                  goto Passreview;
              }
              if ( (ButtonB = digitalRead(BB)) == LOW){   
                  delay(200);
                  PassiveStart();
                  fivemincleaning();
                  goto main;
              }
          }
     J=1;
   }

//****** ACTIVE LOOP
      if((ButtonB = digitalRead(BB))==LOW){
         Activereview:

           whichvapeActive();
           delay(200);
           Primingpuff();
           delay(200);
           PuffLengthselect();
           delay(200);
           PostResponseTimeOut();
           delay(200);
           CueLight();
           delay(200);
           sessionLength();
           delay(200);
           PuffMaxNum();
           delay(200);
           
           
           //Fixed Ratio or progressive Ratio
           
          LCDclear();
          LCDHome();
          lcd.print("Fixed or Progressive");
          LCDSetCursorPosition(1,3);
          lcd.print(" A for Fixed ");
          LCDSetCursorPosition(1,4);
          lcd.print(" B for Progressive ");
          delay(1000);
          
           while(1){
            
             
               
            //Fixed Ratio
             if((ButtonA=digitalRead(BA)) == LOW){
              
              FixedResponseRatio();
              delay(200);
              
              //REVIEW PASSIVE PARAMETERS OR RUN Fixed Ratio
                LCDclear();
                LCDHome();
                lcd.print(" Press: A to Review ");
                lcd.print(" Press: B to Start ");
                while(1){
                   delay(200);
                   
                 if ( (ButtonA=digitalRead(BA)) == LOW){
                     delay(200);
                    //review Active parameters
                   goto Activereview;
                   }
                 if ( (ButtonB = digitalRead(BB)) == LOW){     
                    delay(200);
                    //start fixed ratio loop
                    FixedRatioStart();
                    fivemincleaning();
                    goto main;
                    }
                }
                
              J=1;
             }


            //Progressive Ratio
             if((ButtonB = digitalRead(BB)) == LOW){
                  delay(100);
                IFSessionTimeOut();  // YES or NO SessionTimeOut?  IF(YES): session ended after X time of animal inactivity. Asking for that time. IF(N0): SessionTimeOut will be bigger than Seccion Lenght. 
                //SessionTimeOut();    // session ended after X time of animal inactivity. Asking for that time. 
                LCDclear();
                LCDHome();
                lcd.print ("Press:");
                LCDSetCursorPosition(1,2);
                lcd.print("   A for Arithmetic");
                LCDSetCursorPosition(1,3);
                lcd.print("   B for Geometric ");

                while(1){
                  delay(200);

                  // Arithmetic
                  if ( (ButtonA=digitalRead(BA)) == LOW){
                    delay(200);
                    ArithmeticMultiplier();
                    delay(200);
                    //REVIEW PASSIVE PARAMETERS OR RUN Geometric
                      LCDclear();
                      LCDHome();
                      lcd.print(" Press: A to Review ");
                      lcd.print(" Press: B to Start ");
                      while(1){
                       delay(200);
                   
                      if ( (ButtonA=digitalRead(BA)) == LOW){
                          delay(200);
                         //review Active parameters
                        goto Activereview;
                         }
                      if ( (ButtonB = digitalRead(BB)) == LOW){     
                          delay(200);
                         //start fixed ratio loop
                          ArithmeticRatioStart();
                          fivemincleaning();
                          goto main;
                          }
                      }
                    
                   }

                   // Geometric
                  if ( (ButtonB = digitalRead(BB)) == LOW){
                    delay(200);

                    //REVIEW PASSIVE PARAMETERS OR RUN Geometric
                      LCDclear();
                      LCDHome();
                      lcd.print(" Press: A to Review ");
                      lcd.print(" Press: B to Start ");
                      while(1){
                       delay(200);
                   
                      if ( (ButtonA=digitalRead(BA)) == LOW){
                          delay(200);
                         //review Active parameters
                        goto Activereview;
                         }
                      if ( (ButtonB = digitalRead(BB)) == LOW){     
                          delay(200);
                         //start fixed ratio loop
                          GeometricRatioStart();
                          fivemincleaning();
                          goto main;
                          }
                      }
                    
                  }

                 
                }
         
              J=1;
             }

             if( J==1){
                 J=0;
               LCDclear();
               LCDHome();
               lcd.print(" To Main ");
               delay(2000);
               goto main;
              }

          }
           
           
           J=1;
      }
      
      if( J==1){
        J=0;
        LCDclear();
        LCDHome();
        lcd.print(" To Main ");
        delay(2000);
        goto main;
      }
 }
}
