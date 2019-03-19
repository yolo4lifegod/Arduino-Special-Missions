#define triga 12
#define echoa 11

float cmpers, mpers, mph;
float disa, disb, n;
bool speeding, forward;

void setup(){
  Serial.begin(9600);
  pinMode(triga, OUTPUT);
  pinMode(echoa, INPUT);
}

void loop(){
  disa = scan();
  Serial.println(disa);
  Serial.println(" cm ; ");
  Serial.print("disa");
  delay(100);
  disb = scan();
  Serial.println(disb);
  Serial.println(" cm ; ");
  Serial.print("disb");
  
  n = disa - disb;
  Serial.println(n);
  Serial.print(" diff");
  
  cmpers = n * 10;
  
  if(mpers < 0){
    forward = true;
  }
  if(mpers > 0){
    forward = false;
  }
  if(mpers = 0){
    forward = false;
  }
  
  Serial.print(cmpers);
  Serial.println(" cm/h");
  
  mpers = cmpers / 100;
  Serial.print(mpers);
  Serial.println(" m/s ; ");
  if(forward = true){
    Serial.print("forward");
  }else{
    Serial.print("backward");
  }
  mph = mpers * 2.2369;
  Serial.print(mph);
  Serial.println(" mph");
  Serial.print("___________________");
  delay(500);
}

float scan(){
  long durationb, distanceb;
  digitalWrite(triga,LOW);
  delayMicroseconds(2);
  digitalWrite(triga,HIGH);
  delayMicroseconds(10);
  digitalWrite(triga,LOW);
  durationb = pulseIn(echoa,HIGH);
  distanceb = durationb * 34 / 2000;
  return distanceb;
}

/*
const uint64_t IMAGES[] = {
  0xc3810000000081c3,
  0x813c7e7e7e7e3c81
};
const int IMAGES_LEN = sizeof(IMAGES)/8;
*/
