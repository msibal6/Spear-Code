#include <Bounce.h>

// Firmware for Hernan's birthday controller
// define how many pots are active up to number of available analog inputs
#define ANALOG_INPUTS 8
// make arrays for input values and lagged input values
int inputAnalog[ANALOG_INPUTS];
int iAlag[ANALOG_INPUTS];
// make array of cc values
int ccValue[ANALOG_INPUTS];

// cc values for buttons
int cc_off = 0;
int cc_on = 65;
int cc_super = 127;

// map buttons to cc for button
int cc0 = 51;
int cc1 = 52;
int cc2 = 53;
int cc3 = 54;

Bounce but4 = Bounce( 1, 5);
Bounce but3 = Bounce( 2, 5);
Bounce but2 = Bounce( 3, 5);
Bounce but1 = Bounce( 4, 5);
Bounce but5 = Bounce(9, 5);
Bounce but6 = Bounce(8, 5);
Bounce but7 = Bounce(7, 5);
Bounce but8 = Bounce(6, 5);

void setup() {
  // MIDI rate
  Serial.begin(31250);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void loop() {
  for (int i = 1; i <= ANALOG_INPUTS; i++) {
    // read current value at i-th input
    inputAnalog[i] = analogRead(i);
    // if magnitude of difference is 8 or more...
    if (abs(inputAnalog[i] - iAlag[i]) > 7){
      // calc the CC value based on the raw value
      ccValue[i] = inputAnalog[i]/8;
      // send the MIDI
      usbMIDI.sendControlChange(i, ccValue[i], i);
      // set raw reading to lagged array for next comparison
      iAlag[i] = inputAnalog[i];
    } else {
      continue;
    }
  delay(5); // limits MIDI messages to reasonable number
  }
  while (usbMIDI.read());

  but1.update();
  but2.update();
  but3.update();
  but4.update();
  but5.update();
  but6.update();
  but7.update();
  but8.update();

  // Pressing the buttons
  if (but1.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, 3);  // 60 = C4  
  }
  if (but2.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, 3);  // 60 = C4  
  }
  if (but3.fallingEdge()) {
    usbMIDI.sendNoteOn(62, 99, 3);  // 60 = C4  
  }
  if (but4.fallingEdge()) {
    usbMIDI.sendNoteOn(63, 99, 3);  // 60 = C4  
  }
  if (but5.fallingEdge()) {
    usbMIDI.sendNoteOn(64, 99, 3);  // 60 = C4  
  }
  if (but6.fallingEdge()) {
    usbMIDI.sendNoteOn(65, 99, 3);  // 60 = C4  
  }
  if (but7.fallingEdge()) {
    usbMIDI.sendNoteOn(66, 99, 3);  // 60 = C4  
  }
  if (but8.fallingEdge()) {
    usbMIDI.sendNoteOn(67, 99, 3);  // 60 = C4  
  }

  // releasing the buttons
  if (but1.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, 3);  // 60 = C4  
  }
  if (but2.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, 3);  // 60 = C4  
  }
  if (but3.risingEdge()) {
    usbMIDI.sendNoteOff(62, 0, 3);  // 60 = C4  
  }
  if (but4.risingEdge()) {
    usbMIDI.sendNoteOff(63, 0, 3);  // 60 = C4  
  }
  if (but5.risingEdge()) {
    usbMIDI.sendNoteOff(64, 0, 3);  // 60 = C4  
  }
  if (but6.risingEdge()) {
    usbMIDI.sendNoteOff(65, 0, 3);  // 60 = C4  
  }
  if (but7.risingEdge()) {
    usbMIDI.sendNoteOff(66, 0, 3);  // 60 = C4  
  }
  if (but8.risingEdge()) {
    usbMIDI.sendNoteOff(67, 0, 3);  // 60 = C4  
  }
}
