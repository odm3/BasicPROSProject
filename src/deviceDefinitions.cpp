/********
 * deviceDefinitions.cpp - This is where all the variables and functions declared in the previous file 
 * are defined here, so that they can be used in other functions. 
 */ 

/** Defining Motors *
 * 
 * There are multiple ways to define motors. We can use a formal constructor for them, 
 * Use a literal definition for them, or just apply a number to define the port they use. 
 */ 

/** Constructor method 
 * There a variety of constructors to declare motors. 
 * 1. Motor motorName (port #, Motor gearset, reverse? (T/F), Encoder Units)
 * 2. Motor motorName (port #, reverse? (T/F) ) Gearset defaults to Green - 200 RPM 
 * 3. Motor motorName( port #, gearset)
 * 5. Motor motorName( port# )
 * Port reversal can also be indicated by applying a (-) sign to the number. 
 */

/*** Do not modfify, this includes file is necessary **/
#include "deviceDefinitions.h"

/****************************/

Motor motor1(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor motor2(2, true);
Motor motor3(3, MOTOR_GEARSET_36); 
Motor motor4(4);
Motor motor5 (5);
Motor motor6 (6);
Motor motor7 (7);
Motor motor8 (-8); // Using minus sign to indicate reverse the direction. 

/*** Declaring sensors *****
 * Sensors are declared by indicate the port they occupy, which can be a Number 1-8, or char 'A' - 'H'
 * If you're using Quadrature Encoders, the valid pairings for ports are {1,2}, {3,4}, {5,6}, {7,8}
 */

 ADIPotentiometer pot('A');
 // We can define the gyro here, but this will begin a 1 second calibration. It's better to call this from the initialize function in main.cpp
 // ADIGyro gyro(2);
 ADIEncoder enc(3, 4); 
 // You can also reverse encoders if necessary. 
 ADIEncoder enc2('E', 'F', true);

 /*** Defining Controllers *
  * Defining controllers are simple. If you're using a secondary controller, you must indicate that it is a partner controller.
  */

 Controller mainCtrl(CONTROLLER_MASTER); 
 Controller secondCtrl(CONTROLLER_PARTNER);

// Defining variables 
 int sampleVariable = 1;
 bool toggle = false;

 /** Defining Functions 
  * You flesh out the function definition in cpp files
  */

 void tank(bool partner) {
     if(!partner) {
        motor1 = mainCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        motor2 = mainCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y); 
     } else {
        motor1 = secondCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        motor2 = secondCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y); 
     }
 }

 void arcade(bool partner) {
     if(!partner){
         motor1 = mainCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) + mainCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
         motor2 = mainCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) - mainCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
     } else {
         motor1 = secondCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) + secondCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
         motor2 = secondCtrl.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) - secondCtrl.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
     }
 }




