void PassiveStart(){
LCDclear();
LCDHome();
lcd.print(" Passive Section ON ");
LCDSetCursorPosition(1,2);
lcd.print("# puff Past:");
lcd.print(Numpuffcounter);
LCDSetCursorPosition(1,3);
lcd.print("Total # of Puff:");
lcd.print(PuffMaxQuantity);
LCDSetCursorPosition(1,4);
lcd.print("press B to cancel");
drug=0;
Numpuffcounter=1;
delay(300);
ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
    delay(2000);
    goto cancelpassive;
  }
puffIntinmiliseconds=(PuffIntmin*60*1000)+(PuffIntsec*1000);


while(Numpuffcounter <= PuffMaxQuantity){   //  vaping code
  drug=1;
  LCDclear();
  LCDHome();
  lcd.print(" Passive Section ON ");
  LCDSetCursorPosition(1,2);
  lcd.print("# puff past:");
  lcd.print(Numpuffcounter);
  LCDSetCursorPosition(1,3);
  lcd.print("Total # of Puff:");
  lcd.print(PuffMaxQuantity);
  LCDSetCursorPosition(1,4);
  lcd.print("press B to cancel");
  ButtonB=digitalRead(BB);
  if (ButtonB==LOW){
      LCDclear();
      LCDHome();
      lcd.print("Experiment Cancel");
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
    delay(2000);
    goto cancelpassive;
  }
    
  }
  
  Numpuffcounter=Numpuffcounter + 1;
  
}
cancelpassive:
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
      lcd.print(" Drug cleaning ");
      LCDSetCursorPosition(1,2);
      lcd.print("Past minutes: ");
      lcd.print(fiveminprintcounter);
      LCDSetCursorPosition(1,3);
      lcd.print("press B to cancel");
      
      
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
      lcd.print("Drug Cleaning Ended");
      LCDSetCursorPosition(1,2);
      lcd.print("Press C to Main Menu");
      ButtonC = digitalRead(BC);
  while(ButtonC==HIGH){
    delay(150);
    ButtonC = digitalRead(BC);
    
  }
  delay(300);
  drug=0;
}
