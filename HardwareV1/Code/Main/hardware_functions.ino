//***
//* file with function prototypes
//***

//--------------LCD----------------
void LCDBacklight(char D){
 char B = "ON";
 char C = "OFF";

  if ( D == B){
  lcd.write(0xFE);
  lcd.write(0x42);
  delay(10);
  }
   if ( D == C){
  lcd.write(0xFE);
  lcd.write(0x46);
  delay(10);
  }
}

void LCDSize( int Colum, int Row){
  lcd.write(0xFE);
  lcd.write(0xD1);
  lcd.write(Colum);  // 16 columns
  lcd.write(Row);   // 2 rows
  delay(10);
}

void LCD_Auto_Line_Wrap(char A){
char B = "ON";
char C = "OFF";
  if ( A == B){
  lcd.write(0xFE);
  lcd.write(0x43);
  delay(10);
  }
if ( A == C){
  lcd.write(0xFE);
  lcd.write(0x44);
  delay(10);
  }
}

void LCDcontrast(int constrast){
  lcd.write(0xFE);
  lcd.write(0x50);
  lcd.write(constrast);
  delay(10);     
}

void LCDBrightness(int brightness){
  lcd.write(0xFE);
  lcd.write(0x99);
  lcd.write(brightness);
  delay(10);
}

void LCDclear(){
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10); 
}

void LCDcursor_Enable_Disable(char E){
char B = "ON";
char C = "OFF";

  if ( E == B){
  lcd.write(0xFE);
  lcd.write(0x4A);
  delay(10);
  lcd.write(0xFE);
  lcd.write(0x53);
  delay(10);
  }
  
if ( E == C){
  lcd.write(0xFE);
  lcd.write(0x4B);
  delay(10);
  lcd.write(0xFE);
  lcd.write(0x54);
  delay(10);
  }
}

void LCDHome(){
  lcd.write(0xFE);
  lcd.write(0x48);
  delay(10);
}

void LCDSetCursorPosition( int colum, int row){
  lcd.write(0xFE);
  lcd.write(0x47);
  lcd.write(colum);
  lcd.write(row);
  delay(10);
  
}

void LCDMoveCursor(char I){
char G = "F";
char H = "B";

if ( I == G){
  lcd.write(0xFE);
  lcd.write(0x4D);
  delay(10);
  }
  
if ( I == H){
  lcd.write(0xFE);
  lcd.write(0x4C);
  delay(10);
  
  }
  
}

void LCDRGBColor(int Red , int Green,int Blue){
  lcd.write(0xFE);
  lcd.write(0xD0);
  lcd.write(Red); 
  lcd.write(Green);
  lcd.write(Blue);
  delay(10);
}

//-------------RTC-------------------------

void RTCDateTime(){
    DateTime now = rtc.now();
    Serial.print("Date: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" | ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);
}
