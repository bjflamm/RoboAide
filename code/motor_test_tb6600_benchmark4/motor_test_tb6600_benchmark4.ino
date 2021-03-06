#include <AccelStepper.h>
#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo wrist_servo;               // Define any servo name
Servo claw_servo;

int wrist_servo_position = 180 ;
int claw_servo_position = 0 ;


// Define a stepper motor 1 for arduino 
// PRISMATIC 1 - BLUE
// direction Digital 6 (CW), pulses Digital 7 (CLK)
AccelStepper stepper(1, 7, 6);

// Define a stepper motor 1 for arduino 
// ROTATIONAL - YELLOW
// direction Digital 2 (CW), pulses Digital 3 (CLK)
AccelStepper stepper2(1, 12, 11);

// Define a stepper motor 1 for arduino 
// PRISMATIC 2 - RED
// direction Digital 11 (CW), pulses Digital 12 (CLK)
AccelStepper stepper3(1, 3, 2);
bool tool_delivered = false;

void setup()
{  
  stepper.setMaxSpeed(800);//1100
  stepper.setAcceleration(500);
//  stepper.moveTo(-900); //-1000 for classroom table

  stepper2.setMaxSpeed(500);//500
  stepper2.setAcceleration(500); //500
  stepper2.moveTo(800); //800

  stepper3.setMaxSpeed(800);//1100
  stepper3.setAcceleration(500);
  stepper3.moveTo(2000);

  claw_servo.attach (10);          // Define wrist signal pin
  wrist_servo.attach (9);
  wrist_servo.write(180);
}

void loop()
{ 
  stepper.moveTo(-2000);
  
  
  if(stepper.distanceToGo() == 0){
    if (stepper2.distanceToGo() == 0){
      if(tool_delivered != true){
        claw_grab();
        claw_hold();
      }
      
      stepper2.moveTo( 0 );
//      delay(5000);
      claw_release();
//   
      tool_delivered = true;

      }
      
     
  }
  stepper.run();
  stepper2.run();
  stepper.moveTo(0);

 }
 

void claw_grab(){

 for (claw_servo_position = 0; claw_servo_position <=180; claw_servo_position +=1){

    claw_servo.write(claw_servo_position);
    delay(10);
  }
}

void claw_hold(){
  claw_servo.write(180);
}

void claw_release(){
  claw_servo.write(0);
}


