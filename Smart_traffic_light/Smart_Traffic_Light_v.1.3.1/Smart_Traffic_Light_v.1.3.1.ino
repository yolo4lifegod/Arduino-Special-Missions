#include <NewPing.h>

#define trig 5
#define echo 6
#define dist 100

#define reda 7
#define redb 8
#define yela 9
#define yelb 10
#define grea 11
#define greb 12

int i = 0;
float discheck = 0;

NewPing sonar(trig, echo, dist);

void setup() {
  Serial.begin(115200);

  pinMode(trig,OUTPUT);
  pinMode(echo,OUTPUT);
  
  pinMode(reda,OUTPUT);
  pinMode(redb,OUTPUT);
  pinMode(yela,OUTPUT);
  pinMode(yelb,OUTPUT);
  pinMode(grea,OUTPUT);
  pinMode(greb,OUTPUT);
}

void loop() {
  delay(5000);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  discheck = sonar.ping_cm();
  if(discheck <= 100){
    trafficset();
  }else{
    redlight();
    greenlight();
  }

}

void trafficset(){
  digitalWrite(reda,LOW);
  digitalWrite(redb,HIGH);
  digitalWrite(yela,LOW);
  digitalWrite(yelb,LOW);
  digitalWrite(grea,HIGH);
  digitalWrite(greb,LOW);

  delay(5000);
}

void redlight(){
  digitalWrite(reda,HIGH);
  digitalWrite(redb,LOW);
  digitalWrite(yela,LOW);
  digitalWrite(yelb,LOW);
  digitalWrite(grea,LOW);
  digitalWrite(greb,HIGH);
  delay(25000);

  digitalWrite(greb,LOW);
  i = 0;
  while(i < 5){
    digitalWrite(yelb,HIGH);
    delay(500);
    digitalWrite(yelb,LOW);
    i = i + 1;
    delay(500);
  }

  digitalWrite(redb,HIGH);
  delay(2000);
}

void greenlight(){
  digitalWrite(reda,LOW);
  digitalWrite(redb,HIGH);
  digitalWrite(yela,LOW);
  digitalWrite(yelb,LOW);
  digitalWrite(grea,HIGH);
  digitalWrite(greb,LOW);
  delay(25000);

  digitalWrite(grea,LOW);
  i = 0;
  while(i < 5){
    digitalWrite(yela,HIGH);
    delay(500);
    digitalWrite(yela,LOW);
    i = i + 1;
    delay(500);
  }

  digitalWrite(reda,HIGH);
  delay(2000);
}
