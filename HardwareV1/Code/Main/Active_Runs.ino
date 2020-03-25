void FixedRatioStart(){
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print("Fixed Ratio Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print("TO CANCEL HOLD B");
  

  // insert here rct date
  Serial.println("Schedule: Fixed Ratio");
  
  if(LED1status==1){
  Serial.println("Cue Light1(LED1): Y");
   }
 else {
  Serial.println("Cue Light1(LED1): N");
   }
 
 if(LED2status==1){
  Serial.println("Cue Light2(LED2): Y");
   }
 else {
  Serial.println("Cue Light2(LED2): N");
   }
   
   
 if(primingpuff==1){
  Serial.println((String)"Priming puff: Y");
  Serial.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  Serial.println("Priming puff: N");
   }
  Serial.println((String)"Max # Puff: "+ PuffMaxQuantity);
  Serial.println((String)"Active vaporizer: "+whichvapeactive);
  

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: Fixed Ratio "+fixedresponseratio);
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");
 
SpinNottriggercheck = fixedresponseratio;
Serial.println((String) millis()+", B");
 PrimingExecution();
Serial.println((String) millis()+", T");
   
 
previoustime = millis();
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
  
    checkWheelschange();
    
    if(W1Turn>= fixedresponseratio){
     W1Turn=0;
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      R1=1;
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        Serial.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= fixedresponseratio){
      W2Turn=0;
      digitalWrite(vape2,HIGH);
      Serial.println((String) millis()+", P"+", 2");
      R2=1;
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        Serial.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      Serial.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 Serial.println((String) millis()+", E");
 
 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Fixed Ratio Seccion");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   Serial.println("THIS SECCION WAS CANCELLED");
   delay(3000);
  }
  
}



void ArithmeticRatioStart(){
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print(" Arithmetic Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+ArithmeticConstant+" W2="+ArithmeticConstant);
  
  
  // insert here rct date
  Serial.println("Schedule: Arithmetic Ratio");
  
  if(LED1status==1){
  Serial.println("Cue Light1(LED1): Y");
 }
 else {
  Serial.println("Cue Light1(LED1): N");
 }
 
 if(LED2status==1){
  Serial.println("Cue Light2(LED2): Y");
 }
 else {
  Serial.println("Cue Light2(LED2): N");
 }

  
 if(primingpuff==1){
  Serial.println((String)"Priming puff: Y");
  Serial.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  Serial.println("Priming puff: N");
   }
  Serial.println((String)"Max # Puff: "+ PuffMaxQuantity);
  Serial.println((String)"Active vaporizer: "+whichvapeactive);
  

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: Arithmetic Constant: "+ArithmeticConstant);
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);
 
 if (ifSessionTimeOut==1){
 Serial.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
   }
 else {
  Serial.println("Session Time-Out(m:s): OFF");
  }
  
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");

Serial.println((String) millis()+", B");
 PrimingExecution();
Serial.println((String) millis()+", T");
 
previoustime = millis();
previousSeccionTimeout= millis();
ArithmeticConstantSum1=ArithmeticConstant;
ArithmeticConstantSum2=ArithmeticConstant;
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSeccionTimeout <=SessionTimeOutmilis && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
      
    checkWheelschange();
    
    if(W1Turn>= ArithmeticConstantSum1){
     W1Turn=0;
     previousSeccionTimeout = millis();
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      R1=1;
      ArithmeticConstantSum1=ArithmeticConstantSum1 + ArithmeticConstant;
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+ArithmeticConstantSum1+" W2="+ArithmeticConstantSum2);
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        Serial.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= ArithmeticConstantSum2){
      W2Turn=0;
      previousSeccionTimeout = millis();
      digitalWrite(vape2,HIGH);
      Serial.println((String) millis()+", P"+", 2");
      R2=1;
      ArithmeticConstantSum2=ArithmeticConstantSum2 + ArithmeticConstant;
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+ArithmeticConstantSum1+" W2="+ArithmeticConstantSum2);
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        Serial.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      Serial.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 Serial.println((String) millis()+", E");

 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Arithmetic Seccion");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   Serial.println("THIS SECCION WAS CANCELLED");
   delay(3000);
  }
  
}




void GeometricRatioStart(){
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print(" Geometric Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+WG1+" W2="+WG2);

  // insert here rct date
  Serial.println("Schedule: Geometric Ratio");
  
  if(LED1status==1){
  Serial.println("Cue Light1(LED1): Y");
 }
 else {
  Serial.println("Cue Light1(LED1): N");
 }
 
 if(LED2status==1){
  Serial.println("Cue Light2(LED2): Y");
 }
 else {
  Serial.println("Cue Light2(LED2): N");
 }

  
 if(primingpuff==1){
  Serial.println((String)"Priming puff: Y");
  Serial.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  Serial.println("Priming puff: N");
   }
  Serial.println((String)"Max # Puff: "+ PuffMaxQuantity);
  Serial.println((String)"Active vaporizer: "+whichvapeactive);
  

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: #wheelturn=[5*e^(R*0.2)]-5 , Where R=# of Reinforcers");
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);

 if (ifSessionTimeOut==1){
 Serial.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
   }
 else {
  Serial.println("Session Time-Out(m:s): OFF");
  }
  
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");
 
Serial.println((String) millis()+", B");
 PrimingExecution();
Serial.println((String) millis()+", T");
 
previoustime = millis();
previousSeccionTimeout= millis();
RG1=1;
RG2=1;
WG1=1;
WG2=1;
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSeccionTimeout <= SessionTimeOutmilis && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
  

    
    checkWheelschange();
    
    if(W1Turn>= WG1){
     W1Turn=0;
     previousSeccionTimeout = millis();
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      R1 = 1;
      RG1 = RG1 + 1;
      WG1 = round((5*exp(RG1*0.2)) - 5);
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+WG1+" W2="+WG2);
      
      
      
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        Serial.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= WG2){
      W2Turn=0;
      previousSeccionTimeout = millis();
      digitalWrite(vape2,HIGH);
      Serial.println((String) millis()+", P"+", 2");
      R2=1;
      RG2=RG2 + 1;
      WG2 = round((5*exp(RG2*0.2)) - 5);
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+WG1+" W2="+WG2);
     
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        Serial.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      Serial.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 Serial.println((String) millis()+", E");

 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Geometric Seccion");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   Serial.println("THIS SECCION WAS CANCELLED");
   delay(3000);
  }
 
}


void PostResponseTimeOutExecution(){  //post Response time out need to be a counter because is neccesary to record the wheel spins
  Serial.println((String) millis()+", xt");
  
  
   LCDSetCursorPosition(1,3);
   lcd.print("                ");
   LCDSetCursorPosition(1,3);
   milisleft = SessionLengthInMiliseconds - millis() + previoustime;
   minutesleft=(float)milisleft/60000.0;
   lcd.print(minutesleft);
   
   
   
  previoustime2 = millis();
  while(millis() - previoustime2 <= Postresponsetimeoutmilis){
    checkWheelschange();
    
    W1Turn=0;
    W2Turn=0;

    
  }
    Serial.println((String) millis()+", T");
  
  
   if(L1==1){
        digitalWrite(LED1,LOW);
        Serial.println((String) millis()+", xs"+", 1");
        L1=0;
      }
  
   if(L2==1){
        digitalWrite(LED2,LOW);
        Serial.println((String) millis()+", xs"+", 2");
        L2=0;
      }
}


void PrimingExecution(){
 
  if(primingpuff==1){
    drug=1;
      digitalWrite(vapepriming,HIGH);
      Serial.println((String) millis()+", P"+", "+whichvapepriming);
      digitalWrite(LEDpriming,LEDstatuspriming);
      if(LEDstatuspriming==1){
        Serial.println((String) millis()+", S"+", "+whichvapepriming);
      }
      delay(Puffmiliseconds);
      digitalWrite(vapepriming,LOW);
      digitalWrite(LEDpriming,LOW);
      Serial.println((String) millis()+", xp"+", "+whichvapepriming);
      Serial.println((String) millis()+", xs"+", "+whichvapepriming);
  }

}
