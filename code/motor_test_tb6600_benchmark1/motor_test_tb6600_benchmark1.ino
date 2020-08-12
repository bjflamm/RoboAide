#include <AccelStepper.h>


// Define a stepper motor 1 for arduino 
// PRISMATIC 1 - BLUE
// direction Digital 6 (CW), pulses Digital 7 (CLK)
AccelStepper stepper(1, 7, 6);

// Define a stepper motor 1 for arduino 
// ROTATIONAL - YELLOW
// direction Digital 2 (CW), pulses Digital 3 (CLK)
AccelStepper stepper2(1, 3, 2);

// Define a stepper motor 1 for arduino 
// PRISMATIC 2 - RED
// direction Digital 11 (CW), pulses Digital 12 (CLK)
AccelStepper stepper3(1, 12, 11);
void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(1100);//1100
  stepper.setAcceleration(500);
  stepper.moveTo(1200);
//
  stepper2.setMaxSpeed(200);//1100
  stepper2.setAcceleration(300);
  stepper2.moveTo(450);

//  stepper3.setMaxSpeed(1100);//1100
//  stepper3.setAcceleration(500);
//  stepper3.moveTo(500);
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0){
      delay(100);
      stepper.moveTo( -stepper.currentPosition() );
      delay(100);

    }

    stepper.run();

    
//
    if (stepper2.distanceToGo() == 0){
      delay(100);
      stepper2.moveTo( -stepper2.currentPosition() );
      delay(100);
    }

    
    stepper2.run();
//
}


//if (stepper3.distanceToGo() == 0){
//
//      stepper3.moveTo( -stepper3.currentPosition() );
//
//    }
//    
//    stepper3.run();
//}

//}
