#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// LCD PinOut (RS, E, D4, D5, D6, D7)

int potPina = 2;
int potPinb = 3;
int vala = 0;
int valb = 0;
int setvala = 0;
int setvalb = 0;
int c = 0;
int f = 32;
int i = 1;

int ctof(){
  setvala = (valb * 1.8) + 32;
  return setvala;
}

int ftoc(){
  setvalb = (vala - 32) / 1.8;
  return setvalb;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  vala = analogRead(potPina) - 512;
  valb = analogRead(potPinb) - 512;

  lcd.setCursor(0, 0);
  lcd.print(vala);
  lcd.setCursor(3, 0);
  lcd.print("C = ");
  lcd.setCursor(7, 0);
  f = ctof()
  lcd.print(f);
  lcd.setCursor(10, 0);
  lcd.print("F");

  lcd.setCursor(0, 1);
  lcd.print(valb);
  lcd.setCursor(3, 1);
  lcd.print("F = ");
  lcd.setCursor(7, 1);
  c = ftoc()
  lcd.print(c);
  lcd.setCursor(10, 1);
  lcd.print("C");

  delay(1000);
  lcd.clear();
}
