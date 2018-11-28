/*************************************************
* Created by Yash Saxena
* To access Keypad library by Chris--A: https://github.com/Chris--A/Keypad
* Description: To solve square matrices where one can input any number through a number pad
*************************************************/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Keypad.h>
const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );



int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i = 0;
int sola, solb, solc;

int j = 0;
int u = 0;
int v = 0;
int w = 0;

int detsolve, detx, dety, detz;

void digitcalc(j) {
  int u = keypad.waitForKey();
  Serial.println(u);
  Serial.print(" ");
  lcd.setCursor(0, 0)
  lcd.print(u);
  int v = keypad.waitForKey();
  Serial.println(v);
  Serial.print(" ");
  lcd.setCursor(1, 0)
  lcd.print(v);
  int w = keypad.waitForKey();
  Serial.println(w);
  Serial.print(" ");
  lcd.setCursor(2, 0)
  lcd.print(w);

  j = (u*100) + (v*10) + w;
  delay(10); // to control overdrive of arduino
  lcd.clear();
}

void solve(l, m, n, o, p, q, r, s, t, sold, sole, solf) {
  /************
   * |l m n|
   * |o p q|
   * |r s t|
   ************/
  detsolve = ((l*o*p)+(m*q*r)+(n*o*s))-((n*p*r)+(m*o*t)+(l*q*s));
  if(detsolve == 0){
    lcd.print("No solution");
  }else{
    /**********
     * |sold m n|
     * |sole p q|
     * |solf s t|
     **********/
    
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  digitcalc(a);
  digitcalc(b);
  digitcalc(c);
  digitcalc(d);
  digitcalc(e);
  digitcalc(f);
  digitcalc(g);
  digitcalc(h);
  digitcalc(i);
  digitcalc(sola);
  digitcalc(solb);
  digitcalc(solc);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
