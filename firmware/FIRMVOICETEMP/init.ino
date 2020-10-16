void initialize() {
  Serial.begin(115200);
  mlx.begin();
  EEPROM.get(0, SET);
  
  Serial.println(F("Running Device."));
  
  lcd.init();
  lcd.backlight();
  lcd.createChar(DEG, degree);
  lcd.createChar(PLAY, playButton);
  lcd.createChar(BAR, bar);
  lcd.home();
  
  loadSetting();


  pinMode(buusyPin, INPUT);
  pinMode(TSENS, INPUT);
  
  pinMode(OK, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  
  mySoftwareSerial.begin(9600);
  

  Serial.println(F("Initializing Voice ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("VOICE ONLINE."));

  myDFPlayer.volume(SET.volume);  //Set volume value. From 0 to 30
  
  if(SET.alertMode!=1) {
    (SET.language==true)?myDFPlayer.play(1):myDFPlayer.play(2);
    delayVoice();
  }
  

}
