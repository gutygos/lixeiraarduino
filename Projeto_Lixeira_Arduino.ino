 
#include <Servo.h>                       
#include <Ultrasonic.h>                  
#define echoPin 13                 
#define triggerPin 12                    
 
Servo myservo ;                         
Ultrasonic ultrasonic(12,13);            
 
void setup()
{
  Serial.begin(9600);                      
  pinMode(triggerPin, OUTPUT);           
  pinMode(echoPin, INPUT);             
  myservo.attach(9) ;                    
 
void loop()                            
{
 
  digitalWrite(triggerPin, LOW);          
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);         
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);          
  long duration = pulseIn(echoPin, HIGH);   
  int cm = microsecondsToCentimeters(duration);   
  Serial.println(cm);                     
  
  if(cm <= 30 && cm >=5)                  
  {
       abreTampa();                       
       fechaTampa();                    
 
  }
}
 
void abreTampa()                          
{
    myservo.write(180);
    delay(2000);
}
 
void fechaTampa()                       
{
  myservo.write(0);
  delay(1000);
}
 
float microsecondsToCentimeters(long microseconds)           
{
  float seconds = (float) microseconds / 1000000.0;
  float distance = seconds * 340;
  distance = distance / 2;
  distance = distance * 100;
  return distance;
}
