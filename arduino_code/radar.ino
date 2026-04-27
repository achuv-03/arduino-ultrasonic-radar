#include <Servo.h>

Servo myServo;

int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  myServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (int angle = 15; angle <= 165; angle++) {
    myServo.write(angle);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);

    delay(40);
  }

  for (int angle = 165; angle >= 15; angle--) {
    myServo.write(angle);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);

    delay(40);
  }
}
