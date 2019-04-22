#include <DHT.h>
#define dataPin 8

#define waterLevel A0

#define pResistor A1

//#define potPin A2

int applications = 3;

dht DHT;

void setup() {
  Serial.begin(9600);
  // lcd.begin(16,2);
  pinMode(waterLevel,INPUT);
  pinMode(pResistor,INPUT);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  int t = DHT.temperature;
  int h = DHT.humidity;
  
  int val = analogRead(waterLevel);
  float w = (val * 100) / 1024;
  
  float lux;
  luxmeter();

  // Scrolling screen for LCD
  /*
  int potValue = analogRead(potPin);
  float scrolldecide = 1024 / (applications - 1);
  */
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.print("Water Level: ");
  Serial.print(w);
  Serial.println("%");
  Serial.print("Luxmeters: ");
  Serial.print(lux);
  Serial.println(" lux");
  Serial.println("________________________");

  delay(1000);
}

float luxmeter(){
  int value = analogRead(pResistor);
  float lux = (1.25 * pow(10,7))*(pow(value,-1.4059));
  return lux;
}
