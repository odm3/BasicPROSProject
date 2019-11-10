/****** 
 * 
 * deviceDefinitions.h is the header file where you declare all your motors, sensors, controllers, etc. 
 * Header files in C++ are used to define all constants, variables, and functions throughout the program. 
 * Because we plan on defining these definitions in one source file (deviceDefinitions.cpp), 
 * and using them elsewhere, we prefix the declaration with the "extern" keyword. 
 * 
 */

/**** Do not modify - Header Guard***/
#pragma once
#include "main.h"
/**********************/

// In main.h, we've uncommented the lines using namespace pros

// Declaring Motors - Modify the number and name as you need.
extern Motor motor1; 
extern Motor motor2;  
extern Motor motor3;  
extern Motor motor4;  
extern Motor motor5;  
extern Motor motor6;  
extern Motor motor7;  
extern Motor motor8; 


/****** Declaring Sensors
 * There are multiple sensor types in PROS. All fall under either Analog or Digital. A brief list of types includes: 
 * ADIDigitalOut, ADIDigitalIn, ADIAnalogOut, ADIAnalogIn, ADIPotentiometer, ADIEncoder, ADIGyro
 * They are declared similarly to motors; 
 *
 */

extern ADIPotentiometer pot;
extern ADIGyro gyro;
extern ADIEncoder enc;
extern ADIEncoder enc2;


/*** Declaring Controllers
 * A controller in PROS is declared using the Controller class. 
 */

extern Controller mainCtrl; 
extern Controller secondCtrl; 

/*** Other variables ** 
 * You can also declare additional variables in a header file
 */

extern int sampleVariable; 
extern bool toggle; 

/*** Functions ***
 * Functions can also be declared in header files, where you must also define the return type, name of the function,
 * and number and type of parameters. 
 */ 

extern void tank(bool partner = false); 
/*** We provide a default parameter, in this case whether or not to use the partner controller. 
 * Default parameters are called if you call a function with specifying a value ***/

/**
 * More default parameters here
 * bool partner - Indicates whether to use partner joystick
 */ 
extern void arcade(bool partner = false);
 