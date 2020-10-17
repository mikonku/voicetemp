void mainApp() {
  while(true){
    RUN:
      //Serial.println(sonar.ping_cm());
      checkButton();
      if(!digitalRead(UP) || !digitalRead(DOWN) ){
       // washer(SET.modeSanitize);
        goto VOICE;
      }

      if (!digitalRead(TempSENS)) {
        //washer(SET.modeSanitize);
        delay(500);
        goto VOICE;
      }
//      if(SET.modeSanitize!=1){
        if(!digitalRead(SanitizeSENS)) {
          washer(SET.modeSanitize);
        }

//      }
//      
      lcd.setCursor(4,0);
      lcd.print("MA SAHID");
      goto RUN;
    
    VOICE:
        float t = mlx.readObjectTempC()+SET.Callib;
        lcd.setCursor(1,1);
        lcd.print("Suhu: ");
        lcd.print(t);
        lcd.write(DEG);
        lcd.print("C");
        voice(t);
        lcd.clear();  
  }
}
