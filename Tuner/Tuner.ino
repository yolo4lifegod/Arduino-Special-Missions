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
int pval = 0;
int condval = 0;
int notenum = 0;
int chromatic = 1;

String note;
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
  butpres = read_button(BUTTON_PIN);
  Serial.println("_________");
  Serial.println(butpres);
  
  pval = analogRead(potPin) / 96;
  Serial.println(pval);
  
  notenum = pval % 12;
  Serial.println(note);
  
  chromatic = (pval - note) / 12;
  Serial.println(chromatic);
  
  Serial.println("_________");
  
  lcd.setCursor(1, 0);
  while(butpres == 1){
    if(chromatic == 1){
      if(notenum == 0){
        note = "C";
      }elif(notenum == 1){
        note = "C#";
      }elif(notenum == 2){
        note = "D";
      }elif(notenum == 3){
        note = "Eb";
      }elif(notenum == 4){
        note = "E";
      }
    }
  }
}
