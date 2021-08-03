# voicetemp
This is my project for build a device for measuring temperature body. The device have "VOICE" feature in two languages, so you can set language what do you want.
# Features
1. Voice feature, in addition to the LCD displaying the measured body temperature, this device can also notify the measured body temperature through the speaker in the language we choose (this feature can be turned on or off).
2. The language setting feature, I pinned two languages for this device, namely English and Indonesian (my country of origin)
3. The normal temperature limit setting feature, we can determine the normal temperature limit of the human body(please see the scientific reference regarding this)
4. Calibration feature, for this feature is still rough, I only use the difference in body temperature with this device against devices that have been widely used. Maybe readers can develop it further.

### Materials:
1. Arduino Nano
2. Temperature Sensor (MLX90614)
3. IR Obstacle Sensor
4. DFRobot DFPlayer Mini
5. LCD 16x2 + I2C Module
6. Speaker
7. Relay
8. Mini Pump 5V
9. Push Button

### The firmware uses several libraries, including:
1. Adafruit MLX90614 Library (https://github.com/adafruit/Adafruit-MLX90614-Library/)
2. DFRobot DFPlayer Mini Library (https://github.com/DFRobot/DFRobotDFPlayerMini/archive/1.0.3.zip)
3. LiquidCrystal I2C Library (https://github.com/johnrickman/LiquidCrystal_I2C)
4. Software Serial Library (built-in Arduino)
5. EEPROM Library (buil-in Arduino)

Schematic for this project:
![schematic](Schematic.png)
