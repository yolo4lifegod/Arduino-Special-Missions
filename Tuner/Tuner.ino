/*
 * Created by Yash Saxena
 * Circuited by Ryan Campo
 * Microphone: https://randomnerdtutorials.com/guide-for-microphone-sound-sensor-with-arduino/
 * Tuning Notes: https://www.seventhstring.com/resources/notefrequencies.html
 */

#define BUTTON_PIN 5

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = 7; // Tuning Microphone
int microfeed = 0;
int piezoPin = 8; // Tuner
int potPin = 6; // Potentiometer
int val = 0;

boolean butpres = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sensorPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(sensorPin, LOW);
  digitalWrite(piezoPin, LOW);
  digitalWrite(potPin, LOW);
  digitalWrite(BUTTON_PIN, LOW);
}

void loop() {
  butpres = read_button();
}
