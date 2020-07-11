#include <Bounce.h>

// define how many pots are active up to number of available analog inputs
#define analogInputs 8
// make arrays for input values and lagged input values
int inputAnalog[analogInputs];
int iAlag[analogInputs];
// make array of cc values
int ccValue[analogInputs];
// index variable for loop
int i;

// cc values for buttons
int cc_off = 0;
int cc_on = 65;
int cc_super = 127;

// map buttons to cc for button
int cc0 = 51;
int cc1 = 52;
int cc2 = 53;
int cc3 = 54;


Bounce button0 = Bounce(0, 3);
Bounce button1 = Bounce(1, 3);
Bounce button2 = Bounce(2, 3);
Bounce button3 = Bounce(3, 3);






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
  // loop trough active inputs for knobs
  for (i=0;i<analogInputs;i++){
    // read current value at i-th input
    inputAnalog[i] = analogRead(i);
    // if magnitude of difference is 8 or more...
    if (abs(inputAnalog[i] - iAlag[i]) > 7){
      // calc the CC value based on the raw value
      ccValue[i] = inputAnalog[i]/8;
      // send the MIDI
      usbMIDI.sendControlChange(i, ccValue[i], 3);
      // set raw reading to lagged array for next comparison
      iAlag[i] = inputAnalog[i];
    }
  delay(5); // limits MIDI messages to reasonable number
  }
  
  // Push Button code
  button0.update();
  button1.update();
  button2.update();
  button3.update();

 
   if (button0.fallingEdge())
  {
    usbMIDI.sendControlChange(cc0, cc_on, 3);
  }
  if (button1.fallingEdge())
  {
    usbMIDI.sendControlChange(cc1, cc_on, 3);
  }
  if (button2.fallingEdge())
  {
    usbMIDI.sendControlChange(cc2, cc_on, 3);
  }
  if (button3.fallingEdge())
  {
    usbMIDI.sendControlChange(cc3, cc_on, 3);
  }

   
  if (button0.risingEdge())
  {
    usbMIDI.sendControlChange(cc0, cc_off, 3);
  }
  if (button1.risingEdge())
  {
    usbMIDI.sendControlChange(cc1, cc_off, 3);
  }
  if (button2.risingEdge())
  {
    usbMIDI.sendControlChange(cc2, cc_off, 3);
  }
  if (button3.risingEdge())
  {
    usbMIDI.sendControlChange(cc3, cc_off, 3);
  }
  
}
