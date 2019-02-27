#define trigPin 5
#define echoPin 6

#define reda 7
#define redb 8
#define yela 9
#define yelb 10
#define grea 11
#define greb 12

int i = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  pinMode(reda,OUTPUT);
  pinMode(redb,OUTPUT);
  pinMode(yela,OUTPUT);
  pinMode(yelb,OUTPUT);
  pinMode(grea,OUTPUT);
  pinMode(greb,OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 34 / 2000;
  
  Serial.print(distance);
  Serial.println(" cm; ");
  
  if(distance <= 100){
    Serial.println("trafficset()");
    trafficset();
  }else{
    Serial.println("normal routine");
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
  Serial.print("redlight");
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
  Serial.print("greenlight");
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
