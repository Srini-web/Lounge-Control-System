#include <LiquidCrystal.h>  

int Contrast=40;
int trigPin = 10;
int echoPin = 7;
int c=0;
long duration,inches;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

 void setup()
 { 
    // Serial.begin(9600);
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  }  
     void loop()
 {  


     pinMode(trigPin, OUTPUT);
 digitalWrite(trigPin, LOW);
 delay(2);
 digitalWrite(trigPin, HIGH);
 delay(10);
 digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  inches = (duration/2) / 74;
  
  if ((inches>=1)&&(inches<= 10)) 
 { 
   
   c++;
   delay(1000);
  //Serial.println(c);
    
  }
     if(c>=5)
     {
     lcd.setCursor(0, 0);
     lcd.print("No Entry");}
    
    lcd.setCursor(0, 1);
     lcd.print(c);
     delay(10);
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
