#define DEG              0
#define PLAY             1
#define BAR              3

#define OK               2   //pin button
#define UP               3   //pin button
#define DOWN             4   //pin button

#define STATE            LOW
#define BOUNCE           50

#define SanitizeSENS     A2  //pin sensor jarak
#define TRESHHOLD        38  //suhu batas

#define buusyPin         12   //pin busy DFPLAYER
int bsy = 0;

bool sens = false;



#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//#include <Wire.h> 
#include "LiquidCrystal_I2C.h"
#include "EEPROM.h"

#include "symbols.h" 

struct SETTINGS {
  int   alertMode;
  bool  language;
  int   volume;
  int   modeSanitize;
};

SETTINGS SET;

#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#include <NewPing.h>

#define TRIGGER_PIN  A1  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A0  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



#define RELAY 5


void printDetail(uint8_t type, int value);
void voice(float t = 50.66);
