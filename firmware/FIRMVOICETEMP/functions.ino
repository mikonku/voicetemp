void loadSetting(){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("LOADING");
  
  lcd.setCursor(0,1);
  for(int i=0;i<32;i++) {
    lcd.write(BAR);
    delay(20);
    i++;  
  }
  lcd.clear();
}

void washer(int type) {
  if(type == 1) {
    Serial.println(F("OFF"));
  }
  else if(type == 2) {
    Serial.println(F("WATER"));
    while(TempSENS==false) {
      digitalWrite(RELAY, HIGH);
      delay(100);
    }
  }
  else if(type == 3) {
    Serial.println(F("SANITIZER"));   
  } 
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
