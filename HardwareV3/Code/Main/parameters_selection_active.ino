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

 if (primingpuff==1){
    Whichvapepriming();
  }
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
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(ON), B(OFF)");
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
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(ON), B(OFF)");
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
      lcd.print("PRESS: A(ON), B(OFF)");
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
      lcd.print("PRESS: A(ON), B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
   }
     ButtonC = digitalRead(BC);
  }

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
    lcd.print("PRESS: A(ON), B(OFF)");
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
      lcd.print("PRESS: A(ON), B(OFF)");
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
      lcd.print("PRESS: A(ON), B(OFF)");
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
      lcd.print("PRESS: A(ON), B(OFF)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
   }
     ButtonC = digitalRead(BC);
  }


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
SessionLengthInMiliseconds = (SessionLengthMinutes*60000) + (SessionLengthHours*3600000);
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
  delay(100);
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
  delay(200);

  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) { // select session time out 

    ButtonC = digitalRead(BC);
    if ( ButtonC == LOW) {
      goto Here;
    }

    checkbuttonDstate();
    while (ButtonDstate == LOW) { // selecting session time out minutes
      delay(100);
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
  delay(100);
}


void ArithmeticMultiplier(){ 
  
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

void Whichvapepriming(){
  delay(200);
    LCDclear();            
    LCDHome();
    lcd.print("Which Vape priming?");
    LCDSetCursorPosition(2,2);
    lcd.print((String)"Vaporizer:"+ whichvapepriming);
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS D For 1 or 2");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");

    //ButtonC = digitalRead(BC);
  while ( digitalRead(BC) == HIGH){
    delay(200);
  // ButtonD = digitalRead(BD);
  
  if (digitalRead(BD) == LOW) {
    //delay(200);
    ButtonDstate = !ButtonDstate; //state start in 0
    if (ButtonDstate == LOW) {
      whichvapepriming=1;
      vapepriming=vape1;
      vapeprimingmirror=vape1mirror;
      LEDpriming=LED1;
      LEDstatuspriming=LED1status;
      LCDclear();            
      LCDHome();
      lcd.print("Which Vape priming? LOW");
  //    lcd.print("Which VLOW priming?");
      LCDSetCursorPosition(2,2);
      lcd.print((String)"Vaporizer:"+ whichvapepriming);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS D For 1 or 2");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
      }

    if (ButtonDstate == HIGH) {
      whichvapepriming=2;
      vapepriming=vape2;
      vapeprimingmirror=vape2mirror;
      LEDpriming=LED2;
      LEDstatuspriming=LED2status;
      LCDclear();            
      LCDHome();
      lcd.print("Which Vape priming?");
  //  lcd.print("Which VHIGH priming?");
      LCDSetCursorPosition(2,2);
      lcd.print((String)"Vaporizer:"+ whichvapepriming);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS D For 1 or 2");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
      }
      
    }    
  }
}

void whichvapeActive(){
    delay(200);
    LCDclear();            
    LCDHome();
    lcd.print("Which Vape Active?");
    LCDSetCursorPosition(2,2);
    lcd.print((String)"Vaporizer:"+ whichvapeactive);
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS D For 1 or 2");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
    
   
  while ( digitalRead(BC)==HIGH){ 
    delay(200);
   
  if (digitalRead(BD) == LOW) {
    //delay(200);
    ButtonDstate = !ButtonDstate; // D state start in 0
    if (ButtonDstate == LOW) {
      whichvapeactive=1;
      LCDclear();            
      LCDHome();
      lcd.print("Which Vape Active?");
      LCDSetCursorPosition(2,2);
      lcd.print((String)"Vaporizer:"+ whichvapeactive);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS D For 1 or 2");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
      }

    if (ButtonDstate == HIGH) {
      whichvapeactive=2;
      LCDclear();            
      LCDHome();
      lcd.print("Which Vape Active?");
      LCDSetCursorPosition(2,2);
      lcd.print((String)"Vaporizer:"+ whichvapeactive);
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS D For 1 or 2");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
      }
      
    }    
  }
  
}

void IFSessionTimeOut(){
  delay(200);
  if (ifSessionTimeOut==1){
    LCDclear();            
    LCDHome();
    lcd.print("Session Time Out?");
    LCDSetCursorPosition(2,2);
    lcd.print("YES");
    ifSessionTimeOut=1;
    LCDSetCursorPosition(1,3);
    lcd.print("PRESS: A(Y) , B(N)");
    LCDSetCursorPosition(1,4);
    lcd.print("PRESS C for OK");
   }
  if (ifSessionTimeOut==0){
      LCDclear();            
      LCDHome();
      lcd.print("Session Time Out?");
      LCDSetCursorPosition(2,2);
      lcd.print("NO");
      ifSessionTimeOut=0;
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
      lcd.print("Session Time Out?");
      LCDSetCursorPosition(2,2);
      lcd.print("YES");
      ifSessionTimeOut=1;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(Y) , B(N)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
      }
    if ( ButtonB == LOW){
      LCDclear();            
      LCDHome();
      lcd.print("Session Time Out?");
      LCDSetCursorPosition(2,2);
      lcd.print("NO");
      ifSessionTimeOut=0;
      LCDSetCursorPosition(1,3);
      lcd.print("PRESS: A(Y) , B(N)");
      LCDSetCursorPosition(1,4);
      lcd.print("PRESS C for OK");
    
     }
     ButtonC = digitalRead(BC);
  }

 if (ifSessionTimeOut==1){
    SessionTimeOut();
    }
    
   else{
    SessionTimeOutmilis=SessionLengthInMiliseconds + 15000;
     }
}
