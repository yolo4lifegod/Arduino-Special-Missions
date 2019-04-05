#include <DHT_U.h>
#define dataPin 8
dht DHT;

#define waterLevel A0

void setup() {
  Serial.begin(9600);
  pinMode(waterLevel,INPUT);
}

void loop() {
  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;

  int val = analogRead(waterLevel);
  float w = (val * 100) / 1024;

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.print("Water Level = ");
  Serial.print(w);
  Serial.print("%");

  delay(1000);
}
