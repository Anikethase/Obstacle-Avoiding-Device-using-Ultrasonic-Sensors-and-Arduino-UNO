
/* Date : Sep 07, 2019 Oct 23, 2019
 *  Program for Stop the Robot when Obstacle is Detect...
 */


#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
#include<Servo.h>      // This is the library for Servo Motor...

#define trigPin A0     // trig pin of HC-SR04
#define echoPin A1     // Echo pin of HC-SR04

int LED = 13;   //  This is nothing but LED_BULLTIN...
int ON = 1;
int OFF = 0;

int forwardRight = 7;      //Forward motion of Right motor
int reverseRight = 6;        //Reverse motion of Right motor
int forwardLeft = 4;       //Forward motion of Left motor
int reverseLeft = 5;        //Reverse motion of Left motor

double duration;
double distance;

void setup()
  {
     pinMode(LED, OUTPUT);  //  Set pinMode for Blink a LED give an output to pin 13


    delay(random(500,2000));   // delay for random time
      Serial.begin(9600);
      
     // set Motor pins as output
     
     pinMode(forwardRight, OUTPUT);
     pinMode(reverseRight, OUTPUT);
     pinMode(forwardLeft, OUTPUT);
     pinMode(reverseLeft, OUTPUT);

     pinMode(trigPin, OUTPUT);         // set trig pin as output
     pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  }


  void loop() 
  {

      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);   
      digitalWrite(trigPin, HIGH);     // send waves for 10 us
      delayMicroseconds(10);


      duration = pulseIn(echoPin, HIGH); // receive reflected waves
      distance = duration / 54;   // convert to distance
      delay(10);

      if (distance > 20)            
       {
          Serial.println(distance);
          digitalWrite(forwardRight, HIGH);                    // move forward
          digitalWrite(reverseRight, LOW);
          digitalWrite(forwardLeft, HIGH);                                
          digitalWrite(reverseLeft, LOW);   

          Serial.println("Distance Greater than 20 cm");
        }
        
     if (distance < 20)
      {
          Serial.println(distance);
          digitalWrite(forwardRight, LOW);  //Stop                
          digitalWrite(reverseRight, LOW);
          digitalWrite(forwardLeft, LOW);                                
          digitalWrite(reverseLeft, LOW);
          delay(500);

          Serial.println("Distance Less than 20 cm");
        }

  }
