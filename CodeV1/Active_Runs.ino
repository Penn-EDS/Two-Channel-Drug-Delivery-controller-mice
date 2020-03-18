void FixedRatioStart(){
  LCDclear();
  LCDHome();
  lcd.print("Fixed Ratio Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  
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
  Serial.println("Priming puff: Y");
 }
 else {
  Serial.println("Priming puff: N");
 }

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: Fixed Ratio "+fixedresponseratio);
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");
 
SessionLengthInMiliseconds = (SessionLengthMinutes*60000) + (SessionLengthHours*3600000);
SpinNottriggercheck = fixedresponseratio;
Serial.println((String) millis()+", B");

 if(primingpuff==1){
  drug=1;
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      digitalWrite(LED1,LED1status);
      if(LED1status==1){
        Serial.println((String) millis()+", S"+", 1");
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      digitalWrite(LED1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
 }
   Serial.println((String) millis()+", T");
 
previoustime = millis();
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds){  //currenttime-previoustime <= SessionLengthInMiliseconds
  
//  LCDSetCursorPosition(1,3);
//  lcd.print("                ");
//  LCDSetCursorPosition(1,3);
//   milisleft = SessionLengthInMiliseconds - millis() + previoustime;
//   lcd.print(milisleft);
    
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
    }
  

  }
 Serial.println((String) millis()+", E"); 
}



void ArithmeticRatioStart(){
  
  LCDclear();
  LCDHome();
  lcd.print(" Arithmetic Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+ArithmeticConstant+" W2="+ArithmeticConstant);
  
  
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
  Serial.println("Priming puff: Y");
 }
 else {
  Serial.println("Priming puff: N");
 }

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: Arithmetic Constant: "+ArithmeticConstant);
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);
 Serial.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");
 
SessionLengthInMiliseconds = (SessionLengthMinutes*60000) + (SessionLengthHours*3600000);
//SpinNottriggercheck = fixedresponseratio;
Serial.println((String) millis()+", B");

 if(primingpuff==1){
  drug=1;
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      digitalWrite(LED1,LED1status);
      if(LED1status==1){
        Serial.println((String) millis()+", S"+", 1");
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      digitalWrite(LED1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
 }
   Serial.println((String) millis()+", T");
 
previoustime = millis();
previousSeccionTimeout= millis();
ArithmeticConstantSum1=ArithmeticConstant;
ArithmeticConstantSum2=ArithmeticConstant;
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSeccionTimeout <=SessionTimeOutmilis){  //currenttime-previoustime <= SessionLengthInMiliseconds
  
//  LCDSetCursorPosition(1,3);
//  lcd.print("                ");
//  LCDSetCursorPosition(1,3);
//   milisleft = SessionLengthInMiliseconds - millis() + previoustime;
//   lcd.print(milisleft);
    
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
    }
  

  }
 Serial.println((String) millis()+", E");
  
}




void GeometricRatioStart(){
  
  LCDclear();
  LCDHome();
  lcd.print(" Geometric Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+WG1+" W2="+WG2);
  
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
  Serial.println("Priming puff: Y");
 }
 else {
  Serial.println("Priming puff: N");
 }

 Serial.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 Serial.println((String)"Ratio: #wheelturn=[5*e^(R*0.2)]-5 , Where R=# of Reinforcers");
 Serial.println((String)"TOD(s):"+ Postresponsetimeout);
 Serial.println((String)"Vape Time(ms):"+ Puffmiliseconds);
 Serial.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
Serial.println("----------------------------");
Serial.println("TIME(ms), Action, Unit");
 
SessionLengthInMiliseconds = (SessionLengthMinutes*60000) + (SessionLengthHours*3600000);
//SpinNottriggercheck = fixedresponseratio;
Serial.println((String) millis()+", B");

 if(primingpuff==1){
  drug=1;
      digitalWrite(vape1,HIGH);
      Serial.println((String) millis()+", P"+", 1");
      digitalWrite(LED1,LED1status);
      if(LED1status==1){
        Serial.println((String) millis()+", S"+", 1");
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      digitalWrite(LED1,LOW);
      Serial.println((String) millis()+", xp"+", 1");
 }
   Serial.println((String) millis()+", T");
 
previoustime = millis();
previousSeccionTimeout= millis();
RG1=1;
RG2=1;
WG1=1;
WG2=1;
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSeccionTimeout <= SessionTimeOutmilis){  //currenttime-previoustime <= SessionLengthInMiliseconds
  
//  LCDSetCursorPosition(1,3);
//  lcd.print("                ");
//  LCDSetCursorPosition(1,3);
//   milisleft = SessionLengthInMiliseconds - millis() + previoustime;
//   lcd.print(milisleft);
    
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
    }
  

  }
 Serial.println((String) millis()+", E");
 
}


void PostResponseTimeOutExecution(){  //post Response time out need to be a counter because is neccesary to record the wheel spins
  Serial.println((String) millis()+", xt");
  //Serial.println((String) millis()+", xt"+", 1");
  //Serial.println((String) millis()+", xt"+", 2");
  
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
//    LCDSetCursorPosition(1,3);
//    lcd.print("                ");
//    LCDSetCursorPosition(1,3);
//    milisleft = SessionLengthInMiliseconds - millis() + previoustime;
//    lcd.print(milisleft);
    
  }
    Serial.println((String) millis()+", T");
  //Serial.println((String) millis()+", T"+", 1");
  //Serial.println((String) millis()+", T"+", 2");
  
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
