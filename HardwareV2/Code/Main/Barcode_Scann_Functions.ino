void UserName(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
 userN:
    LCDclear();
    LCDHome();
    lcd.print("Scann User");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"USER: "+username);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    
    while(digitalRead(BC)==HIGH){
      
         Usb.Task();
       if(readed==1){
          username = ""; 
          username=barcodeword;
          barcodeword = "";
          readed =0;
          goto userN;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}


void AnimalName(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animalN:
    LCDclear();
    LCDHome();
    lcd.print("Scann Animal");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal: "+animalname);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalname = "";
          animalname=barcodeword;
          barcodeword = "";
          readed =0;
          goto animalN;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}


void DrugName(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  drugN:
    LCDclear();
    LCDHome();
    lcd.print("Scann Drug");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Drug: "+drugname);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          drugname = ""; 
          drugname=barcodeword;
          barcodeword = "";
          readed =0;
          goto drugN;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}
