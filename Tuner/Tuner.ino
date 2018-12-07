/*
 * Created by Yash Saxena
 * Circuited by Ryan Campo
 * Serial Monitor is useful for experimental environments.
 * Runs only concert pitches.
 * Microphone: https://randomnerdtutorials.com/guide-for-microphone-sound-sensor-with-arduino/
 * Tuning Notes: https://www.seventhstring.com/resources/notefrequencies.html
 */

#define BUTTON_PIN 5

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = 7; // Tuning Microphone
int microfeed = 0;
int piezoPin = 8; // Tuner
int buzzval = 0;
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
  if(chromatic == 1){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 2){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 3){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 4){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 5){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb"; 
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 6){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
      }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
        lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 7){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
        note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
      }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }
   }
   if(chromatic == 8){
     if(notenum == 0){
       lcd.setCursor(1, 0);
       note = "C";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
       buzzval = 32.70;
     }elif(notenum == 1){
       lcd.setCursor(1, 0);
       note = "C#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 2){
       lcd.setCursor(1, 0);
       note = "D";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 3){
       lcd.setCursor(1, 0);
       note = "Eb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 4){
       lcd.setCursor(1, 0);
       note = "E";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 5){
       lcd.setCursor(1, 0);
       note = "F";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 6){
       lcd.setCursor(1, 0);
       note = "F#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 7){
       lcd.setCursor(1, 0);
       note = "G";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum == 8){
       lcd.setCursor(1, 0);
       note = "G#";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 9){
       lcd.setCursor(1, 0);
       note = "A";
       lcd.print(note);
       lcd.setCursor(4, 0);
        lcd.print(chromatic);
     }elif(notenum = 10){
       lcd.setCursor(1, 0);
       note = "Bb";
       lcd.print(note);
       lcd.setCursor(4, 0);
       lcd.print(chromatic);
     }elif(notenum = 11){
       lcd.setCursor(1, 0);
       note = "B";
       lcd.print(note);
       lcd.setCursor(4, 0);
      lcd.print(chromatic);
    }
  }
  while(butpres == 1){
    
  }
}
