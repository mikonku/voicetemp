void MODE (int MOD) {
  while(true){
      if(digitalRead(OK) == STATE){
        delay(BOUNCE);
        while(digitalRead(OK) == STATE) {}
        lcd.clear();
        menuSetting();
      }
      else if(digitalRead(UP) == STATE){
        delay(BOUNCE);
        while(digitalRead(UP) == STATE) {}
        lcd.clear();
        (MOD>1)?MOD=1:MOD++;    
      }
      else if(digitalRead(DOWN) == STATE){
        delay(BOUNCE);
        while(digitalRead(DOWN) == STATE) {}
        lcd.clear();
        (MOD<1)?MOD=3:MOD--;    
      }

      SET.alertMode = MOD;
      lcd.setCursor(0,0);
      lcd.print("ALERT MODE?  ");
      
      if(MOD == 1) {

        lcd.setCursor(3,1);
        lcd.print(" BEEP");   
      }
      else if(MOD == 2) {
        lcd.setCursor(3,1);
        lcd.print(" VOICE ");
      }
//      else if(MOD == 3) {
//        lcd.setCursor(3,1);
//        lcd.print(" FULL  ");
//      }
      //Serial.print(MOD);
  }
  
}

void LANGUAGE (bool LAN) {
  while(true){
      if(digitalRead(OK) == STATE){
        delay(BOUNCE);
        while(digitalRead(OK) == STATE) {}
        lcd.clear();
        menuSetting();
      }
      else if(digitalRead(UP) == STATE || digitalRead(DOWN) == STATE){
        delay(BOUNCE);
        while(digitalRead(UP) == STATE) {}
        while(digitalRead(DOWN) == STATE) {}
        lcd.clear();
        LAN=!LAN;    
      }
      SET.language = LAN;
      lcd.setCursor(0,0);
      lcd.print("VOICE LANGUAGE?");
      
      if(LAN == true) {
        lcd.setCursor(3,1);
        lcd.print("INDONESIA");  
      }

      else if(LAN == false) {
        lcd.setCursor(3,1);
        lcd.print(" ENGLISH ");
      }
  }
}

void VOLUME (int VOL) {
  
  while(true) {
    if(digitalRead(OK) == STATE){
      delay(BOUNCE);
      while(digitalRead(OK) == STATE) {}
      lcd.clear();
      menuSetting();    
    }
    else if(digitalRead(UP) == STATE){
      delay(BOUNCE);
      while(digitalRead(UP) == STATE) {}
      lcd.clear();
      if(VOL<30) VOL++;    
    }
    else if(digitalRead(DOWN) == STATE){
      delay(BOUNCE);
      while(digitalRead(DOWN) == STATE) {}
      lcd.clear();
      if(VOL>10) VOL--;    
    }
    SET.volume = VOL;
    lcd.setCursor(0,1);
    lcd.print("VOLUME = ");
    lcd.print(VOL);

  }
  
}
