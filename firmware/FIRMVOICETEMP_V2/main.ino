void mainApp() {
  while(true){
    RUN:
      //Serial.println(sonar.ping_cm());
      checkButton();
      if(!digitalRead(UP) || !digitalRead(DOWN)){
        washer(SET.modeSanitize);
        goto VOICE;
      }

      if(sonar.ping_cm()<30 && sonar.ping_cm()>2 && sonar.ping_cm()!=0) {
        goto VOICE;
      }
      
      lcd.setCursor(4,0);
      lcd.print("MA SAHID");
      goto RUN;
    
    VOICE:
        float t = random(20,36);
        lcd.setCursor(1,1);
        lcd.print("Suhu: ");
        lcd.print(t);
        lcd.write(DEG);
        lcd.print("C");
        voice(t);
        lcd.clear();  
  }
}
