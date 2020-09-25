void PassiveStart(){
SDini();
digitalWrite(SDcs,LOW);
delay(300);
LCDclear();
LCDHome();
lcd.print(" Passive Session ON ");
LCDSetCursorPosition(1,2);
lcd.print("# Puff Past:");
lcd.print(Numpuffcounter);
LCDSetCursorPosition(1,3);
lcd.print("Total # of Puff:");
lcd.print(PuffMaxQuantity);
LCDSetCursorPosition(1,4);
lcd.print("PRESS B to Cancel");

CreateFile();
RTCDateTime();

myFile.println((String)"USER:,"+username);
myFile.println((String)"Drug:,"+drugname);
myFile.println("Schedule:,Passive");
myFile.println((String)"Puff Length(miliseconds):,"+Puffmiliseconds);
myFile.println((String)"Puff Interval(m:s):,"+PuffIntmin+":"+PuffIntsec);
myFile.println((String)"Max # Puff:,"+ PuffMaxQuantity);

<<<<<<< HEAD
myFile.println((String)"Animal #1:,"+animalnamepassive1);
myFile.println((String)"Animal #2:,"+animalnamepassive2);
myFile.println((String)"Animal #3:,"+animalnamepassive3);
myFile.println((String)"Animal #4:,"+animalnamepassive4);
myFile.println((String)"Animal #5:,"+animalnamepassive5);
myFile.println((String)"Animal #6:,"+animalnamepassive6);
myFile.println((String)"Animal #7:,"+animalnamepassive7);
myFile.println((String)"Animal #8:,"+animalnamepassive8);
=======
myFile.println((String)"Animal in Box#1:,"+animalnamepassive1);
myFile.println((String)"Animal in Box#2:,"+animalnamepassive2);
myFile.println((String)"Animal in Box#3:,"+animalnamepassive3);
myFile.println((String)"Animal in Box#4:,"+animalnamepassive4);
myFile.println((String)"Animal in Box#5:,"+animalnamepassive5);
myFile.println((String)"Animal in Box#6:,"+animalnamepassive6);
myFile.println((String)"Animal in Box#7:,"+animalnamepassive7);
myFile.println((String)"Animal in Box#8:,"+animalnamepassive8);
>>>>>>> 0322479833a051ad17614f3729ca344d5703778d

drug=0;
Numpuffcounter=1;
delay(300);
<<<<<<< HEAD
ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
    delay(2000);
    goto cancelpassive;
  }
=======
>>>>>>> 0322479833a051ad17614f3729ca344d5703778d
puffIntinmiliseconds=(PuffIntmin*60*1000)+(PuffIntsec*1000);


while(Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){   //  passive vaping code
  drug=1;
  LCDclear();
  LCDHome();
  lcd.print(" Passive Session ON ");
  LCDSetCursorPosition(1,2);
  lcd.print("# Puff Past:");
  lcd.print(Numpuffcounter);
  LCDSetCursorPosition(1,3);
  lcd.print("Total # of Puff:");
  lcd.print(PuffMaxQuantity);
  LCDSetCursorPosition(1,4);
  lcd.print("PRESS B to cancel");
<<<<<<< HEAD
  ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
    delay(2000);
    goto cancelpassive;
  }
=======
>>>>>>> 0322479833a051ad17614f3729ca344d5703778d

  digitalWrite(vape1,HIGH); 
  digitalWrite(vapeR1,HIGH);
  digitalWrite(vape2,HIGH); 
  digitalWrite(vapeR2,HIGH);
  delay(Puffmiliseconds);
  digitalWrite(vape1,LOW); 
  digitalWrite(vapeR1,LOW);
  digitalWrite(vape2,LOW); 
  digitalWrite(vapeR2,LOW);
  
  puffIntcounter=0;
  
  while(puffIntcounter<=puffIntinmiliseconds && digitalRead(BB)==HIGH){
    delay(100);
    puffIntcounter=puffIntcounter+100;
    }
  
  Numpuffcounter=Numpuffcounter + 1;
  
}
if (digitalRead(BB)==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
<<<<<<< HEAD
=======
      Numpuffcounter=Numpuffcounter-1;
      myFile.println((String)"# Puff Delivered:,"+ Numpuffcounter);
>>>>>>> 0322479833a051ad17614f3729ca344d5703778d
    delay(2000);
  }
myFile.close();
delay(100);
}



void fivemincleaning(){
  delay(100);

  if (drug==1){
    //the 5min cleaning 
    fivemincounter=1;
    fiveminprintcounter=0;
    while(fivemindelay>=fivemincounter){
      LCDclear();
      LCDHome();
      lcd.print(" Purging Chambers ");
      LCDSetCursorPosition(1,2);
      lcd.print("Elapsed Minutes: ");
      LCDSetCursorPosition(1,3);
      lcd.print(fiveminprintcounter);
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS B to Cancel");
      
      
      onemincounter=0;
      while(onemincounter<60000){
        delay(100);
       onemincounter=onemincounter+100;
       ButtonB=digitalRead(BB);
      if (ButtonB==LOW){
        LCDclear();
        LCDHome();
        lcd.print("Cleaning Cancel");
        delay(2000);
        goto cancelcleaning;
         }
      }
      
      fivemincounter=fivemincounter+1;
      fiveminprintcounter=fiveminprintcounter+1; 
      
    }
    cancelcleaning:
    delay(100);
  }

      LCDclear();
      LCDHome();
      lcd.print("  Purging Chambers");
      LCDSetCursorPosition(1,2);
      lcd.print("   Completed");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C to Main Menu");
      ButtonC = digitalRead(BC);
  while(ButtonC==HIGH){
    delay(150);
    ButtonC = digitalRead(BC);
    
  }
  delay(300);
  drug=0;
}
