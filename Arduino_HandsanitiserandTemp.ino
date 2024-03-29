#include <Servo.h>
#include "dht.h"
#define dht_apin A0
Servo servo1;
Servo servo2;
dht DHT;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
long t;
 
void setup() 
{
servo1.attach(7);
servo2.attach(4); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
  delay(1000);
 
}
 
void loop() {
  ultra();
  servo1.write(0);
  if(distance <= 15){
  servo1.write(90);
  delay(5);
  }

  DHT.read11(dht_apin);
  t=DHT.temperature;  
  //delay(2000);
  servo2.write(0);
  Serial.println(t);
  if(t>28)
  {
   servo2.write(90); 
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