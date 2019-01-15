#include <Servo.h>

#define trigPina 2
#define echoPina 3
#define trigPinb 4
#define echoPinb 5

float x = 0;
float y = 0;
float a = 0;
float b = 0;
float d = 0;
float e = 0;
float theta = 0;
float alpha = 0;
float beta = 0;

float pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164;

Servo delvalle_servo;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPina, OUTPUT);
  pinMode(echoPina, INPUT);
  pinMode(trigPinb, OUTPUT);
  pinMode(echoPinb, INPUT);
  
  delvalle_servo.attach(6);
  delvalle_servo.write(0);
}

void loop() {
  long dura, disa, durb, disb;
  scan();
  if(disa >= 45 || disb >= 45){
    scan();
  }
  Serial.println(disa);
  Serial.println(disb);
  theta = double acos(0-(((y^2)-(x^2)-(25.5^2))/(51*x)));
  a = x * sin(theta*180/pi);
  a = a*180/pi;
  d = double sqrt((x^2) - (a^2));
  e = 12.75 - d;
  b = double sqrt((a^2) + (e^2));
  beta = atan(a/e);
  beta = beta*180/pi;

  delvalle_servo.write(beta);
  delay(500);

  Serial.println("__________________________");
  Serial.println(x);
  Serial.println(y);
  Serial.println(theta);
  Serial.println(a);
  Serial.println(d);
  Serial.println(e);
  Serial.println(b);
  Serial.println(beta);
  Serial.println("__________________________");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* solutions are in radian
  By- ABHILASH PATEL
*/
float asin(float c){
  float out;
  out= ((c+(c*c*c)/6+(3*c*c*c*c*c)/40+(5*c*c*c*c*c*c*c)/112+
  (35*c*c*c*c*c*c*c*c*c)/1152 +(c*c*c*c*c*c*c*c*c*c*c*0.022)+
  (c*c*c*c*c*c*c*c*c*c*c*c*c*.0173)+(c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*.0139)+
  (c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*0.0115)+(c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*0.01)
   ));

                                           //asin
if(c>=.96 && c<.97){out=1.287+(3.82*(c-.96)); }
if(c>=.97 && c<.98){out=(1.325+4.5*(c-.97));}          // arcsin
if(c>=.98 && c<.99){out=(1.37+6*(c-.98));}
if(c>=.99 && c<=1){out=(1.43+14*(c-.99));}  
return out;}

float acos(float c)
{float out;
out=asin(sqrt(1-c*c));
return out;}

float atan(float c)
{float out;
out=asin(c/(sqrt(1+c*c)));
return out;}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void scan(){
  long dura, disa, durb, disb;
  
  // a ultrasonic
  digitalWrite(trigPina, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPina, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPina, LOW);
  dura = pulseIn(echoPina, HIGH);
  disa = (dura/2) / 29.1;
  
  // b ultrasonic
  digitalWrite(trigPinb, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinb, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinb, LOW);
  durb = pulseIn(echoPinb, HIGH);
  disb = (durb/2) / 29.1;
  
  x = disa;
  y = disb;
}
