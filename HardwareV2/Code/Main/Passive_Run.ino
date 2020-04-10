void PassiveStart(){
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

myFile.println((String)"Animal #1:,"+animalnamepassive1);
myFile.println((String)"Animal #2:,"+animalnamepassive2);
myFile.println((String)"Animal #3:,"+animalnamepassive3);
myFile.println((String)"Animal #4:,"+animalnamepassive4);
myFile.println((String)"Animal #5:,"+animalnamepassive5);
myFile.println((String)"Animal #6:,"+animalnamepassive6);
myFile.println((String)"Animal #7:,"+animalnamepassive7);
myFile.println((String)"Animal #8:,"+animalnamepassive8);

drug=0;
Numpuffcounter=1;
delay(300);
ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
    delay(2000);
    goto cancelpassive;
  }
puffIntinmiliseconds=(PuffIntmin*60*1000)+(PuffIntsec*1000);


while(Numpuffcounter <= PuffMaxQuantity){   //  passive vaping code
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
  ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
    delay(2000);
    goto cancelpassive;
  }

  digitalWrite(vape1,HIGH);
  digitalWrite(vape2,HIGH);
  delay(Puffmiliseconds);
  digitalWrite(vape1,LOW);
  digitalWrite(vape2, LOW);
  
  puffIntcounter=0;
  
  while(puffIntcounter<=puffIntinmiliseconds){
    delay(100);
    puffIntcounter=puffIntcounter+100;
    ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
      myFile.println("THIS SESSION WAS CANCELLED");
    delay(2000);
    goto cancelpassive;
  }
    
  }
  
  Numpuffcounter=Numpuffcounter + 1;
  
}
cancelpassive:
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
