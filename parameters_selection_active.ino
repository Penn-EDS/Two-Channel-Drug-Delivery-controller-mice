void Primingpuff(){
  delay(200);
  if (primingpuff==1){
    LCDclear();            
    LCDHome();
    lcd.print("Priming Puff?");
    LCDSetCursorPosition(2,2);
    lcd.print("YES");
    primingpuff=1;
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(Y) , B(N)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   }
  if (primingpuff==0){
      LCDclear();            
      LCDHome();
      lcd.print("Priming Puff?");
      LCDSetCursorPosition(2,2);
      lcd.print("NO");
      primingpuff=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(Y) , B(N)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
  }
    
   ButtonC = digitalRead(BC);
  while ( ButtonC==HIGH){ 
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Priming Puff?");
      LCDSetCursorPosition(2,2);
      lcd.print("YES");
      primingpuff=1;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(Y) , B(N)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Priming Puff?");
      LCDSetCursorPosition(2,2);
      lcd.print("NO");
      primingpuff=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(Y) , B(N)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
   }
     ButtonC = digitalRead(BC);
  }
// if(primingpuff==1){
//  Serial.println("Priming puff: Y");
// }
// else {
//  Serial.println("Priming puff: N");
// }
}


void PostResponseTimeOut(){
    LCDclear();            
    LCDHome();
    lcd.print("Select PRTO Length");
    LCDSetCursorPosition(2,2);
    lcd.print("Seconds:");
    lcd.print(Postresponsetimeout);
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(+) , B(-)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   ButtonC = digitalRead(BC);
  while ( ButtonC==HIGH){ 
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW){
      Postresponsetimeout=Postresponsetimeout+1;
      LCDclear();            
      LCDHome();
      lcd.print("Select PRTO Length");
      LCDSetCursorPosition(2,2);
      lcd.print("Seconds:");
      lcd.print(Postresponsetimeout);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW){
     Postresponsetimeout=Postresponsetimeout-1;
     LCDclear();            
     LCDHome();
     lcd.print("Select PRTO Length");
     LCDSetCursorPosition(2,2);
     lcd.print("Seconds:");
     lcd.print(Postresponsetimeout);
     LCDSetCursorPosition(1,3);
     lcd.print("PRESS: A(+) , B(-)");
     LCDSetCursorPosition(1,4);
     lcd.print("PRESS C for OK");
    if (Postresponsetimeout <= 0){
       Postresponsetimeout=0;
       LCDclear();            
       LCDHome();
       lcd.print("Select PRTO Length");
       LCDSetCursorPosition(2,2);
       lcd.print("Seconds:");
       lcd.print(Postresponsetimeout);
       LCDSetCursorPosition(1,3);
       lcd.print("PRESS: A(+) , B(-)");
       LCDSetCursorPosition(1,4);
       lcd.print("PRESS C for OK");
    }
   }
     ButtonC = digitalRead(BC);
  }
  
  Postresponsetimeoutmilis = Postresponsetimeout*1000;
  //Serial.println((String)"TOD(s):"+ Postresponsetimeout);
}


void CueLight(){

   //LED1
  if (LED1status==1){ 
    LCDclear();            
    LCDHome();
    lcd.print("Select Cuelight LED1");
    LCDSetCursorPosition(2,2);
    lcd.print(" LED1:");
    lcd.print("ON");
    LED1status=1;
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(ON) , B(OFF)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   }
  if (LED1status==0){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED1");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED1:");
      lcd.print("OFF");
      LED1status=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
  }
    
   ButtonC = digitalRead(BC);
  while ( ButtonC==HIGH){ 
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED1");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED1:");
      lcd.print("ON");
      LED1status=1;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED1");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED1:");
      lcd.print("OFF");
      LED1status=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
   }
     ButtonC = digitalRead(BC);
  }
//  if(LED1status==1){
//  Serial.println("Cue Light1(LED1): Y");
// }
// else {
//  Serial.println("Cue Light1(LED1): N");
// }
delay(300);

 //LED2
  if (LED2status==1){ 
    LCDclear();            
    LCDHome();
    lcd.print("Select Cuelight LED2");
    LCDSetCursorPosition(2,2);
    lcd.print(" LED2:");
    lcd.print("ON");
    LED2status=1;
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(ON) , B(OFF)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   }
  if (LED2status==0){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED2");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED2:");
      lcd.print("OFF");
      LED2status=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
  }
    
   ButtonC = digitalRead(BC);
  while ( ButtonC==HIGH){ 
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED2");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED2:");
      lcd.print("ON");
      LED2status=1;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Select Cuelight LED2");
      LCDSetCursorPosition(2,2);
      lcd.print(" LED2:");
      lcd.print("OFF");
      LED2status=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON) , B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
   }
     ButtonC = digitalRead(BC);
  }
//if(LED2status==1){
//  Serial.println("Cue Light2(LED2): Y");
// }
// else {
//  Serial.println("Cue Light2(LED2): N");
// }

}

void sessionLength(){
  
  LCDclear();
  LCDHome();
  lcd.print("  Session Length");
  LCDSetCursorPosition(1, 2);
  lcd.print(" Hrs:");
  LCDSetCursorPosition(6, 2);
  lcd.print(SessionLengthHours);
  LCDSetCursorPosition(15, 2);
  lcd.print("Min:");
  LCDSetCursorPosition(19, 2);
  lcd.print(SessionLengthMinutes);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("D(Hrs or Min) C(OK)");

  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) {   // select Active session Length time loop

    ButtonC = digitalRead(BC);
    if ( ButtonC == LOW) {
      goto Here;
    }

    checkbuttonDstate();
    while (ButtonDstate == LOW) {  // selecting session length hours
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
        SessionLengthHours = SessionLengthHours + 1;
        LCDclear();
        LCDHome();
        lcd.print("  Session Length");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Hrs:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionLengthHours);
        LCDSetCursorPosition(15, 2);
        lcd.print("Min:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionLengthMinutes);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Hrs or Min) C(OK)");
        LCDSetCursorPosition(1, 2);
        // putt a maximum value here hours
        if ( SessionLengthHours >= 24) {
          SessionLengthHours = 24;
          LCDclear();
          LCDHome();
          lcd.print("  Session Length");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Hrs:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionLengthHours);
          LCDSetCursorPosition(15, 2);
          lcd.print("Min:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionLengthMinutes);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Hrs or Min) C(OK)");
          LCDSetCursorPosition(1, 2);
        }
      }
      checkbuttonDstate();
      if ( ButtonB == LOW) {
        SessionLengthHours = SessionLengthHours - 1;
        LCDclear();
        LCDHome();
        lcd.print("  Session Length");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Hrs:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionLengthHours);
        LCDSetCursorPosition(15, 2);
        lcd.print("Min:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionLengthMinutes);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Hrs or Min) C(OK)");
        LCDSetCursorPosition(1, 2);
        
        if (SessionLengthHours == 4294967295) {
          SessionLengthHours = 0;
          LCDclear();
          LCDHome();
          lcd.print("  Session Length");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Hrs:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionLengthHours);
          LCDSetCursorPosition(15, 2);
          lcd.print("Min:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionLengthMinutes);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Hrs or Min) C(OK)");
          LCDSetCursorPosition(1, 2);
        }
      }
      checkbuttonDstate();

      ButtonC = digitalRead(BC);
      if ( ButtonC == LOW) {
        goto Here;
      }
    }
    checkbuttonDstate();
    while (ButtonDstate == HIGH) { // selecting session Length Minutes
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
        SessionLengthMinutes = SessionLengthMinutes + 1;
        LCDclear();
        LCDHome();
        lcd.print("  Session Length");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Hrs:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionLengthHours);
        LCDSetCursorPosition(15, 2);
        lcd.print("Min:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionLengthMinutes);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Hrs or Min) C(OK)");
        LCDSetCursorPosition(14, 2);

        if ( SessionLengthMinutes >= 60) {
          SessionLengthMinutes = 60;
          LCDclear();
          LCDHome();
          lcd.print("  Session Length");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Hrs:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionLengthHours);
          LCDSetCursorPosition(15, 2);
          lcd.print("Min:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionLengthMinutes);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Hrs or Min) C(OK)");
          LCDSetCursorPosition(14, 2);
        }
      }
      
      checkbuttonDstate();
      if ( ButtonB == LOW) {

        SessionLengthMinutes = SessionLengthMinutes - 1;
        LCDclear();
        LCDHome();
        lcd.print("  Session Length");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Hrs:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionLengthHours);
        LCDSetCursorPosition(15, 2);
        lcd.print("Min:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionLengthMinutes);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Hrs or Min) C(OK)");
        LCDSetCursorPosition(14, 2);
        
        if ( SessionLengthMinutes == 4294967295) {
          SessionLengthMinutes = 0;
          LCDclear();
          LCDHome();
          lcd.print("  Session Length");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Hrs:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionLengthHours);
          LCDSetCursorPosition(15, 2);
          lcd.print("Min:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionLengthMinutes);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Hrs or Min) C(OK)");
          LCDSetCursorPosition(14, 2);
        }
      }
      checkbuttonDstate();

      ButtonC = digitalRead(BC);
      if ( ButtonC == LOW) {
        goto Here;
      }
    }
  }
Here:
  //Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
  delay(100);
}



void FixedResponseRatio(){
  LCDclear();
  LCDHome();
  lcd.print("Fixed Response Ratio");
  LCDSetCursorPosition(1, 2);
  lcd.print("Quantity: ");
  lcd.print(fixedresponseratio);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) , B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("PRESS C for OK");
  
  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) {
    delay(100);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW) {
      fixedresponseratio = fixedresponseratio + 1;
      LCDclear();
      LCDHome();
      lcd.print("Fixed Response Ratio");
      LCDSetCursorPosition(1, 2);
      lcd.print("Quantity: ");
      lcd.print(fixedresponseratio);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");
      
    }
    
    if ( ButtonB == LOW) {
      fixedresponseratio = fixedresponseratio - 1;
      LCDclear();
      LCDHome();
      lcd.print("Fixed Response Ratio");
      LCDSetCursorPosition(1, 2);
      lcd.print("Quantity: ");
      lcd.print(fixedresponseratio);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");

    }
    ButtonC = digitalRead(BC);
  }
  //Serial.println((String)"Ratio: Fixed Ratio "+fixedresponseratio);
}



void SessionTimeOut(){
  LCDclear();
  LCDHome();
  lcd.print("Session Time Out");
  LCDSetCursorPosition(1, 2);
  lcd.print(" Min:");
  LCDSetCursorPosition(6, 2);
  lcd.print(SessionTimeOutmin);
  LCDSetCursorPosition(15, 2);
  lcd.print("SEC:");
  LCDSetCursorPosition(19, 2);
  lcd.print(SessionTimeOutsec);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("D(Min or SEC) C(OK)");

  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) { // select session time out 

    ButtonC = digitalRead(BC);
    if ( ButtonC == LOW) {
      goto Here;
    }

    checkbuttonDstate();
    while (ButtonDstate == LOW) { // selecting session time out minutes
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
        SessionTimeOutmin = SessionTimeOutmin + 1;
        LCDclear();
        LCDHome();
        lcd.print("Session Time Out");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionTimeOutmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionTimeOutsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(1, 2);
        
        if ( SessionTimeOutmin >= 99999999) {
          SessionTimeOutmin = 99999999;
          LCDclear();
          LCDHome();
          lcd.print("Session Time Out");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionTimeOutmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionTimeOutsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
          LCDSetCursorPosition(1, 2);
        }

      }
      checkbuttonDstate();
      if ( ButtonB == LOW) {
        SessionTimeOutmin = SessionTimeOutmin - 1;
        LCDclear();
        LCDHome();
        lcd.print("Session Time Out");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionTimeOutmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionTimeOutsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(1, 2);
        if ( SessionTimeOutmin == 4294967295) {
          SessionTimeOutmin = 0;
          LCDclear();
          LCDHome();
          lcd.print("Session Time Out");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionTimeOutmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionTimeOutsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
          LCDSetCursorPosition(1, 2);
        }

      }
      checkbuttonDstate();

      
      if ((ButtonC = digitalRead(BC)) == LOW) {
        goto Here;
      }
    }
    checkbuttonDstate();
    while (ButtonDstate == HIGH) { 
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
       SessionTimeOutsec = SessionTimeOutsec + 1;
        LCDclear();
        LCDHome();
        lcd.print("Session Time Out");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionTimeOutmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionTimeOutsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(14, 2);

        if ( SessionTimeOutsec >= 60) {
          SessionTimeOutsec = 60;
          LCDclear();
          LCDHome();
          lcd.print("Session Time Out");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionTimeOutmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionTimeOutsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
          LCDSetCursorPosition(14, 2);
        }
      }
      checkbuttonDstate();
      if ( ButtonB == LOW) {

        SessionTimeOutsec = SessionTimeOutsec - 1;
        LCDclear();
        LCDHome();
        lcd.print("Session Time Out");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(SessionTimeOutmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(SessionTimeOutsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(14, 2);
        
        if ( SessionTimeOutsec == 4294967295) {
          SessionTimeOutsec = 0;
          LCDclear();
          LCDHome();
          lcd.print("Session Time Out");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(SessionTimeOutmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(SessionTimeOutsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
          LCDSetCursorPosition(14, 2);
        }
      }
      checkbuttonDstate();

      ButtonC = digitalRead(BC);
      if ( ButtonC == LOW) {
        goto Here;
      }
    }
  }
Here:

SessionTimeOutmilis = (SessionTimeOutmin*60000) + (SessionTimeOutsec*1000);
  delay(1);
}


void ArithmeticMultiplier(){ /////
  
    LCDclear();            
    LCDHome();
    lcd.print("Arithmetic Constant");
    LCDSetCursorPosition(2,2);
    lcd.print("Constant:");
    lcd.print(ArithmeticConstant);
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(+) , B(-)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   ButtonC = digitalRead(BC);
  while ( ButtonC==HIGH){ 
    delay(100);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW){
      ArithmeticConstant=ArithmeticConstant+1;
      LCDclear();            
      LCDHome();
      lcd.print("Arithmetic Constant");
      LCDSetCursorPosition(2,2);
      lcd.print("Constant:");
      lcd.print(ArithmeticConstant);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW){
     ArithmeticConstant=ArithmeticConstant-1;
     LCDclear();            
     LCDHome();
     lcd.print("Arithmetic Constant");
     LCDSetCursorPosition(2,2);
     lcd.print("Constant:");
     lcd.print(ArithmeticConstant);
     LCDSetCursorPosition(1,3);
     lcd.print("PRESS: A(+) , B(-)");
     LCDSetCursorPosition(1,4);
     lcd.print("PRESS C for OK");
     
   }
     ButtonC = digitalRead(BC);
  }
  
}
