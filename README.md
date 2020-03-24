# Two-Channel-Drug-Delivery-controller-mice
The project is a Two channel drug delivery controller. 
The system hardware can be divided in two categorize:

The Human interface:

   -microcontroller (mega2560)
   -RTC 
   -4 Push buttons 
   - LCD and LCD driver module. 
   - 28v power supply 
   - Adjustable Buck converter 
   - Two BJT(2N2222)

Mouse Interface(the next items are part of a chamber):

  -Two vaporizer ( The vaporizer deliver the drug to a chamber). This is EDS custom. 
  -Two LED ENV-321M
  - Two Wheel Spins  ENV-113AM
The device has two modes:
   -Passive: The number of Puff(vaporizer delivery) can be set up by the User. Also can be set the length of Puff and the time between Puff. 
   -Active: In the active mode the mice interact with the wheels. Each wheel is related to one of the vaporizer and one of the LED(example: Wheel 1 with vaporizer 1 and Wheel 2 with vaporizer 2). The active mode can be devided in three more submodes:
      - Fixed ratio: The number of spin needed for a delivery is fix.
      - Arithmetic progressive ratio: The number of spin wheels needed increase by the number puff.
            Number of spins needed = n*p ,  where n(n is submitted be the user) is the number ratio and p the number of the next puff. p number start with 1.
            Geometric progressive ratio: Wheel spin needed = ((5*e^(R*0.2))-5) , where R is the number of spin of the next puff. R number start with 1.
