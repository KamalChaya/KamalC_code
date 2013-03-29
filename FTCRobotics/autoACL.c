#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S2,     Touch,               sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     rightm,        tmotorNormal, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftm,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    trapdoor,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    hoop,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    lefthook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_6,    claws,                tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

// Our Includes

#define MIN_POWER 20


#include "joysticklib.c"

#include "servolib.c"
#include "drivelibrary.c"
#include "armjoysticktest.c"
#include "Initialize.c"


void StopAllMotors()
{
  motor[leftm] = 0;
  motor[rightm] = 0;
  motor[arm] = 0;
}


task main()
{
  initializeRobotAuto();
  waitForStart();

  // turn towards rolling goal
  spinAntiClockWise(40, 500);

  // move forward towards goal
  moveFwd(50, 4850);

  // back little bit
  moveBwd(50,1250);

  // turn towards bridge
  spinAntiClockWise(80,4800);

  //move across
  moveBwd(80,10100);

  StopAllTasks();
  //stop all the motors from moving.
  StopAllMotors();

}
