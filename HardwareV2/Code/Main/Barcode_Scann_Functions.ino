void UserName(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
 userN:
    LCDclear();
    LCDHome();
    lcd.print("Scan User:");
    LCDSetCursorPosition(1,2);
    lcd.print((String)" "+username);
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


void AnimalNameActive(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animalN:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal: "+animalnameactive);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnameactive = "";
          animalnameactive=barcodeword;
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
    lcd.print("Scan Drug");
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


//------ passive animals-----

void AnimalNamePasssive1(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal1N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #1");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #1: "+animalnamepassive1);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive1 = "";
          animalnamepassive1=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal1N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}


void AnimalNamePasssive2(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal2N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #2");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #2: "+animalnamepassive2);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive2 = "";
          animalnamepassive2=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal2N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}


void AnimalNamePasssive3(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal3N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #3");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #3: "+animalnamepassive3);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive3 = "";
          animalnamepassive3=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal3N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}

void AnimalNamePasssive4(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal4N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #4");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #4: "+animalnamepassive4);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive4 = "";
          animalnamepassive4=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal4N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}

void AnimalNamePasssive5(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal5N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #5");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #5: "+animalnamepassive5);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive5 = "";
          animalnamepassive5=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal5N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}

void AnimalNamePasssive6(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal6N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #6");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #6: "+animalnamepassive6);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive6 = "";
          animalnamepassive6=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal6N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}

void AnimalNamePasssive7(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal7N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #7");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #7: "+animalnamepassive7);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive7 = "";
          animalnamepassive7=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal7N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}

void AnimalNamePasssive8(){
  delay(200);
  digitalWrite(SDcs,HIGH);
  digitalWrite(USBcs,LOW);
  animal8N:
    LCDclear();
    LCDHome();
    lcd.print("Scan Animal #8");
    LCDSetCursorPosition(1,2);
    lcd.print((String)"Animal #8: "+animalnamepassive8);
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    while(digitalRead(BC)==HIGH){
       Usb.Task();
       if(readed==1){
          animalnamepassive8 = "";
          animalnamepassive8=barcodeword;
          barcodeword = "";
          readed =0;
          goto animal8N;
        }
        
     }
 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
}
