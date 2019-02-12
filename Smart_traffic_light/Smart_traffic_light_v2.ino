#include<hcsr04>

// include the NewPing library: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
#include<NewPing.h>
#define SONAR_NUM 2

// Ultrasonic Ports
#define tria 3
#define echa 4
#define trib 5
#define echb 6

// Traffic Light Ports
#define reda 7
#define redb 8
#define yela 9
#define yelb 10
#define grea 11
#define greb 12

int i = 0;
double float disa = 201;
double float disb = 201;

NewPing sonar[SONAR-NUM} = {
  NewPing(3, 4, 200), 
  NewPing(5, 6, 200)
};

void setup() {
  Serial.begin(115200);

  pinMode(tria,OUTPUT);
  pinMode(echa,INPUT);
  pinMode(trib,OUTPUT);
  pinMode(echb,INPUT);
  
  pinMode(reda,OUTPUT);
  pinMode(redb,OUTPUT);
  pinMode(yela,OUTPUT);
  pinMode(yelb,OUTPUT);
  pinMode(grea,OUTPUT);
  pinMode(greb,OUTPUT);
}


void loop() {
  for (uint8_t i < SONAR_NUM; i++) {
    
  /*
   * scana();
   * scanb();
   */
  if(disa <= 200 && disb > 200) {
    trafficseta();
  }else if(disa > 200 && disb <= 200) {
    trafficsetb();
  }else{
    norm();
  }
}

void scana(){
  NewPing(tria,echa,300);
  disa = sonar.ping_cm();
}

void scanb(){
  NewPing(trib,echb,300);
  disb = sonar.ping_cm();
}

void norm(){
  while(i != 25){
    digitalWrite(reda,HIGH);
    digitalWrite(redb,LOW);
    digitalWrite(yela,LOW);
    digitalWrite(yelb,LOW);
    digitalWrite(grea,LOW);
    digitalWrite(greb,HIGH);
    delay(1000);
    i = i + 1;
  }

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

  /////////////////////////////////////////////////////////////////////
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

void trafficseta(){
  digitalWrite(reda,LOW);
  digitalWrite(redb,HIGH);
  digitalWrite(yela,LOW);
  digitalWrite(yelb,LOW);
  digitalWrite(grea,HIGH);
  digitalWrite(greb,LOW);

  delay(5000);
}

void trafficsetb(){
  digitalWrite(reda,HIGH);
  digitalWrite(redb,LOW);
  digitalWrite(yela,LOW);
  digitalWrite(yelb,LOW);
  digitalWrite(grea,LOW);
  digitalWrite(greb,HIGH);

  delay(5000);
}
