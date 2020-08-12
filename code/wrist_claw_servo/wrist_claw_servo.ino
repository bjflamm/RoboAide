#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo wrist_servo;               // Define any servo name
Servo claw_servo;

int wrist_servo_position = 0 ;
int claw_servo_position = 0 ;

void setup() {
  
wrist_servo.attach (10);          // Define wrist signal pin
claw_servo.attach (9);

}

void loop() {
 for (wrist_servo_position = 0; wrist_servo_position <=180; wrist_servo_position +=1){

    wrist_servo.write(wrist_servo_position);
    delay(10);
  }

  for (wrist_servo_position=180; wrist_servo_position >= 0; wrist_servo_position -=1){

    wrist_servo.write(wrist_servo_position);
    delay(10);
  }

 for (claw_servo_position = 0; claw_servo_position <=180; claw_servo_position +=1){

    claw_servo.write(claw_servo_position);
    delay(10);
  }

  for (claw_servo_position=180; claw_servo_position >= 0; claw_servo_position -=1){

    claw_servo.write(claw_servo_position);
    delay(10);
    
  }
  
}

void hook_rotation() {
  
}

