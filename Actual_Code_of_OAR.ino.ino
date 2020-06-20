

/* Date :  Nov 4, 2019
 *  Program for avoid the Obstacle using arduino UNO and Ultrasonic Sensor...
 */


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

     delay(random(500,2000));   // delay for random time
     Serial.begin(9600);    //  Used to open serial port speed is in bits per seconds..
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
           digitalWrite(forwardRight, LOW);  // For Stoping the Robo              
           digitalWrite(reverseRight, LOW);
           digitalWrite(forwardLeft, LOW);                                
           digitalWrite(reverseLeft, LOW);

           digitalWrite(LED, ON);    //  ON = HIGH = 1
           delay(200);

           digitalWrite(LED, OFF);   //  OFF = LOW = 0
           
            Serial.println("Distance Less than 20 cm");
            
            delay(500);
            digitalWrite(forwardRight, LOW);      // Move Backword         
            digitalWrite(reverseRight, HIGH);
            digitalWrite(forwardLeft, LOW);                                
            digitalWrite(reverseLeft, HIGH);
            delay(500);
            
            digitalWrite(forwardRight, LOW);  // Stop                
            digitalWrite(reverseRight, LOW);
            digitalWrite(forwardLeft, LOW);                                
            digitalWrite(reverseLeft, LOW);  
            delay(100);  
            
            digitalWrite(forwardRight, HIGH);       
            digitalWrite(reverseRight, LOW);    // Turn on Right side..
            digitalWrite(forwardLeft, LOW);                                 
            digitalWrite(reverseLeft, LOW);  
            delay(500);

        /*   digitalWrite(forwardRight, LOW);       
            digitalWrite(reverseRight, LOW);    // T
            urn on Left side..
            digitalWrite(forwardLeft, HIGH);                                 
            digitalWrite(reverseLeft, LOW);  
            delay(500);*/
        }
  }

   
