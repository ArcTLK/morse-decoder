#include <LiquidCrystal.h>

const int sensorPin = 8;
unsigned long previousMillis = 0;
const long interval = 60;

unsigned short input[5] = {0, 0, 0, 0, 0};
unsigned short inputIndex = 0;

unsigned int touchCount = 0;
unsigned int noTouchCount = 0;
bool noTouchTriggered = true;
unsigned short chars = 0;
char state[10];

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(sensorPin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (digitalRead(sensorPin) == HIGH) {
      touchCount++;
      if (noTouchCount > 20 && !noTouchTriggered) {
        //logic
        if (input[0] == 2 && input[1] == 2 && input[2] == 2 && input[3] == 2 && input[4] == 2) lcd.print("0");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 2 && input[3] == 2 && input[4] == 1) lcd.print("9");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 2 && input[3] == 1 && input[4] == 1) lcd.print("8");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 1 && input[3] == 1 && input[4] == 1) lcd.print("7");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 1 && input[3] == 1 && input[4] == 1) lcd.print("6");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 1 && input[4] == 1) lcd.print("5");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 1 && input[4] == 2) lcd.print("4");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 2 && input[4] == 2) lcd.print("3");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 2 && input[3] == 2 && input[4] == 2) lcd.print("2");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 2 && input[3] == 2 && input[4] == 2) lcd.print("1");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 1 && input[3] == 1 && input[4] == 0) lcd.print("Z");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 2 && input[3] == 2 && input[4] == 0) lcd.print("Y");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 1 && input[3] == 2 && input[4] == 0) lcd.print("X");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 2 && input[3] == 0 && input[4] == 0) lcd.print("W");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 2 && input[4] == 0) lcd.print("V");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 2 && input[3] == 0 && input[4] == 0) lcd.print("U");
        else if (input[0] == 2 && input[1] == 0 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("T");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 0 && input[4] == 0) lcd.print("S");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 1 && input[3] == 0 && input[4] == 0) lcd.print("R");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 1 && input[3] == 2 && input[4] == 0) lcd.print("Q");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 2 && input[3] == 1 && input[4] == 0) lcd.print("P");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 2 && input[3] == 0 && input[4] == 0) lcd.print("O");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("N");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("M");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 1 && input[3] == 1 && input[4] == 0) lcd.print("L");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 2 && input[3] == 0 && input[4] == 0) lcd.print("K");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 2 && input[3] == 2 && input[4] == 0) lcd.print("J");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("I");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 1 && input[3] == 1 && input[4] == 0) lcd.print("H");
        else if (input[0] == 2 && input[1] == 2 && input[2] == 1 && input[3] == 0 && input[4] == 0) lcd.print("G");
        else if (input[0] == 1 && input[1] == 1 && input[2] == 2 && input[3] == 1 && input[4] == 0) lcd.print("F");
        else if (input[0] == 1 && input[1] == 0 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("E");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 1 && input[3] == 0 && input[4] == 0) lcd.print("D");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 2 && input[3] == 1 && input[4] == 0) lcd.print("C");
        else if (input[0] == 2 && input[1] == 1 && input[2] == 1 && input[3] == 1 && input[4] == 0) lcd.print("B");
        else if (input[0] == 1 && input[1] == 2 && input[2] == 0 && input[3] == 0 && input[4] == 0) lcd.print("A");
        input[0] = 0;
        input[1] = 0;
        input[2] = 0;
        input[3] = 0;
        input[4] = 0;
        inputIndex = 0;
        chars++;
        noTouchTriggered = true;
      }
      else {
        noTouchCount = 0;
        noTouchTriggered = false;
      }
    }
    else {
      noTouchCount++;
      if (touchCount > 8) {
         if (inputIndex < 5) input[inputIndex++] = 2;
         touchCount = 0;
      }
      else if (touchCount > 1) {
        if (inputIndex < 5) input[inputIndex++] = 1;
        touchCount = 0;
      }
    }
    if (chars >= 16) {
      lcd.clear();
      chars = 0;
    }
    //display current input
    lcd.setCursor(0, 1);
    sprintf(state, "%c%c%c%c%c",
    input[0] == 1 ? '.' : input[0] == 2 ? '_' : ' ',
    input[1] == 1 ? '.' : input[1] == 2 ? '_' : ' ',
    input[2] == 1 ? '.' : input[2] == 2 ? '_' : ' ',
    input[3] == 1 ? '.' : input[3] == 2 ? '_' : ' ',
    input[4] == 1 ? '.' : input[4] == 2 ? '_' : ' ');
    lcd.print(state);
    lcd.setCursor(chars, 0);
  }
}
