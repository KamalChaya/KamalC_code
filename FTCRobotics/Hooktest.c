#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S2,     Touch,               sensorTouch)
#pragma config(Sensor, S3,     HTGYRO,              sensorNone)
#pragma config(Sensor, S4,     HTMAG,               sensorNone)
#pragma config(Motor,  motorA,          lamp,          tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     rightm,        tmotorNormal, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftm,         tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    trapdoor,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    hoop,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    lefthook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_6,    claws,                tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//#include "joysticklib.c"

#include "servolib.c"
#include "ArmLib.c"

//This program is to test the arm
task main()
{
  //reset the trapdoor
  ResetTrapdoor();
  //ResetArm();
  CLAWS_STOP

  while (true)
  {
    //If the right button is pressed on the nxt, move the arm up
    if(nNxtButtonPressed == 1)
      ResetHooks();
    //If the left button is pressed on the nxt, move the arm down
    else if(nNxtButtonPressed == 2)
      LowerHooks();
    //If no buttons on the NXT are pressed, dont move the arm
    else if(nNxtButtonPressed == -1)
      //motor[arm] = 0;
    wait1Msec(10);

  }

}


/*
 * $Id: HTGYRO-test1.c 20 2009-12-08 22:59:13Z xander $
 */
