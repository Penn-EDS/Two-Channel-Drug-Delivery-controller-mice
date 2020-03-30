void FixedRatioStart(){
  delay(300);
  W1Turn=0;
  W2Turn=0;
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print("Fixed Ratio Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print("TO CANCEL HOLD B");
  
  CreateFile();
  RTCDateTime();
  myFile.println((String)"USER :"+username);
  myFile.println((String)"Drug: "+drugname);
  myFile.println((String)"Animal: "+animalnameactive);

  myFile.println("Schedule: Fixed Ratio");
  
  if(LED1status==1){
  myFile.println("Cue Light1(LED1): Y");
   }
 else {
  myFile.println("Cue Light1(LED1): N");
   }
 
 if(LED2status==1){
  myFile.println("Cue Light2(LED2): Y");
   }
 else {
  myFile.println("Cue Light2(LED2): N");
   }
   
   
 if(primingpuff==1){
  myFile.println((String)"Priming puff: Y");
  myFile.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  myFile.println("Priming puff: N");
   }
  myFile.println((String)"Max # Puff: "+ PuffMaxQuantity);
  myFile.println((String)"Active vaporizer: "+whichvapeactive);
  

 myFile.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 myFile.println((String)"Ratio: Fixed Ratio "+fixedresponseratio);
 myFile.println((String)"TOD(s):"+ Postresponsetimeout);
 myFile.println((String)"Vape Time(ms):"+ Puffmiliseconds);
myFile.println("----------------------------");
myFile.println("TIME(ms), Action, Unit");
 
SpinNottriggercheck = fixedresponseratio;
myFile.println((String) millis()+", B");
 PrimingExecution();
myFile.println((String) millis()+", T");
   
 
previoustime = millis();
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
  
    checkWheelschange();
    
    if(W1Turn>= fixedresponseratio){
     W1Turn=0;
      digitalWrite(vape1,HIGH);
      myFile.println((String) millis()+", P"+", 1");
      R1=1;
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        myFile.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      myFile.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= fixedresponseratio){
      W2Turn=0;
      digitalWrite(vape2,HIGH);
      myFile.println((String) millis()+", P"+", 2");
      R2=1;
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        myFile.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      myFile.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 myFile.println((String) millis()+", E");
 
 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Fixed Ratio Session");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   myFile.println("THIS Session WAS CANCELLED");
   myFile.close();
   delay(3000);
  }
  myFile.close();
}



void ArithmeticRatioStart(){
  delay(300);
  W1Turn=0;
  W2Turn=0;
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print(" Arithmetic Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+ArithmeticConstant+" W2="+ArithmeticConstant);
  
  
  CreateFile();
  RTCDateTime();
  myFile.println((String)"USER :"+username);
  myFile.println((String)"Drug: "+drugname);
  myFile.println((String)"Animal: "+animalnameactive);
  
  myFile.println("Schedule: Arithmetic Ratio");
  
  if(LED1status==1){
  myFile.println("Cue Light1(LED1): Y");
 }
 else {
  myFile.println("Cue Light1(LED1): N");
 }
 
 if(LED2status==1){
  myFile.println("Cue Light2(LED2): Y");
 }
 else {
  myFile.println("Cue Light2(LED2): N");
 }

  
 if(primingpuff==1){
  myFile.println((String)"Priming puff: Y");
  myFile.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  myFile.println("Priming puff: N");
   }
  myFile.println((String)"Max # Puff: "+ PuffMaxQuantity);
  myFile.println((String)"Active vaporizer: "+whichvapeactive);
  

 myFile.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 myFile.println((String)"Ratio: Arithmetic Constant: "+ArithmeticConstant);
 myFile.println((String)"TOD(s):"+ Postresponsetimeout);
 myFile.println((String)"Vape Time(ms):"+ Puffmiliseconds);
 
 if (ifSessionTimeOut==1){
 myFile.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
   }
 else {
  myFile.println("Session Time-Out(m:s): OFF");
  }
  
myFile.println("----------------------------");
myFile.println("TIME(ms), Action, Unit");

myFile.println((String) millis()+", B");
 PrimingExecution();
myFile.println((String) millis()+", T");
 
previoustime = millis();
previousSessionTimeout= millis();
ArithmeticConstantSum1=ArithmeticConstant;
ArithmeticConstantSum2=ArithmeticConstant;
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSessionTimeout <=SessionTimeOutmilis && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
      
    checkWheelschange();
    
    if(W1Turn>= ArithmeticConstantSum1){
     W1Turn=0;
     previousSessionTimeout = millis();
      digitalWrite(vape1,HIGH);
      myFile.println((String) millis()+", P"+", 1");
      R1=1;
      ArithmeticConstantSum1=ArithmeticConstantSum1 + ArithmeticConstant;
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+ArithmeticConstantSum1+" W2="+ArithmeticConstantSum2);
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        myFile.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      myFile.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= ArithmeticConstantSum2){
      W2Turn=0;
      previousSessionTimeout = millis();
      digitalWrite(vape2,HIGH);
      myFile.println((String) millis()+", P"+", 2");
      R2=1;
      ArithmeticConstantSum2=ArithmeticConstantSum2 + ArithmeticConstant;
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+ArithmeticConstantSum1+" W2="+ArithmeticConstantSum2);
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        myFile.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      myFile.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 myFile.println((String) millis()+", E");

 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Arithmetic Session");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   myFile.println("THIS Session WAS CANCELLED");
   myFile.close();
   delay(3000);
  }
  myFile.close();
}




void GeometricRatioStart(){
  delay(300);
  W1Turn=0;
  W2Turn=0;
  WG1=1;
  WG2=1;
  RG1=1;
  RG2=1;
  drug=0;
  Numpuffcounter=1;
  LCDclear();
  LCDHome();
  lcd.print(" Geometric Running");
  LCDSetCursorPosition(1,2);
  lcd.print("Minutes Left:");
  LCDSetCursorPosition(1,4);
  lcd.print((String)"W1="+WG1+" W2="+WG2);

  CreateFile();
  RTCDateTime();
  myFile.println((String)"USER :"+username);
  myFile.println((String)"Drug: "+drugname);
  myFile.println((String)"Animal: "+animalnameactive);
  
  myFile.println("Schedule: Geometric Ratio");
  
  if(LED1status==1){
  myFile.println("Cue Light1(LED1): Y");
 }
 else {
  myFile.println("Cue Light1(LED1): N");
 }
 
 if(LED2status==1){
  myFile.println("Cue Light2(LED2): Y");
 }
 else {
  myFile.println("Cue Light2(LED2): N");
 }

  
 if(primingpuff==1){
  myFile.println((String)"Priming puff: Y");
  myFile.println((String)"priming Vaporizer: "+whichvapepriming);
   }
 else {
  myFile.println("Priming puff: N");
   }
  myFile.println((String)"Max # Puff: "+ PuffMaxQuantity);
  myFile.println((String)"Active vaporizer: "+whichvapeactive);
  

 myFile.println((String)"Session Duration(h:m): "+SessionLengthHours+":"+SessionLengthMinutes);
 myFile.println((String)"Ratio: #wheelturn=[5*e^(R*0.2)]-5 , Where R=# of Reinforcers");
 myFile.println((String)"TOD(s):"+ Postresponsetimeout);
 myFile.println((String)"Vape Time(ms):"+ Puffmiliseconds);

 if (ifSessionTimeOut==1){
 myFile.println((String)"Session Time-Out(m:s):"+SessionTimeOutmin+":"+SessionTimeOutsec);
   }
 else {
  myFile.println("Session Time-Out(m:s): OFF");
  }
  
myFile.println("----------------------------");
myFile.println("TIME(ms), Action, Unit");
 
myFile.println((String) millis()+", B");
 PrimingExecution();
myFile.println((String) millis()+", T");
 
previoustime = millis();
previousSessionTimeout= millis();
drug=1;
 while(millis() - previoustime <= SessionLengthInMiliseconds && millis() - previousSessionTimeout <= SessionTimeOutmilis && Numpuffcounter <= PuffMaxQuantity && digitalRead(BB)==HIGH){  //currenttime-previoustime <= SessionLengthInMiliseconds
  

    
    checkWheelschange();
    
    if(W1Turn>= WG1){
     W1Turn=0;
     previousSessionTimeout = millis();
      digitalWrite(vape1,HIGH);
      myFile.println((String) millis()+", P"+", 1");
      R1 = 1;
      RG1 = RG1 + 1;
      WG1 = round((5*exp(RG1*0.2)) - 5);
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+WG1+" W2="+WG2);
      
      
      
      
      if(LED1status==1){
        digitalWrite(LED1,HIGH);
        myFile.println((String) millis()+", S"+", 1");
        L1=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape1,LOW);
      myFile.println((String) millis()+", xp"+", 1");
      PostResponseTimeOutExecution();  //post Response time out need to be a counter because is neccesary to record the wheel spins 
      Numpuffcounter=Numpuffcounter + 1;
     }


    if(W2Turn>= WG2){
      W2Turn=0;
      previousSessionTimeout = millis();
      digitalWrite(vape2,HIGH);
      myFile.println((String) millis()+", P"+", 2");
      R2=1;
      RG2=RG2 + 1;
      WG2 = round((5*exp(RG2*0.2)) - 5);
      LCDSetCursorPosition(1,4);
      lcd.print("                   ");
      LCDSetCursorPosition(1,4);
      lcd.print((String)"W1="+WG1+" W2="+WG2);
     
      
      if(LED2status==1){
        digitalWrite(LED2,HIGH);
        myFile.println((String) millis()+", S"+", 2");
        L2=1;
      }
      delay(Puffmiliseconds);
      digitalWrite(vape2,LOW);
      myFile.println((String) millis()+", xp"+", 2"); 
      PostResponseTimeOutExecution();
      Numpuffcounter=Numpuffcounter + 1;
    }
  

  }
 myFile.println((String) millis()+", E");

 if(digitalRead(BB)==LOW){
   LCDclear();
   LCDHome();
   lcd.print("Geometric Session");
   LCDSetCursorPosition(1,2);
   lcd.print("     CANCELLED     ");
   myFile.println("THIS Session WAS CANCELLED");
   myFile.close();
   delay(3000);
  }
 myFile.close();
}


void PostResponseTimeOutExecution(){  //post Response time out need to be a counter because is neccesary to record the wheel spins
  myFile.println((String) millis()+", xt");
  
  
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
    myFile.println((String) millis()+", T");
  
  
   if(L1==1){
        digitalWrite(LED1,LOW);
        myFile.println((String) millis()+", xs"+", 1");
        L1=0;
      }
  
   if(L2==1){
        digitalWrite(LED2,LOW);
        myFile.println((String) millis()+", xs"+", 2");
        L2=0;
      }
}


void PrimingExecution(){
 
  if(primingpuff==1){
    drug=1;
      digitalWrite(vapepriming,HIGH);
      myFile.println((String) millis()+", P"+", "+whichvapepriming);
      digitalWrite(LEDpriming,LEDstatuspriming);
      if(LEDstatuspriming==1){
        myFile.println((String) millis()+", S"+", "+whichvapepriming);
      }
      delay(Puffmiliseconds);
      digitalWrite(vapepriming,LOW);
      digitalWrite(LEDpriming,LOW);
      myFile.println((String) millis()+", xp"+", "+whichvapepriming);
      myFile.println((String) millis()+", xs"+", "+whichvapepriming);
  }

}
