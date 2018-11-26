// #include <LiquidCrystal.h>
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int trigPin = 6;
int echoPin = 7;
int buzzer = 2;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  long dur, dist;
  digitalWrite(trigPin, LOW);
  delay(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  dur = pulseIn(echoPin, HIGH);
  dist = (dur/2) / 29.1;

  int thisPitch = map(distance, 0, 135, 2500, 50);
  tone(buzzer, thisPitch, 10);
  Serial.print(distance);
  Serial.print(" cm ");
  Serial.print(thisPitch);
  Serial.println("Hz");
  delay(50);

  if(dist > 0){
    digitalWrite(8, HIGH);
  }else{
    digitalWrite(8, LOW);
  }

  if(dist > 10){
    digitalWrite(9, HIGH);
  }else{
    digitalWrite(9, LOW);
  }

  if(dist > 20){
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);
  }

  if(dist > 30){
    digitalWrite(11, HIGH);
  }else{
    digitalWrite(11, LOW);
  }
  
  if(dist > 40){
    digitalWrite(12, HIGH);
  }else{
    digitalWrite(12, LOW);
  }
  
if(dist > 50){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}
