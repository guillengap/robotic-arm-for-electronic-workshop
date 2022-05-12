#include <Servo.h>

Servo myservo1;  // create servo1 object to control a servo1
Servo myservo2;  // create servo2 object to control a servo2
Servo myservo3;  // create servo3 object to control a servo3
Servo myservo4;  // create servo4 object to control a servo4
Servo myservo5;  // create servo5 object to control a servo5
Servo myservo6;  // create servo6 object to control a servo6

#define RED 22     
#define BLUE 24     
#define GREEN 23
#define LED_PWR 25

int pos1 = 90;    // variable to store the servo1 position - front
int pos2 = 90;    // variable to store the servo2 position - vertical
int pos3 = 90;    // variable to store the servo3 position - vertical
int pos4 = 150;   // variable to store the servo4 position - vertical
int pos5 = 90;    // variable to store the servo5 position - vertical
int pos6 = 20;    // variable to store the servo6 position - gripper close

const int buttonPin1 = 4;     // the number of the pushbutton pin
const int buttonPin2 = 7;     // the number of the pushbutton pin
const int buttonPin3 = 8;     // the number of the pushbutton pin
const int buttonPin4 = 12;    // the number of the pushbutton pin
const int buttonPin5 = 13;    // the number of the pushbutton pin
const int buttonPin6 = 2;     // the number of the pushbutton pin

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;         // variable for reading the pushbutton status
int buttonState5 = 0;         // variable for reading the pushbutton status
int buttonState6 = 0;         // variable for reading the pushbutton status

void setup() {
  myservo1.attach(3);  // attaches the servo on pin 3 to the servo object
  myservo2.attach(5);  // attaches the servo on pin 5 to the servo object
  myservo3.attach(6);  // attaches the servo on pin 3 to the servo object
  myservo4.attach(9);  // attaches the servo on pin 3 to the servo object 
  myservo5.attach(10); // attaches the servo on pin 3 to the servo object 
  myservo6.attach(11); // attaches the servo on pin 3 to the servo object

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);  

// intitialize the digital Pin as an output
pinMode(RED, OUTPUT);
digitalWrite(RED, LOW);
  
pinMode(BLUE, OUTPUT);
digitalWrite(BLUE, LOW);

pinMode(GREEN, OUTPUT);
digitalWrite(GREEN, LOW);

pinMode(LED_PWR, OUTPUT);
digitalWrite(LED_PWR, LOW);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);

  // check if the button is is HIGH:
  if (buttonState1 == HIGH) {
    // MOVE THE OBJECT (BOX)
    digitalWrite(LED_PWR, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);    
    digitalWrite(RED, HIGH);
    for (pos1 = 90; pos1 <= 180; pos1 += 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    } 
    for (pos2 = 90; pos2 >= 75; pos2 -= 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 90; pos3 <= 120; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 20; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    for (pos4 = 150; pos4 <= 165; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos6 = 100; pos6 >= 30; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    } 
    delay(100);
    for (pos4 = 165; pos4 >= 90; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    for (pos1 = 180; pos1 >= 35; pos1 -= 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos4 = 90; pos4 <= 160; pos4 += 1) { // servo4 
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos6 = 30; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);          
    for (pos4 = 160; pos4 >= 120; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos1 = 35; pos1 <= 90; pos1 += 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos4 = 120; pos4 <= 150; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 120; pos3 >= 50; pos3 -= 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos2 = 75; pos2 <= 90; pos2 += 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 50; pos3 <= 90; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 100; pos6 >= 20; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    digitalWrite(RED, LOW);
    delay(10);
 
  } else if (buttonState2 == HIGH) {
    // RETURN THE OBJECT (BOX)
    digitalWrite(LED_PWR, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, HIGH);    
    for (pos1 = 90; pos1 >= 35; pos1 -= 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos2 = 90; pos2 >= 75; pos2 -= 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 90; pos3 <= 120; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 20; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    for (pos4 = 150; pos4 <= 165; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos6 = 100; pos6 >= 30; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    } 
    delay(100);
    for (pos4 = 165; pos4 >= 90; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos1 = 35; pos1 <= 180; pos1 += 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos4 = 90; pos4 <= 160; pos4 += 1) { // servo4 
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos6 = 30; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);          
    for (pos4 = 160; pos4 >= 120; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos1 = 180; pos1 >= 90; pos1 -= 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos4 = 120; pos4 <= 150; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 120; pos3 >= 50; pos3 -= 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos2 = 75; pos2 <= 90; pos2 += 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 50; pos3 <= 90; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 100; pos6 >= 20; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    digitalWrite(RED, LOW);
    delay(10);
    
  } else if (buttonState3 == HIGH) {
    // MOVE THE BOARD
    digitalWrite(LED_PWR, LOW);
    digitalWrite(RED, LOW); 
    digitalWrite(BLUE, LOW);       
    digitalWrite(GREEN, HIGH);
    for (pos1 = 90; pos1 <= 180; pos1 += 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    } 
    for (pos2 = 90; pos2 >= 75; pos2 -= 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 90; pos3 <= 110; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 20; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    delay(100);
    for (pos5 = 90; pos5 <= 180; pos5 += 1) { // servo5
      myservo5.write(pos5);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    delay(100);
    for (pos6 = 100; pos6 >= 15; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    } 
    delay(100);
    digitalWrite(GREEN, LOW);    
    
  } else if (buttonState4 == HIGH) {
    // RETURN THE BOARD
    digitalWrite(LED_PWR, LOW);
    digitalWrite(RED, LOW); 
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, HIGH);    
    for (pos4 = 150; pos4 <= 180; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos6 = 15; pos6 <= 100; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    delay(100);
    for (pos4 = 180; pos4 >= 150; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos5 = 180; pos5 >= 90; pos5 -= 1) { // servo5
      myservo5.write(pos5);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos1 = 180; pos1 >= 90; pos1 -= 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 110; pos3 >= 50; pos3 -= 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos2 = 75; pos2 <= 90; pos2 += 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 50; pos3 <= 90; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
      for (pos6 = 100; pos6 >= 20; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    digitalWrite(GREEN, LOW);
    delay(10);
    
  } else if (buttonState5 == HIGH) {
    // MOVE THE BOTTLE WITH WATER
    digitalWrite(LED_PWR, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    for (pos6 = 20; pos6 <= 75; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    for (pos4 = 150; pos4 >= 50; pos4 -= 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos2 = 90; pos2 >= 55; pos2 -= 1) { // servo2
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 90; pos3 <= 155; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);         
    for (pos6 = 75; pos6 >= 35; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos3 = 155; pos3 >= 130; pos3 -= 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos1 = 90; pos1 <= 170; pos1 += 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos5 = 90; pos5 >= 0; pos5 -= 1) { // servo5
      myservo5.write(pos5);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    delay(3000);
    for (pos5 = 0; pos5 <= 90; pos5 += 1) { // servo5
      myservo5.write(pos5);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }     
    delay(50);
    digitalWrite(BLUE, LOW);

  } else if (buttonState6 == HIGH) {
    // RETURN THE BOTTLE WITH WATER
    digitalWrite(LED_PWR, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    for (pos1 = 170; pos1 >= 90; pos1 -= 1) { // servo1
      myservo1.write(pos1);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 130; pos3 <= 150; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }          
    for (pos6 = 35; pos6 <= 75; pos6 += 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(30);             // waits 25ms for the servo to reach the position
    }
    delay(100);
    for (pos3 = 150; pos3 >= 50; pos3 -= 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }   
    for (pos2 = 55; pos2 <= 90; pos2 += 1) { // servo2 
      myservo2.write(pos2);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos4 = 50; pos4 <= 150; pos4 += 1) { // servo4
      myservo4.write(pos4);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos3 = 50; pos3 <= 90; pos3 += 1) { // servo3
      myservo3.write(pos3);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }
    for (pos6 = 75; pos6 >= 20; pos6 -= 1) { // servo6
      myservo6.write(pos6);    // tell servo to go to position in variable 'pos'
      delay(25);             // waits 25ms for the servo to reach the position
    }       
    digitalWrite(BLUE, LOW);
    delay(10);

  } else  {
    // END
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);    
    digitalWrite(LED_PWR, HIGH);    
    delay(10);
  }          
}
