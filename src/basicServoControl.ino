#include "Servo.h"


#define DEBUG 1
#define RUNNING_TIME 8000
#define TOP_SPEED 255

#define SERVO_PAN   9
#define SERVO_TILT 10


Servo panServo;
Servo tiltServo;
int pSangle = 0;
int tSangle = 0;

char serialBuffer[4];

void setup() {
    Serial.begin(115200);
    
    panServo.attach(SERVO_PAN);
    tiltServo.attach(SERVO_TILT);
    
     panServo.write(pSangle);
     tiltServo.write(tSangle);
}
void loop() {
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'u') {  // Move servo up
      pSangle += 10;
    } else if (input == 'd') {  // Move servo down
      pSangle -= 10;
    }

    // Limit servo angle between 0 and 180 degrees
    pSangle = constrain(pSangle, 20, 160);

    panServo.write(pSangle);  // Set servo position
  }
}
