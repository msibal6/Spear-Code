/* SnackyMini Keyboad Firmware
   By @huydotnet
   You must select Keyboard from the "Tools > USB Type" menu.
*/


/* Forked by Mitchell Sibal
   Not sure if this actually forked lol
   Version ANSI	104
*/

/* List of changes made
    changed NULL_KEY to KEY_NULL
    update the refCode table
    Deleted FN layout because I do not have FN key
*/
#include <Keyboard.h>
// Comment this out to use QWERTY layout
//#define USE_DVORAK

// KEYS THAT MIGHT NOT WORK
// backtick
// 
#define ARROW_UP_KEY    91
#define ARROW_DOWN_KEY  112
#define ARROW_LEFT_KEY  111
#define ARROW_RIGHT_KEY 113
#define SHIFT_KEY       89//62
#define RIGHT_SHIFT_KEY 101
#define MENU_KEY        93
#define FN_KEY          110
#define BACKSPACE_KEY   61
#define ENTER_KEY       102
#define TAB_KEY         103
#define SUPER_KEY       111
#define RIGHT_SUPER_KEY 121
#define CTRL_KEY        110
#define RIGHT_CTRL_KEY  124
#define ALT_KEY         113
#define RIGHT_ALT_KEY   120
#define KEY_NULL        0

#ifndef KEY_BACKTICK
#define KEY_BACKTICK 53
#endif

#define ROWS           6
#define COLS           22
#define DEFAULT_LAYOUT 0
#define FN_LAYOUT      1

#define MAXIMUM_STROKES   10
#define DEBOUNCE_DELAY    15

const int SUPPORTED_STROKES = 6;
unsigned long lastFrame = 0;

// DO NOT EDIT
// The key code map of the board. I don't know why it's weird.
// Need to debug some day.
// Had to edit to fit my ANSI 104 keyboard
char refCode[ROWS][COLS] = {
	{ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15, 
		16, 17, 18, 19, 20, 21},
	{ 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 
		38, 39, 40, 41, 42, 43}, 
	{ 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
		60, 61, 62, 63, 64, 65},
	{ 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81,
		82, 83, 84, 85, 86, 87},
	{ 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
		104, 105, 106, 107, 108, 109},
	{ 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123,
		124, 125, 126, 127, 128, 129, 130, 131}
};

#ifndef USE_DVORAK
// QWERTY LAYOUT
// TODO 
// Add my six ROW and 22 COL
//uint8_t
// int
uint8_t keyLayout[][ROWS][COLS] = {
  // Default layout
  {
    { KEY_ESC, KEY_NULL, KEY_F1, KEY_F2, KEY_F3, KEY_F4,  KEY_NULL, KEY_F5, 
	  KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, 
	  KEY_PRINTSCREEN, KEY_SCROLL_LOCK, KEY_PAUSE, KEY_NULL, KEY_NULL, 
	  KEY_NULL, KEY_NULL}, 
    { KEY_BACKTICK, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8,
    KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_NULL, KEY_BACKSPACE, KEY_INSERT,
    KEY_HOME, KEY_PAGE_UP, KEY_NUM_LOCK, KEYPAD_SLASH, KEYPAD_ASTERIX, 
    KEYPAD_MINUS}, 
    { KEY_TAB, KEY_NULL, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, 
    KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_BACKSLASH, 
    KEY_DELETE, KEY_END, KEY_PAGE_DOWN, KEYPAD_7, KEYPAD_8, KEYPAD_9, 
    KEYPAD_PLUS},
    { KEY_CAPS_LOCK, KEY_NULL, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, 
    KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER, KEY_NULL, 
    KEY_NULL, KEY_NULL, KEY_NULL, KEYPAD_4, KEYPAD_5, KEYPAD_6, KEY_NULL},
    { KEY_NULL, KEY_NULL, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N,
    KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_NULL,
    KEY_NULL, KEY_NULL, KEY_NULL, KEY_UP, KEY_NULL, KEYPAD_1,
    KEYPAD_2, KEYPAD_3, KEYPAD_ENTER},
    {MODIFIERKEY_CTRL, MODIFIERKEY_GUI, KEY_NULL, MODIFIERKEY_ALT, KEY_NULL,
    KEY_NULL, KEY_SPACE, KEY_NULL, KEY_NULL, KEY_NULL, MODIFIERKEY_RIGHT_ALT,
    MODIFIERKEY_RIGHT_GUI, KEY_NULL, MODIFIERKEY_RIGHT_GUI, 
    MODIFIERKEY_RIGHT_CTRL, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEYPAD_0,
    KEY_NULL, KEYPAD_PERIOD, KEY_NULL}
    
	

  },
  // Fn layout
  {
   { KEY_ESC, KEY_NULL, KEY_F1, KEY_F2, KEY_F3, KEY_F4,  KEY_NULL, KEY_F5, 
	KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, 
	KEY_PRINTSCREEN, KEY_SCROLL_LOCK, KEY_PAUSE, KEY_NULL, KEY_NULL, 
	KEY_NULL, KEY_NULL}, 
    { KEY_BACKTICK, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8,
    KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_NULL, KEY_BACKSPACE, KEY_INSERT,
    KEY_HOME, KEY_PAGE_UP, KEY_NUM_LOCK, KEYPAD_SLASH, KEYPAD_ASTERIX, 
    KEYPAD_MINUS}, 
    { KEY_TAB, KEY_NULL, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, 
    KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_BACKSLASH, 
    KEY_DELETE, KEY_END, KEY_PAGE_DOWN, KEYPAD_7, KEYPAD_8, KEYPAD_9, 
    KEYPAD_PLUS},
    { KEY_CAPS_LOCK, KEY_NULL, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, 
    KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER, KEY_NULL, 
    KEY_NULL, KEY_NULL, KEY_NULL, KEYPAD_4, KEYPAD_5, KEYPAD_6, KEY_NULL},
    { KEY_NULL, MODIFIERKEY_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N,
    KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_NULL,
    MODIFIERKEY_RIGHT_SHIFT, KEY_NULL, KEY_NULL, KEY_UP, KEY_NULL, KEYPAD_1,
    KEYPAD_1, KEYPAD_1, KEYPAD_ENTER},
    {MODIFIERKEY_CTRL, MODIFIERKEY_GUI, KEY_NULL, MODIFIERKEY_ALT, KEY_NULL,
    KEY_NULL, KEY_SPACE, KEY_NULL, KEY_NULL, KEY_NULL, MODIFIERKEY_RIGHT_ALT,
    MODIFIERKEY_RIGHT_GUI, KEY_NULL, MODIFIERKEY_RIGHT_GUI, 
    MODIFIERKEY_RIGHT_CTRL, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEYPAD_0,
    KEY_NULL, KEYPAD_PERIOD, KEY_NULL}
  }
};
#else
// DVORAK LAYOUT
uint8_t keyLayout[][ROWS][COLS] = {
  // Default layout
  {
   { KEY_TAB  , KEY_QUOTE    , KEY_COMMA, KEY_PERIOD, KEY_P   , KEY_Y   , KEY_F   , KEY_G   , KEY_C   , KEY_R   , KEY_L   , KEY_BACKSLASH },
   { KEY_NULL , KEY_A        , KEY_O    , KEY_E     , KEY_U   , KEY_I   , KEY_D   , KEY_H   , KEY_T   , KEY_N   , KEY_S   , KEY_NULL      },
   { KEY_NULL , KEY_SEMICOLON, KEY_Q    , KEY_J     , KEY_K   , KEY_X   , KEY_B   , KEY_M   , KEY_W   , KEY_V   , KEY_NULL, KEY_Z         },
   { KEY_TILDE, KEY_NULL     , KEY_NULL , KEY_NULL  , KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL      }
  },
  // Fn layout
  // Will not be using this FN layout
  {
   { KEY_ESC , KEY_1   , KEY_2   , KEY_3   , KEY_4   , KEY_5   , KEY_6   , KEY_7   , KEY_8    , KEY_9    , KEY_0    , KEY_LEFT_BRACE },
   { KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_SLASH, KEY_EQUAL, KEY_MINUS, KEY_NULL       },
   { KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL , KEY_NULL , KEY_NULL , KEY_RIGHT_BRACE},
   { KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL , KEY_NULL , KEY_NULL , KEY_NULL       }
  }
};
#endif

// TODO assign rowPins and colPins after wiring teensy 3.2 to keyboard
int rowPins[ROWS] = { 0, 23, 22, 20, 21, 17};
int colPins[COLS] = { 25, 26, 24, 28, 27, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 14, 15, 16, 18, 19 };

struct Key {
  int row;
  int col;
  int code;
};

struct Point {
  int r;
  int c;
};

struct Point keyToPoint(int code) {
  struct Point p;
  p.r = -1; p.c = -1;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (refCode[r][c] == code) {
        p.r = r; p.c = c;
      }
    }
  }
  return p;
}

// Key Scanning Algorithm
struct Key* readKey() {
  struct Key* result = (Key*)malloc(MAXIMUM_STROKES * sizeof(struct Key));
  for (int i = 0; i < MAXIMUM_STROKES; i++) {
    result[i].col = -1;
    result[i].row = -1;
    result[i].code = -1;
  }
  int cur = 0;

  for (int row = 0; row < ROWS; row++) {
    pinMode(rowPins[row], OUTPUT);
    digitalWrite(rowPins[row], LOW);
    for (int col = 0; col < COLS; col++) {
      if (digitalRead(colPins[col]) == LOW) {
        result[cur].row = row;
        result[cur].col = col;
        result[cur].code = col + row * 22;
        if (cur < MAXIMUM_STROKES) cur++;
      }
    }
    pinMode(rowPins[row], INPUT);
    digitalWrite(rowPins[row], LOW);
  }

  return result;
}

void setKey(int id, uint8_t code) {
  switch (id) {
  case 0: Keyboard.set_key1(code); break;
  case 1: Keyboard.set_key2(code); break;
  case 2: Keyboard.set_key3(code); break;
  case 3: Keyboard.set_key4(code); break;
  case 4: Keyboard.set_key5(code); break;
  case 5: Keyboard.set_key6(code); break;
  }
}

void submitLayout(struct Key* keys, uint8_t layout[ROWS][COLS]) {
  int modifiers = 0;
  int rolloverCount = 0;
  Keyboard.set_modifier(0);
  for (int i = 0; i < SUPPORTED_STROKES; i++) {
    setKey(i, 0);
  }
  for (int i = 0; i < SUPPORTED_STROKES; i++) {
    #ifdef USE_DVORAK
    if (keys[i].code == ARROW_UP_KEY) {
      Keyboard.set_key1(KEY_UP);
    }
    else if (keys[i].code == ARROW_DOWN_KEY) {
      Keyboard.set_key1(KEY_DOWN);
    }
    else if (keys[i].code == ARROW_LEFT_KEY) {
      Keyboard.set_key1(KEY_LEFT);
    }
    else if (keys[i].code == ARROW_RIGHT_KEY) {
      Keyboard.set_key1(KEY_RIGHT);
    }
    #endif
    if (keys[i].code == SUPER_KEY) {
      modifiers |= MODIFIERKEY_GUI;
    }
    else if (keys[i].code == RIGHT_SUPER_KEY) {
      modifiers |= MODIFIERKEY_RIGHT_GUI;
    }
    else if (keys[i].code == CTRL_KEY) {
      modifiers |= MODIFIERKEY_CTRL;
    }
    else if (keys[i].code == RIGHT_CTRL_KEY) {
      modifiers |= MODIFIERKEY_RIGHT_CTRL;
    }
    else if (keys[i].code == ALT_KEY) {
      modifiers |= MODIFIERKEY_ALT;
    }
    else if (keys[i].code == RIGHT_ALT_KEY) {
      modifiers |= MODIFIERKEY_RIGHT_ALT;
    }
    else if (keys[i].code == SHIFT_KEY) {
      modifiers |= MODIFIERKEY_SHIFT;
    }
    // mitchell addition
    else if (keys[i].code == RIGHT_SHIFT_KEY) {
      modifiers |= MODIFIERKEY_RIGHT_SHIFT;
    }
    
    else if (keys[i].code == BACKSPACE_KEY) {
      Keyboard.set_key1(KEY_BACKSPACE);
    }
    else if (keys[i].code == TAB_KEY) {
      Keyboard.set_key1(KEY_SPACE);
    }
    else if (keys[i].code == ENTER_KEY) {
      Keyboard.set_key1(KEY_ENTER);
    }
    else {
      if (keys[i].code != -1) {
        struct Point pos = keyToPoint(keys[i].code);
        int c = layout[pos.r][pos.c];
        if (c != KEY_NULL) {
          setKey(rolloverCount, c);
          rolloverCount++;
        }
      }
    }
  }
  if (modifiers) {
    Keyboard.set_modifier(modifiers);
  }
  Keyboard.send_now();
}

void keySubmit(struct Key* keys) {
  int layoutId = DEFAULT_LAYOUT;
  for (int i = 0; i < SUPPORTED_STROKES; i++) {
    if (keys[i].code == FN_KEY) {
      layoutId = FN_LAYOUT; break;
    }
  }
  submitLayout(keys, keyLayout[0]);
}

/* Life Cycle Functions */

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], INPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  
  for (int i = 0; i < COLS; i++) {
    pinMode(colPins[i], INPUT);
    digitalWrite(colPins[i], HIGH);
  }
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - lastFrame > DEBOUNCE_DELAY) {
    lastFrame = timeNow;
    struct Key* keys = readKey();
    if (keys[0].row != -1 && keys[0].col != -1) {
      keySubmit(keys);
    } else {
      Keyboard.set_modifier(0);
      for (int i = 0; i < SUPPORTED_STROKES; i++) {
        setKey(i, 0);
      }
      Keyboard.send_now();
    }
    free(keys);
  }
}
