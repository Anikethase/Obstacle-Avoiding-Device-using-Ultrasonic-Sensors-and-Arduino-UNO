

/* Date : Aug 10, 2019
 *  Program for Blink the LED or to test the Arduino is properly Worked or not...
 */

 
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
 #include<Servo.h>

int LED = 13;   //  This is nothing but LED_BULLTIN...
int ON = 1;
int OFF = 0;

int forwardRight = 7;      //Forward motion of Right motor
int reverseRight = 6;        //Reverse motion of Right motor
int forwardLeft = 4;       //Forward motion of Left motor
int reverseLeft = 5;        //Reverse motion of Left motor


void setup()
  {
     pinMode(LED, OUTPUT);  //  Set pinMode for Blink a LED give an output to pin 13
     
  }


  void loop() 
  {
     digitalWrite(LED, OFF);   //  OFF = LOW = 0
     delay(1000);              //  2000 ms = 2000*10^-3 = 2 sec

     digitalWrite(LED, ON);    //  ON = HIGH = 1
     delay(2000);

  }
