#include <Keypad.h>
//#include <FastLED.h>
//#define NUM_LEDS 36
//#define DATA_PIN 2
//int lighttime = 200;
const byte ROWS = 2;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'}
};
byte colPins[COLS] = {1, 2, 3, 4}; 
byte rowPins[ROWS] = {6, 7};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
//  delay(500);
//  Serial.println("checking");
  char customKey = customKeypad.getKey();

  if (customKey) {
//    Serial.println("got one");
    switch (customKey) {
      case '0':
        
        Serial.write(B10010000);
        Serial.write(1);
        Serial.write(100);
        break;
      case '1':
      
        Serial.write(B10010000);
        Serial.write(2);
        Serial.write(100);
        break;
      case '2':
        
        Serial.write(B10010000);
        Serial.write(3);
        Serial.write(100);
        break;
      case '3':
       
        Serial.write(B10010000);
        Serial.write(4);
        Serial.write(100);
        break;
      case '4':
       
        Serial.write(B10010000);
        Serial.write(5);
        Serial.write(100);
        break;
      case '5':
       
        Serial.write(B10010000);
        Serial.write(6);
        Serial.write(100);
        break;
      case '6':
      
        Serial.write(B10010000);
        Serial.write(7);
        Serial.write(100);
        break;
      case '7':
    
        Serial.write(B10010000);
        Serial.write(8);
        Serial.write(100);
        break;
    }
  }
}
