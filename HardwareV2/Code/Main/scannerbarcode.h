// CLASS DECLARATION
class KbdRptParser : public KeyboardReportParser{
    void PrintKey(byte mod, byte key);

  private:

    void OnKeyDown  (byte mod, byte key);
    void OnKeyUp  (byte mod, byte key);
    void OnKeyPressed(byte key);
};

// IMPLEMENTATION OF METHODS
void KbdRptParser::PrintKey(byte m, byte key){
  MODIFIERKEYS mod;
  *((byte*)&mod) = m;
}

void KbdRptParser::OnKeyDown(byte mod, byte key){
  PrintKey(mod, key);
  byte c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
}

void KbdRptParser::OnKeyUp(byte mod, byte key){
  PrintKey(mod, key);
}

void KbdRptParser::OnKeyPressed(byte key){
  
  if(key == 19){
    Serial.println("Leitura finalizada");
    leituraRealizada = 1;
  }else{
    codigoLido += (char)key;  
  }
  
}

// INSTANCING OBJECTS
USB     Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;
