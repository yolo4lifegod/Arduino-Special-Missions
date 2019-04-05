#include <DHT_U.h>
#define dataPin 8
dht DHT;

#define waterLevel A0

#define pResistor A1

void setup() {
  Serial.begin(9600);
  pinMode(waterLevel,INPUT);
  pinMode(pResistor,INPUT);
}

void loop() {
  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;

  int val = analogRead(waterLevel);
  float w = (val * 100) / 1024;

  int value = analogRead(pResistor);
  luxmeter(value);

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

  delay(1000);
}

float luxmeter(a){
  lux = (1.25 * pow(10,7))*(pow(a,-1.4059))
  return lux;
}
