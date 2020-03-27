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
    myFile.print("Date: ");
    myFile.print(now.year(), DEC);
    myFile.print('/');
    myFile.print(now.month(), DEC);
    myFile.print('/');
    myFile.print(now.day(), DEC);
    myFile.print(" | ");
    myFile.print(now.hour(), DEC);
    myFile.print(':');
    myFile.print(now.minute(), DEC);
    myFile.print(':');
    myFile.println(now.second(), DEC);
    
}

void CreateFile() {
  //put this next line *Right Before* any file open line:
  Serial.println("Creating a new file");

 digitalWrite(USBcs,HIGH);
 digitalWrite(SDcs,LOW);
 
  // see if the card is present and can be initialized:
  if (!SD.begin(SDcs)) {
    
  } else {
    Serial.println("Able to select card");
  }



  // Name filename in format F###_MMDDYYNN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  strcpy(filename, "________.CSV");  // placeholder filename
  getFilename(filename);//getfilename is a function that generates the filename using the device number, date, and increment
  Serial.println("Past getting file name");
  myFile = SD.open(filename, FILE_WRITE);//this creates a file with that name and assigns opening it to a variable (logfile)
Serial.println(filename);
  if (!myFile) {
    Serial.println("Cannot open File");
    while(1);
  }

}


void getFilename(char *filename) {
  Serial.println("Generating file name");
  DateTime now = rtc.now();
  //filename[3] = (device / 100) % 10 + '0';
  //filename[3] = (device / 10) % 10 + '0';
  filename[0] = device % 10 + '0';
  filename[1] = now.month() / 10 + '0';
  filename[2] = now.month() % 10 + '0';
  filename[3] = now.day() / 10 + '0';
  filename[4] = now.day() % 10 + '0';
  filename[5] = (now.year() / 1000) % 10 + '0'; // descart the first to digits
  filename[6] = (now.year() / 100) % 10 + '0';  // descart the first to digits
  filename[5] = (now.year() / 10) % 10 + '0';
  filename[6] = now.year() % 10 + '0';
  filename[8] = '.';
  filename[9] = 'C';
  filename[10] = 'S';
  filename[11] = 'V';
  for (uint8_t i = 0; i < 10; i++) {
    //filename[8] = '0' + i / 10;
    filename[7] = '0' + i % 10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename)) {
      break;
    }
  }
  
  
}
