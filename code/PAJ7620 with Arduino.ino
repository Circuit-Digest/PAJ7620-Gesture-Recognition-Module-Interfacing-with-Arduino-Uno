#include <DFRobot_PAJ7620U2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t rightChar[8] = { B00000, B00000, B00100, B00010, B11111, B00010, B00100, B00000 };
uint8_t leftChar[8] = { B00000, B00000, B00100, B01000, B11111, B01000, B00100, B00000 };
uint8_t upChar[8] = { B00000, B00000, B00100, B01110, B10101, B00100, B00100, B00000 };
uint8_t downChar[8] = { B00000, B00100, B00100, B10101, B01110, B00100, B00000, B00000 };
uint8_t forwardChar[8] = { B00100, B10101, B01110, B00100, B00000, B00000, B01110, B01110 };
uint8_t backwardChar[8] = { B00100, B01110, B10101, B00100, B00000, B00000, B01110, B01110 };
uint8_t clockwiseChar[8] = { B01110, B10001, B00001, B00001, B01010, B01100, B01110, B00000 };
uint8_t antiClockwiseChar[8] = { B00000, B01110, B01100, B01010, B00001, B00001, B10001, B01110 };
uint8_t waveRightChar[8] = { B00111, B00011, B00101, B01000, B00010, B10100, B11000, B11100 };
uint8_t waveLeftChar[8] = { B11100, B11000, B10100, B00010, B01000, B00101, B00011, B00111 };

DFRobot_PAJ7620U2 paj;

void setup() {
  Serial.begin(115200);
  delay(300);

  lcd.begin();
  lcd.createChar(1, waveRightChar);
  lcd.createChar(2, waveLeftChar);
  lcd.createChar(3, upChar);
  lcd.createChar(4, downChar);
  lcd.createChar(5, forwardChar);
  lcd.createChar(6, backwardChar);
  lcd.createChar(7, clockwiseChar);
  lcd.createChar(8, antiClockwiseChar);

  Serial.println("Gesture recognition system base on PAJ7620U2");
  while (paj.begin() != 0) {
    Serial.println("initial PAJ7620U2 failure! Please check if all the connections are fine, or if the wire sequence is correct?");
    delay(500);
  }
  Serial.println("PAJ7620U2init completed, start to test the gesture recognition function");


  /*Set fast detection mode 
   *If the parameter is set to false, the module enters slow detection mode, and it detects one gesture every 2s. We have integrated 
   *some gestures inside the module to make it convenient for beginners.
   *The slow mode can recognize 9  basic gestures and 4 expanded gestures: move left, right, up, down, forward, backward, clockwise, 
   *counter-clockwise, wave, slowly move left and right, slowly move up and down, slowly move forward and backward,
   *wave slowly and randomly. 
   *
   *
   *
   *If the parameter is set to true, the module enters fast detection mode. 
   *The fast mode can recognize 9 gestures: move left, right, up, down, forward, backward, clockwise, counter-clockwise, wave.
   *To detect the combination of these gestures, like wave left, right and left quickly, users needs to design their own
   *algorithms logic.
   *Since users only use limited gestures in this mode, we are not going to integrate too much expanded gestures in the library.
   *If necessary, you can complete the algorithm logic in the ino file by yourself.
   */
  paj.setGestureHighRate(false);


  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("Ready to");
  lcd.setCursor(3, 1);
  lcd.print("Recognize");
}

void loop() {

  DFRobot_PAJ7620U2::eGesture_t gesture = paj.getGesture();
  if (gesture != paj.eGestureNone) {
    lcd.clear();

    /* Get the string descritpion corresponding to the gesture number
    * The string description could be  
    * "None","Right","Left", "Up", "Down", "Forward", "Backward", "Clockwise", "Anti-Clockwise", "Wave",
    * "WaveSlowlyDisorder", "WaveSlowlyLeftRight", "WaveSlowlyUpDown", "WaveSlowlyForwardBackward"
    */
    String description = paj.gestureDescription(gesture);
    Serial.println("--------------Gesture Recognition System---------------------------");
    Serial.print("gesture code        = ");
    Serial.println(gesture);
    Serial.print("gesture description  = ");
    Serial.println(description);
    Serial.println();

    switch (gesture) {
      case 1:
        lcd.setCursor(3, 0);
        lcd.write(byte(1));
        lcd.print(" ");
        lcd.print("RIGHT");
        lcd.print(" ");
        lcd.write(byte(1));
        break;
      case 2:
        lcd.setCursor(4, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("LEFT");
        lcd.print(" ");
        lcd.write(byte(2));
        break;
      case 4:
        lcd.setCursor(5, 0);
        lcd.write(byte(3));
        lcd.print(" ");
        lcd.print("UP");
        lcd.print(" ");
        lcd.write(byte(3));
        break;
      case 8:
        lcd.setCursor(4, 0);
        lcd.write(byte(4));
        lcd.print(" ");
        lcd.print("DOWN");
        lcd.print(" ");
        lcd.write(byte(4));
        break;
      case 16:
        lcd.setCursor(2, 0);
        lcd.write(byte(5));
        lcd.print(" ");
        lcd.print("FORWARD");
        lcd.print(" ");
        lcd.write(byte(5));
        break;
      case 32:
        lcd.setCursor(2, 0);
        lcd.write(byte(6));
        lcd.print(" ");
        lcd.print("BACKWARD");
        lcd.print(" ");
        lcd.write(byte(6));
        break;
      case 64:
        lcd.setCursor(2, 0);
        lcd.write(byte(7));
        lcd.print(" ");
        lcd.print("CLOCKWISE");
        lcd.print(" ");
        lcd.write(byte(7));
        break;
      case 128:
        lcd.setCursor(4, 0);
        lcd.write(byte(8));
        lcd.print(" ");
        lcd.print("    ");
        lcd.print(" ");
        lcd.write(byte(8));
        lcd.setCursor(1, 1);
        lcd.print("ANTI-CLOCKWISE");
        break;
      case 256:
        lcd.setCursor(4, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("WAVE");
        lcd.print(" ");
        lcd.write(byte(1));
        break;
      case 512:
        lcd.setCursor(2, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("SLOW WAVE");
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.setCursor(4, 1);
        lcd.print("DISORDER");
        break;
      case 3:
        lcd.setCursor(2, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("SLOW WAVE");
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.setCursor(3, 1);
        lcd.print("LEFT-RIGHT");
        break;
      case 12:
        lcd.setCursor(2, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("SLOW WAVE");
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.setCursor(4, 1);
        lcd.print("UP-DOWN");
        break;
      case 48:
        lcd.setCursor(2, 0);
        lcd.write(byte(2));
        lcd.print(" ");
        lcd.print("SLOW WAVE");
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.setCursor(1, 1);
        lcd.print("FORWARD-BACKWARD");
        break;
      default:
        lcd.print("New Gesture");
        break;
    }
  }
}
