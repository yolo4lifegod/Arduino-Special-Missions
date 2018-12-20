/*******************************************************
 * Locater using an Ultrasonic sensor and a Servo Motor
 * Created by Yash Saxena
 * To conv. from polar to cartesian: https://github.com/sdumetz/coordinates
 *******************************************************/

#define triggerpin 6
#define echopin 7
int maxdist = 200; // In centimeters. Change this to change range

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);
  Serial.print("  Polar  | Cartesian");
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1){
    long dur, dist;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    dur = pulseIn(echoPin, HIGH);
    dist = (dur / 2) / 29.1;
    if (dist <= 100) {
      Serial.println("(");
      Serial.print(dist);
      Serial.print(", ");
      Serial.print(pos);
      Serial.print(")");
    }
  }
}
