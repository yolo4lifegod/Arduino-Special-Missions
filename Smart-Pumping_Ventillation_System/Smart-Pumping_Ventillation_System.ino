// Graph to find luxmeter: https://www.allaboutcircuits.com/projects/design-a-luxmeter-using-a-light-dependent-resistor/


#include <DHT_U.h>
#define dataPin 8
dht DHT;

#define waterLevel A0

#define pResistor A1
/*
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
*/
#define potPin A2

int applications = 3;

void setup() {
  Serial.begin(9600);
  // lcd.begin(16,2);
  pinMode(waterLevel,INPUT);
  pinMode(pResistor,INPUT);
}

void loop() {
  // Applications
  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;

  int val = analogRead(waterLevel);
  float w = (val * 100) / 1024;

  int value = analogRead(pResistor);
  luxmeter(value);

  // Scrolling screen for LCD
  int potValue = analogRead(potPin);
  float scrolldecide = 1024 / (applications - 1);
  
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println(" *C ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.print("Water Level = ");
  Serial.print(w);
  Serial.println("%");
  Serial.print("Luxmeters = ");
  Serial.print(lux);
  Serial.println(" lux");
  Serial.println("________________________");

  for(int i = 0; i <= (applications - 1); i++){
    if(potValue < (i*scrolldecide)){
      int decider = i
    }
  }

  delay(1000);
}

float luxmeter(a){
  lux = (1.25 * pow(10,7))*(pow(a,-1.4059))
  return lux;
}
