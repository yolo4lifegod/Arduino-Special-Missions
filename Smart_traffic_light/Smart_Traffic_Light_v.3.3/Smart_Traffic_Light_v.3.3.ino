#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 A0
#define COL_4 A1
#define COL_5 A2
#define COL_6 A3
#define COL_7 A4
#define COL_8 A5

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

byte S[] = {B11010000,B10010000,B01010110,B11010110,B00000000,B01000011,B11011011,B11011011};
byte O[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

#define triga 13
#define echoa 12

float cmpers, mpers, mph;
float disa, disb, n;
bool speeding, forward;

void setup(){
  Serial.begin(9600);
  pinMode(triga, OUTPUT);
  pinMode(echoa, INPUT);

  for (byte i = 2; i <= 11; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
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
  if(mph > 40){
    speeding == true;
  }else{
    speeding == false;
  }
  Serial.println(" mph");
  Serial.print("___________________");

  if(speeding == true){
    for(int j = 0; j <= 5; j++) {
      drawScreen(S);
      delay(500);
      drawScreen(O);
      delay(500);
    }
  }else{
    delay(100);
    drawScreen(O);
  }
  delay(100);
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
