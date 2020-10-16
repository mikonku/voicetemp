void mainMenu() {
  while(true){
    BACK:
      if(digitalRead(OK) == STATE){
        delay(BOUNCE);
        while(digitalRead(OK) == STATE) {}
        lcd.clear();
        mainApp();
      }
      else if(digitalRead(UP) == STATE || digitalRead(DOWN) == STATE){
        delay(BOUNCE);
        while(digitalRead(UP) == STATE) {}
        while(digitalRead(DOWN) == STATE) {}
        lcd.clear();
        goto NEXT;    
      }

      
      lcd.setCursor(0,0);
      lcd.print(" GO TO SETTING? ");
      lcd.setCursor(0,1);
      lcd.write(PLAY);
      lcd.print("BACK");
      lcd.setCursor(10,1);
      lcd.print(" NEXT");
      goto BACK;

    NEXT:
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
        goto BACK;    
      }
      
      lcd.setCursor(0,0);
      lcd.print(" GO TO SETTING? ");
      lcd.setCursor(0,1);
      lcd.print(" BACK");
      lcd.setCursor(10,1);
      lcd.write(PLAY);
      lcd.print("NEXT");
      goto NEXT;
  }
}

void menuSetting(){
  bool fromUP;
  setMenu1:
    if(digitalRead(OK) == STATE){
      delay(BOUNCE);
      while(digitalRead(OK) == STATE) {}
      lcd.clear();
      MODE(SET.alertMode);    
    }
    else if(digitalRead(UP) == STATE){
      delay(BOUNCE);
      while(digitalRead(UP) == STATE) {}
      lcd.clear();
      goto setMenu4;    
    }
    else if(digitalRead(DOWN) == STATE){
      delay(BOUNCE);
      while(digitalRead(DOWN) == STATE) {}
      lcd.clear();
      fromUP = true;
      goto setMenu2;    
    }

    

    lcd.setCursor(0,0);
    lcd.write(PLAY);
    lcd.print("ALERT MODE");
    lcd.setCursor(0,1);
    //lcd.write(PLAY);
    lcd.print(" LANGUAGE");
      
    goto setMenu1;
    
  setMenu2:
    if(digitalRead(OK) == STATE){
      delay(BOUNCE);
      while(digitalRead(OK) == STATE) {}
      lcd.clear();
      LANGUAGE(SET.language);    
    }
    else if(digitalRead(UP) == STATE){
      delay(BOUNCE);
      while(digitalRead(UP) == STATE) {}
      lcd.clear();
      goto setMenu1;    
    }
    else if(digitalRead(DOWN) == STATE){
      delay(BOUNCE);
      while(digitalRead(DOWN) == STATE) {}
      lcd.clear();
      fromUP = true;
      goto setMenu3;    
    }

    if(fromUP == false){
      lcd.setCursor(0,0);
      lcd.write(PLAY);
      lcd.print("LANGUAGE");
      lcd.setCursor(0,1);
      //lcd.write(PLAY);
      lcd.print(" VOLUME");
    } else {
      lcd.setCursor(0,0);
      //lcd.write(PLAY);
      lcd.print(" ALERT MODE");
      lcd.setCursor(0,1);
      lcd.write(PLAY);
      lcd.print("LANGUAGE");
    }
    goto setMenu2;
    
  setMenu3:
    if(digitalRead(OK) == STATE){
      delay(BOUNCE);
      while(digitalRead(OK) == STATE) {}
      lcd.clear();
      VOLUME(SET.volume);    
    }
    else if(digitalRead(UP) == STATE){
      delay(BOUNCE);
      while(digitalRead(UP) == STATE) {}
      lcd.clear();
      fromUP = false;
      goto setMenu2;    
    }
    else if(digitalRead(DOWN) == STATE){
      delay(BOUNCE);
      while(digitalRead(DOWN) == STATE) {}
      lcd.clear();
      goto setMenu4;    
    }

    if(fromUP == false){
      lcd.setCursor(0,0);
      lcd.write(PLAY);
      lcd.print("VOLUME");
      lcd.setCursor(0,1);
      //lcd.write(PLAY);
      lcd.print(" CLOSE");
    } else {
      lcd.setCursor(0,0);
      //lcd.write(PLAY);
      lcd.print(" LANGUAGE");
      lcd.setCursor(0,1);
      lcd.write(PLAY);
      lcd.print("VOLUME");
    }    
    goto setMenu3;

    
  setMenu4:
    if(digitalRead(OK) == STATE){
      delay(BOUNCE);
      while(digitalRead(OK) == STATE) {}
      EEPROM.put(0, SET);
      loadSetting();
      mainApp();    
    }
    else if(digitalRead(UP) == STATE){
      delay(BOUNCE);
      while(digitalRead(UP) == STATE) {}
      lcd.clear();
      goto setMenu3;    
    }
    else if(digitalRead(DOWN) == STATE){
      delay(BOUNCE);
      while(digitalRead(DOWN) == STATE) {}
      lcd.clear();
      goto setMenu1;    
    }
    lcd.setCursor(0,0);
    //lcd.write(PLAY);
    lcd.print(" VOLUME");
    lcd.setCursor(0,1);
    lcd.write(PLAY);
    lcd.print("CLOSE ");
    
    goto setMenu4; 
}

void checkButton(){
  // check for button press
  if ( digitalRead(OK) == STATE ) {
    // poor mans debounce/press-hold, code not ideal for production
    delay(BOUNCE);
    if( digitalRead(OK) == STATE ){
      Serial.println(F("Button Pressed"));
      // still holding button for 3000 ms, reset settings, code not ideaa for production
      delay(3000); // reset delay hold
      
      
      
      if( digitalRead(OK) == STATE ){
        loadSetting();
        while(digitalRead(OK) == STATE) {}
        lcd.clear();
        Serial.println(F("GO TO MENU"));
        mainMenu();
      }
      lcd.clear();
    }
  }
}
