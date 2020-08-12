// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@open.com.au)
// Copyright (C) 2009 Mike McCauley
// $Id: HRFMessage.h,v 1.1 2009/08/15 05:32:58 mikem Exp mikem $

#include <AccelStepper.h>

//AccelStepper stepper; // Defaults to 4 pins on 2, 3, 4, 5
//AccelStepper stepper2 = AccelStepper(4, 22, 24, 26, 28);
AccelStepper stepper3 = AccelStepper(4, 34, 36, 38, 40);

void setup()
{  
//   stepper.setSpeed(100);
//   stepper2.setSpeed(50);	
   stepper3.setSpeed(50); 
}

void loop()
{  
//   stepper.runSpeed();
//   stepper2.runSpeed();
   stepper3.runSpeed();
}
