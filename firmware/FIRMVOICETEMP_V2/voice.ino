void delayVoice() { 
//  if (myDFPlayer.available()) {
//        printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
//  }
  int z=0;
  int bsyflag=0;
  //Serial.println(" ");
  //Serial.print("busypin ");
  for(z=0; z<=100; z++){
    bsy = digitalRead(buusyPin);
    //Serial.print(bsy);
    delay(20); 
    if (bsyflag==1 && bsy==1){
      break;
    }
    if(bsy==0){
      bsyflag=1;
    }
  }  
}


void voice(float t)
{
   if(t>100){
    //Serial.println("ANDA MENDIDIH");
    myDFPlayer.playMp3Folder(2);
    delayVoice();
    if(SET.alertMode!=1) {
      (SET.language==true)?myDFPlayer.playMp3Folder(3):myDFPlayer.playMp3Folder(10);
      delayVoice();
    }
    delay(3000);
    return;
  } 
  
  else if(t>SET.Thresh && t<100){
    myDFPlayer.playMp3Folder(2);
    delayVoice();
    //Serial.println("ANDA SAKIT");
    if(SET.alertMode!=1) {
      (SET.language==true)?myDFPlayer.playMp3Folder(8):myDFPlayer.playMp3Folder(15);delayVoice();
    }
    delay(3000);
    return;
  }
  
  else if(t<20) {
    //Serial.println("SUHU ANDA DIBAWAH 20");
    if(SET.alertMode!=1) {
      (SET.language==true)?myDFPlayer.playMp3Folder(7):myDFPlayer.playMp3Folder(14); delayVoice();
    }
    delay(3000);
    return;
  }

  if(SET.alertMode==1) {
    delay(3000);
    return;
  } else {
    
    String sens = String(t);
    char x[sens.length()];
    strcpy(x, sens.c_str());
    int _p, _s;
    int b = 1;
    while(b){
      for(int i=0; i<sens.length()-1; i++){ 
        
        //Serial.println(x[i]);
        switch (x[i]) {
        case '.':
          if(SET.language == true) {
            myDFPlayer.playFolder(3, 2);
          } else {
            myDFPlayer.playFolder(3, 3);
          }
          delayVoice();
          break;
        case '0':
          if(SET.language == true) {
            if (i==1) {
              //Serial.print(F("0A"));
            }
            else {
              myDFPlayer.playFolder(1,10); delayVoice();
            }
          } else {
            if(i==1){
              //Serial.print(F("0A"));
            } else {
              myDFPlayer.playFolder(1,20); delayVoice();
            }
          }
          
          break;
        case '1':
          //(i==0)? myDFPlayer.playFolder(2, 1):myDFPlayer.playFolder(1, 1);
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 1);} else {myDFPlayer.playFolder(1, 1);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 11);} else {myDFPlayer.playFolder(1, 11);}
          }
          delayVoice();
          break;
        case '2':
          //(i==0)? myDFPlayer.playFolder(2, 2):myDFPlayer.playFolder(1, 2);
          if(SET.language == true) { 
            if(i==0) {myDFPlayer.playFolder(2, 2);} else {myDFPlayer.playFolder(1, 2);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 12);} else {myDFPlayer.playFolder(1, 12);}
          }
          delayVoice();
          break;
        case '3':
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 3);} else {myDFPlayer.playFolder(1, 3);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 13);} else {myDFPlayer.playFolder(1, 13);}
          }
          delayVoice();
          break;
        case '4':
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 4);} else {myDFPlayer.playFolder(1, 4);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 14);} else {myDFPlayer.playFolder(1, 14);}
          }
          delayVoice();
          break;
        case '5':
          //(i==0)? myDFPlayer.playFolder(2, 5):myDFPlayer.playFolder(1, 5);
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 5);} else {myDFPlayer.playFolder(1, 5);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 15);} else {myDFPlayer.playFolder(1, 15);}
          }
          delayVoice();
          break;
        case '6':
          //(i==0)? myDFPlayer.playFolder(2, 6):myDFPlayer.playFolder(1, 6);
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 6);} else {myDFPlayer.playFolder(1, 6);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 16);} else {myDFPlayer.playFolder(1, 16);}
          }
          delayVoice();
          break;
        case '7':
          //(i==0)? myDFPlayer.playFolder(2, 7):myDFPlayer.playFolder(1, 7);
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 7);} else {myDFPlayer.playFolder(1, 7);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 17);} else {myDFPlayer.playFolder(1, 17);}
          }
          delayVoice();
          break;
        case '8':
          //(i==0)? myDFPlayer.playFolder(2, 8):myDFPlayer.playFolder(1, 8);
          if(SET.language == true) {
            if(i==0) {myDFPlayer.playFolder(2, 8);} else {myDFPlayer.playFolder(1, 8);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 18);} else {myDFPlayer.playFolder(1, 18);}
          }
          delayVoice();
          break;
        case '9':
          //(i==0)? myDFPlayer.playFolder(2, 9):myDFPlayer.playFolder(1, 9);
          if(SET.language == true) {   
            if(i==0) {myDFPlayer.playFolder(2, 9);} else {myDFPlayer.playFolder(1, 9);}
          } else {
            if(i==0) {myDFPlayer.playFolder(2, 19);} else {myDFPlayer.playFolder(1, 19);}
          }
          delayVoice();
          break;
        }
    
      } b=0;
    }  
    }
}
