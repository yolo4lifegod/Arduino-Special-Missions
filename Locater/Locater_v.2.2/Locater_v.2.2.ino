#include <Servo.h>
#include <math.h>

#define trigPina 2
#define echoPina 3
#define trigPinb 4
#define echoPinb 5

float x = 0.0;
float y = 0.0;
float a = 0.0;
float b = 0.0;
float c = 0.0;
float d = 0.0;
float e = 0.0;
float l = 0.0;
float m = 0.0;
float n = 0.0;
float theta = 0.0;
float alpha = 0.0;
float beta = 0.0;
float dura = 0.0;
float durb = 0.0;
float disa = 0.0;
float disb = 0.0;

const float pi = 3.14159265358979;

Servo myservo;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPina, OUTPUT);
  pinMode(echoPina, INPUT);
  pinMode(trigPinb, OUTPUT);
  pinMode(echoPinb, INPUT);
  
  myservo.attach(6);
  myservo.write(90);
  delay(1000);
}
/////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  scan();
  delay(1000);
}

/////////////////////////////////////////////////////////////////// FUNCTIONS /////////////////////////////////////////////////////////////////////////////////////////////

// Absolute error <= 6.7e-5
float acos(float h) {
  float negate = float(h < 0);
  h = abs(h);
  float ret = -0.0187293;
  ret = ret * h;
  ret = ret + 0.0742610;
  ret = ret * h;
  ret = ret - 0.2121144;
  ret = ret * h;
  ret = ret + 1.5707288;
  ret = ret * sqrt(1.0-h);
  ret = ret - 2 * negate * ret;
  return negate * pi + ret;
}

void scan(){
  long dura, disa, durb, disb;
  
  // a ultrasonic
  digitalWrite(trigPina, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPina, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPina, LOW);
  dura = pulseIn(echoPina, HIGH);
  disa = (dura/2) / 29.1;
  
  // b ultrasonic
  digitalWrite(trigPinb, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinb, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPinb, LOW);
  durb = pulseIn(echoPinb, HIGH);
  disb = (durb/2) / 29.1;
  
  Serial.print("disa = ");
  Serial.println(disa);
  Serial.print("disb = ");
  Serial.println(disb);
  
  delay(100);
  
  ///////////////////////////////////////////////////////////
  
  l = pow(disb,2);
  m = pow(disa,2);
  c = pow(25.5,2);
  
  // Solve for Theta
  
  n = 0-((l-m-c)/(51*disa));
  theta = acos(n);
  
  //////////////////
  
  l = (theta * 180) / pi;
  n = sin(l);
  a = disa * n;
  a = a*180/pi;
  Serial.println(a);
  
  l = pow(disa,2);
  m = pow(a,2);
  n = l - m;
  d = sqrt(n);
  e = 12.75 - d;
  l = pow(a,2);
  m = pow(e,2);
  n = l + m;
  b = sqrt(n);
  
  n = a / e;
  beta = atan(n);
  beta = (beta * 180) / pi;

  myservo.write(beta);
  delay(5000);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  Serial.println("__________________________");
  Serial.println(disa);//
  Serial.println(disb);//
  Serial.println(theta);//
  Serial.println(c);//
  Serial.println(a);//
  Serial.println(d);
  Serial.println(e);
  Serial.println(b);
  Serial.println(beta);
  Serial.println("__________________________");
  Serial.print("(");
  Serial.println(a);
  Serial.println(",");
  Serial.println(e);
  Serial.println(")");
}
