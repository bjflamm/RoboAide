#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_StepperMotor *myMotor = AFMS.getStepper(513, 1);


void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");

  AFMS.begin();
  myMotor->setSpeed(5);
}    

void loop() {
  myMotor->step(100, FORWARD, SINGLE); 
}
