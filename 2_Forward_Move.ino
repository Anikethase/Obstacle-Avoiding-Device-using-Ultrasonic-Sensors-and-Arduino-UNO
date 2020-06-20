


/* Date : Aug 24, 2019
 *  Program for Move the Robot to forward as well as Backward Direction....
 */


#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
 #include<Servo.h>

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
     digitalWrite(LED, OFF);   //  OFF = LOW = 0
     delay(1000);              //  2000 ms = 2000*10^-3 = 2 sec

     digitalWrite(LED, ON);    //  ON = HIGH = 1
     delay(2000);

     digitalWrite(forwardLeft, ON);
     digitalWrite(forwardRight, ON);   
     digitalWrite(reverseLeft, OFF);                    // move forward
     digitalWrite(reverseRight, OFF);
  }
