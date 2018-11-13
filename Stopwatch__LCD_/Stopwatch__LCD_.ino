#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// LCD PinOut (RS, E, D4, D5, D6, D7)

void setup() {
 int sec = millis()/1000;
 int milli = millis();
 int minu = millis()/60000;
 lcd.begin(16, 2); // Tell the dimansions of hte LCD
 // Print a message to the LCD.
 lcd.print("Stopwatch");
}

void loop() {
 int sec = millis()/1000;
 int minu = millis()/60000;
 // set the cursor to column 0, line 1
 // (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(0, 1);
 // print the number of minutes since reset:
 lcd.print(minu);
 lcd.setCursor(3, 1);
 lcd.print(".");
 lcd.setCursor(4, 1);
 lcd.print(sec);
 lcd.setCursor(7, 1);
 lcd.print(".");
 lcd.setCursor(8, 1);
 lcd.print(millis());
}
 
