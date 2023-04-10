#include <Servo.h>
Servo servo1;

int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
 
void setup() 
{
servo1.attach(7);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);

 
}
 
void loop() {
  ultra();
  servo1.write(0);
  if(distance <= 15){
  servo1.write(90);
  delay(5);
  }

 
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
