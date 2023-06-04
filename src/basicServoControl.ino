#include "Servo.h"


#define DEBUG 1
#define RUNNING_TIME 8000
#define TOP_SPEED 255

#define SERVO_PAN   9
#define SERVO_TILT 10


Servo panServo;
Servo tiltServo;
int tSangle = 0;
int pSangle = 100;

char serialBuffer[4];

void setup() {
    Serial.begin(9600);
    
    panServo.attach(SERVO_PAN);
    tiltServo.attach(SERVO_TILT);
    
     panServo.write(pSangle);
     tiltServo.write(tSangle);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'w') {
      tSangle += 20;
    } else if (input == 's') {
      tSangle -= 20;
    } else if (input == 'd') {
      pSangle += 20;
    } else if (input == 'a') {
      pSangle -= 20;
    } else if (input == 'r') {
      pSangle = 100;
      tSangle = 0;
    }
    // Limit servo angle between 0 and 180 degrees
    tSangle = constrain(tSangle, 0, 100);
    pSangle = constrain(pSangle, 0, 180);

    tiltServo.write(tSangle);  // Set servo position
    panServo.write(pSangle);  // Set servo position
  }




}
