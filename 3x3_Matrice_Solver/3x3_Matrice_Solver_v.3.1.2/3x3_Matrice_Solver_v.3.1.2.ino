#include <BasicLinearAlgebra.h>
using namespace BLA;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <IRremote.h>
const int irRecievePin = A0; // pin connected to the output of the IR detector
const int ledPin = 9; // LED is connected to a PWM pin
const int numberOfKeys = 10; // 10 keys are learned (0 through 9)
long irKeyCodes[numberOfKeys]; // holds the codes for each key
IRrecv irrecv(irReceivePin); // create the IR library
decode_results results; // IR data goes here

int potPin = 2;
int a;

float X = 0;
float Y = 0;
float Z = 0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(irReceivePin, INPUT);
  irrecv.enableIRIn(); // Start the IR receiver
  learnKeycodes(); // learn remote control key codes
  
  BLA::Matrix<a,a> A;
  BLA::Matrix<a> B;
  BLA::Matrix<a,a> C;
  BLA::Matrix<a,1> D;
}
