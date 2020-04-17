
//// select puff length loop
void PuffLengthselect() {
  LCDclear();
  LCDHome();
  lcd.print("Select Puff Length");
  LCDSetCursorPosition(2, 2);
  lcd.print("Miliseconds:");
  lcd.print(Puffmiliseconds);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) , B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("PRESS C for OK");
  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) {
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW) {
      // Puffmiliseconds = Puffmiliseconds + 1;    /** 1ms increment ***/
      Puffmiliseconds = Puffmiliseconds + 50;      /** 50ms increment requested by Jessica **/ 
      LCDclear();
      LCDHome();
      lcd.print("Select Puff Length");
      LCDSetCursorPosition(2, 2);
      lcd.print("Miliseconds:");
      lcd.print(Puffmiliseconds);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW) {
      // Puffmiliseconds = Puffmiliseconds - 1;
      Puffmiliseconds = Puffmiliseconds - 50;
      LCDclear();
      LCDHome();
      lcd.print("Select Puff Length");
      LCDSetCursorPosition(2, 2);
      lcd.print("Miliseconds:");
      lcd.print(Puffmiliseconds);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");
      if (Puffmiliseconds <= 0) {
        Puffmiliseconds = 0;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff Length");
        LCDSetCursorPosition(2, 2);
        lcd.print("Miliseconds:");
        lcd.print(Puffmiliseconds);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) , B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("PRESS C for OK");
      }
    }
    ButtonC = digitalRead(BC);
  }


}


//****select puff interval length loop
void PuffIntSelect() {
  LCDclear();
  LCDHome();
  lcd.print("Select Puff Interval");
  LCDSetCursorPosition(1, 2);
  lcd.print(" Min:");
  LCDSetCursorPosition(6, 2);
  lcd.print(PuffIntmin);
  LCDSetCursorPosition(15, 2);
  lcd.print("SEC:");
  LCDSetCursorPosition(19, 2);
  lcd.print(PuffIntsec);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("D(Min or SEC) C(OK)");

  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) { // select puff interval time loop

    ButtonC = digitalRead(BC);
    if ( ButtonC == LOW) {
      goto Here;
    }

    checkbuttonDstate();
    while (ButtonDstate == LOW) { // selecting puff interval minutes
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
        PuffIntmin = PuffIntmin + 1;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff Interval");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(PuffIntmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(PuffIntsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(1, 2);

      }
      checkbuttonDstate();
      if ( ButtonB == LOW) {
        PuffIntmin = PuffIntmin - 1;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff Interval");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(PuffIntmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(PuffIntsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(1, 2);

        if ( PuffIntmin == 4294967295) {
          PuffIntmin = 0;
          LCDclear();
          LCDHome();
          lcd.print("Select Puff Interval");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(PuffIntmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(PuffIntsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
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
    while (ButtonDstate == HIGH) { // selecting puff interval seconds
      delay(90);
      ButtonA = digitalRead(BA);
      ButtonB = digitalRead(BB);
      checkbuttonDstate();
      if ( ButtonA == LOW) {
        PuffIntsec = PuffIntsec + 1;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff Interval");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(PuffIntmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(PuffIntsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(14, 2);

        if ( PuffIntsec >= 60) {
          PuffIntsec = 60;
          LCDclear();
          LCDHome();
          lcd.print("Select Puff Interval");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(PuffIntmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(PuffIntsec);
          LCDSetCursorPosition(1, 3);
          lcd.print("PRESS: A(+) B(-)");
          LCDSetCursorPosition(1, 4);
          lcd.print("D(Min or SEC) C(OK)");
          LCDSetCursorPosition(14, 2);
        }
      }
      checkbuttonDstate();
      if ( ButtonB == LOW) {

        PuffIntsec = PuffIntsec - 1;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff Interval");
        LCDSetCursorPosition(1, 2);
        lcd.print(" Min:");
        LCDSetCursorPosition(6, 2);
        lcd.print(PuffIntmin);
        LCDSetCursorPosition(15, 2);
        lcd.print("SEC:");
        LCDSetCursorPosition(19, 2);
        lcd.print(PuffIntsec);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("D(Min or SEC) C(OK)");
        LCDSetCursorPosition(14, 2);
        if ( PuffIntsec == 4294967295) {
          PuffIntsec = 0;
          LCDclear();
          LCDHome();
          lcd.print("Select Puff Interval");
          LCDSetCursorPosition(1, 2);
          lcd.print(" Min:");
          LCDSetCursorPosition(6, 2);
          lcd.print(PuffIntmin);
          LCDSetCursorPosition(15, 2);
          lcd.print("SEC:");
          LCDSetCursorPosition(19, 2);
          lcd.print(PuffIntsec);
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
  delay(1);
}



void PuffMaxNum() {
  LCDclear();
  LCDHome();
  lcd.print("Select Puff NUMBER");
  LCDSetCursorPosition(2, 2);
  lcd.print("Quantity:");
  lcd.print(PuffMaxQuantity);
  LCDSetCursorPosition(1, 3);
  lcd.print("PRESS: A(+) , B(-)");
  LCDSetCursorPosition(1, 4);
  lcd.print("PRESS C for OK");
  ButtonC = digitalRead(BC);
  while ( ButtonC == HIGH) {
    delay(90);
    ButtonA = digitalRead(BA);
    ButtonB = digitalRead(BB);
    if ( ButtonA == LOW) {

      PuffMaxQuantity = PuffMaxQuantity + 1;
      LCDclear();
      LCDHome();
      lcd.print("Select Puff NUMBER");
      LCDSetCursorPosition(2, 2);
      lcd.print("Quantity:");
      lcd.print(PuffMaxQuantity);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");
    }
    if ( ButtonB == LOW) {

      PuffMaxQuantity = PuffMaxQuantity - 1;
      LCDclear();
      LCDHome();
      lcd.print("Select Puff NUMBER");
      LCDSetCursorPosition(2, 2);
      lcd.print("Quantity:");
      lcd.print(PuffMaxQuantity);
      LCDSetCursorPosition(1, 3);
      lcd.print("PRESS: A(+) , B(-)");
      LCDSetCursorPosition(1, 4);
      lcd.print("PRESS C for OK");
      if (PuffMaxQuantity <= 0) {
        PuffMaxQuantity = 1;
        LCDclear();
        LCDHome();
        lcd.print("Select Puff NUMBER");
        LCDSetCursorPosition(2, 2);
        lcd.print("Quantity:");
        lcd.print(PuffMaxQuantity);
        LCDSetCursorPosition(1, 3);
        lcd.print("PRESS: A(+) , B(-)");
        LCDSetCursorPosition(1, 4);
        lcd.print("PRESS C for OK");
      }
    }
    ButtonC = digitalRead(BC);
  }
}


void checkbuttonDstate() {
  ButtonD = digitalRead(BD);
  if (ButtonD == LOW) {
    delay(150);
    ButtonDstate = !ButtonDstate; //state start in 0
    if (ButtonDstate == LOW) {
      LCDSetCursorPosition(1, 2);
    }

    if (ButtonDstate == HIGH) {
      LCDSetCursorPosition(14, 2);
    }
  }
}
