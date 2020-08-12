#include <Wire.h>
#include <Adafruit_MotorShield.h>
 
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);
 
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
 
  myMotor->setSpeed(10);  // 10 rpm   
 
  myMotor->step(100, FORWARD, SINGLE); 
  myMotor->release();
  delay(1000);
}
 
void loop() {
  myMotor->step(100, FORWARD, SINGLE); 
  myMotor->step(100, BACKWARD, SINGLE); 
 
  myMotor->step(100, FORWARD, DOUBLE); 
  myMotor->step(100, BACKWARD, DOUBLE);
 
  myMotor->step(100, FORWARD, INTERLEAVE); 
  myMotor->step(100, BACKWARD, INTERLEAVE); 
 
  myMotor->step(100, FORWARD, MICROSTEP); 
  myMotor->step(100, BACKWARD, MICROSTEP); 
}
