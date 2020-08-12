#include <AccelStepper.h>
#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo wrist_servo;               // Define any servo name
Servo claw_servo;

int wrist_servo_position = 0 ;
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

bool tool1_delivered = false;
bool tool1_grabbed = false;
bool tool2_delivered = false;
bool tool2_grabbed = false;
bool tool3_delivered = false;
bool tool3_grabbed = false;

void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(800);//1100
  stepper.setAcceleration(500);
  stepper.moveTo(-2000);
//
  stepper2.setMaxSpeed(500);//500
  stepper2.setAcceleration(500); //500
//  stepper2.moveTo(200); //800
  stepper2.moveTo(800);

//  stepper3.setMaxSpeed(800);//1100
//  stepper3.setAcceleration(500);
//  stepper3.moveTo(2000);

  claw_servo.attach (10);          // Define wrist signal pin
  wrist_servo.attach (9);
  wrist_servo.write(0);
    
}

void loop()
{ 
  stepper.run();
  
  if(stepper.distanceToGo() == 0 && !tool1_delivered && !tool2_delivered){
    stepper2.run();
    if (stepper2.distanceToGo() == 0){
    stepper.moveTo(-600);
    if(stepper.distanceToGo() == 0){
        claw_grab();
        claw_hold();
        stepper.moveTo(-2000);
        stepper2.moveTo( 0 );
        tool1_grabbed = true;
      }
    }
      if(stepper2.currentPosition() == 0 && tool1_grabbed == true){
        
        claw_release();
        tool1_grabbed = false;
        tool1_delivered = true;

        
      }
  }

  if(!tool2_delivered && tool1_delivered){
    stepper.moveTo(-2000);
    if(stepper.distanceToGo() == 0) {
        stepper2.moveTo(1000);
        stepper2.run();
        if (stepper2.distanceToGo() == 0){
        stepper.moveTo(-600);
        if(stepper.distanceToGo() == 0){
            claw_grab();
            claw_hold();
            stepper.moveTo(-2000);
            stepper2.moveTo( 0 );
            tool2_grabbed = true;
          }
          }
            if(stepper2.currentPosition() == 0 && tool2_grabbed == true){
              
              claw_release();
              tool2_grabbed = false;
              tool2_delivered = true;
            }
        }
  }
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


