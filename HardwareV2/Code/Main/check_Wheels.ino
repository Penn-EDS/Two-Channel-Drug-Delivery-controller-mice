//* To be used in Active mode **//

void checkWheelschange() {

//  Wheel One ---------------------------------------

if ((Wheel1State=digitalRead(W1))!= lastWheel1State){
  W1Step= W1Step+1;
  
 wheel1stopcountertimemilis=0;
  lastWheel1State = Wheel1State;
}

if ((Wheel1State=digitalRead(W1)) == lastWheel1State){
      
      wheel1stopcountertimemilis=wheel1stopcountertimemilis+1;
      if(wheel1stopcountertimemilis >=XrCycles && R1==1){
        wheel1stopcountertimemilis=0;
        myFile.println((String) millis()+", xr"+", 1");
        R1=0;
      }
    }

 if (W1Step==Step){
    W1Step=0;
    W1Turn=W1Turn +1;
   if(W1Turn != SpinNottriggercheck || W1Turn==1 && SpinNottriggercheck==1){
    myFile.println((String) millis()+", R"+", 1");
    R1=1;

    }
    
   
  }

  
// Wheel 2------------------------------------------


  if ((Wheel2State=digitalRead(W2))!= lastWheel2State){
  W2Step= W2Step+1;
  
 wheel2stopcountertimemilis=0;
  lastWheel2State = Wheel2State;
}

if ((Wheel2State=digitalRead(W2)) == lastWheel2State){
      
      wheel2stopcountertimemilis=wheel2stopcountertimemilis+1;
      if(wheel2stopcountertimemilis >=XrCycles && R2==1){
        wheel2stopcountertimemilis=0;
        myFile.println((String) millis()+", xr"+", 2");
        R2=0;
      }
    }

if (W2Step==Step){
    W2Step=0;
    W2Turn=W2Turn +1;
   if(W2Turn != SpinNottriggercheck || W2Turn==1 && SpinNottriggercheck==1){
     myFile.println((String) millis()+", R"+", 2");
     R2=1;
    }
 
  }

}
