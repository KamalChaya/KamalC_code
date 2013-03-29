 int position;

#define TRAYPOS_MAX 190
#define TRAYPOS_MIN 6

#define RACK_POS    1
#define SCORE_POS   2

#define TRAYBOTTOM_OPEN_POS  170
#define TRAYBOTTOM_CLOSE_POS 55

#define RACK_ARM_POS  2570
#define RACK_TRAY_POS 65
#define SCORE_ARM_POS 4146
#define SCORE_TRAY_POS 50
#define TRAY_RESET_POS 190





void RotateTraySmooth(unsigned int ServoPos)

{

     if ((ServoPos > TRAYPOS_MAX) ||
      (ServoPos < TRAYPOS_MIN) )
      return;

		  servoTarget[tray1] = ServoPos;
		  servoTarget[tray2] = ServoPos;
		  servoTarget[tray3] = ServoPos;
		  servoTarget[tray4] = ServoPos;
		  while(ServoValue[tray1] != ServoPos)
		  {
		    nxtDisplayTextLine(4, "Pos:%d Srv:%d", ServoPos,ServoValue[tray1]);
		    wait1Msec(10);
		  }


    //wait1Msec(500);
}

/*
Function: OpenTrayBottom()
Description: opens the bottom of the tray.
parameters: none
returns: none
*/
void OpenTrayBottom()
{
  ServoRotate(traybottom, TRAYBOTTOM_OPEN_POS);
}

/*
Function: CloseTrayBottom()
Description: closes the bottom of the tray.
parameters: none
returns: none
*/
void CloseTrayBottom()
{
  ServoRotate(traybottom, TRAYBOTTOM_CLOSE_POS);
}

/*
Function: ResetArm()
Description:
Brings the arm Down untill touch port 1 is pressed. This is the arms reset position.
This helps us to stay within the robot size constraints.

parameters: none
returns: none
*/
void ResetArm()

{
  //power motors towards the ground.
  motor[ArmMotor2] = -15;
  motor[ArmMotor1] = -15;
  //wait until touch port 1 is pressed.
  WaitForTouchPressed(1);
  //stop the motors.
  motor[ArmMotor2] = 0;
  motor[ArmMotor1] = 0;
  //reset motor encoder values to 0.
  nMotorEncoder[ArmMotor2] = 0;
  nMotorEncoder[ArmMotor1] = 0;

}

/*
Function: ResetTray()
Description:
Move the tray upwards so that when it comes down to the arms reset position, it will be parallel
to ground. This helps us to stay within the robot size constraints.
parameters: none
returns: none
*/

void ResetTray()
/*Move the tray upwards so that when it comes down to the arms reset position, it will be parallel
to ground. This helps us to stay within the robot size constraints.  */
{
  //Close the tray bottom.
  CloseTrayBottom();

  //move the servo up so the tray is parallel to the ground relative to the arm position.
  RotateTraySmooth(TRAY_RESET_POS);
}



/*
Function: ResetScoringMachine()
Description: Resets the arm and the tray to the front of the robot..
parameters: none
returns: none
*/
void ResetScoringMachine()
{
  //first, reset the tray, so that it will not hit anything on its way down.
  ResetTray();
  //then, reset the arm.
  ResetArm();
  //Set the position value as 1. A position value of one corresponds to the reset value of the
  position = 1;
}


/*
Function: ArmToPosition()
Description:
Brings the arm to rack position or scoring position
parameters:
position: what position we want the arm to go to, rack or scoring.
returns: none
*/
void ArmToPosition(unsigned int Position)
{
  int targetVal =0;

  // calculate incremental target postition
  switch(Position)
  {
    case RACK_POS:
      targetVal = RACK_ARM_POS - nMotorEncoder[ArmMotor2];
      break;
    case SCORE_POS:
      targetVal = SCORE_ARM_POS - nMotorEncoder[ArmMotor2];
      break;
    default:

  }
  //nxtDisplayTextLine(5, "tv:%d, nME:%d", targetVal,nMotorEncoder[ArmMotor2]);
  //Move the arm up to Rack Position.
  nMotorEncoderTarget[ArmMotor2]= targetVal;
  nMotorEncoderTarget[ArmMotor1]= targetVal;
  //power the motor
  if(targetVal > 0)
  {
    motor[ArmMotor2] = 50;
    motor[ArmMotor1] = 50;
  }
  else
  {
    motor[ArmMotor2] = -22;
    motor[ArmMotor1] = -22;
  }

  //Wait until the motors stop moving
  while ( (nMotorRunState[ArmMotor2] != runStateIdle) ||
          (nMotorRunState[ArmMotor1] != runStateIdle) )

  {
    //nxtDisplayTextLine(5, " E2:%d", nMotorEncoder[ArmMotor2]);

    wait1Msec(30);
  }
  motor[ArmMotor2]=0;
  motor[ArmMotor1]=0;
}

/*
Function: ArmToRackPosition()
Description: Brings arm to rack position
parameters: none
returns: none
*/
void ArmToRackPosition()
{
  ArmToPosition(RACK_POS);
}

/*
Function: ArmToScoringPosition()
Description: Brings arm to scoring position
parameters: none
returns: none
*/
void ArmToScoringPosition()
{
  ArmToPosition(SCORE_POS);
}

/*
Function: TrayToRackPosition
Description: Brings tray to rack position
parameters: none
returns: none
*/
void TrayToRackPosition()
{
  //move the tray up so that its parallel when the arm is in rack position.
  RotateTraySmooth(RACK_TRAY_POS);
}

/*
Function: TrayToScoringPosition()
Description: Brings tray to scoring position
parameters: none
returns: none
*/
void TrayToScoringPosition()
{
  RotateTraySmooth(SCORE_TRAY_POS);
}

/*
Function: ScoringMachineToScoringPosition()
Description: Brings arm and tray to scoring position.
parameters: none
returns: none
*/
void ScoringMachineToScoringPosition()
{
  //move the arm up alittle bit
  motor[ArmMotor1] = 40;
  motor[ArmMotor2] = 40;
  wait1Msec(250);
  //Bring the tray to scoring position
  TrayToScoringPosition();
  //bring the arm to scoring position
  ArmToScoringPosition();

  position = 3;
}

/*
Function: ScoringMachineToRackPosition()
Description: Brings arm and tray to rack position.
parameters: none
returns: none
*/
void ScoringMachineToRackPosition()
{

  //Move the arm up first before tray, so tray does not hit sides of robot.
  ArmToRackPosition();
  //Move tray up so its parallel to the ground.
  TrayToRackPosition();
  //Set the position value as 2.
  position = 2;
}

/*
Task: TrayToScoringPositionTask()
Description: Moves the tray to rack position. The reason we made this as a task is because in autonomous mode,
we want to raise the arm and the tray up to scoring position at the same time, so we made the tray run in
its own task and the arm run in the main task. this way both tasks would be running at the same time.
parameters: none
returns: none
*/
task TrayToScoringPositionTask()
{
  TrayToScoringPosition();
}

/*
Task: TrayToScoringPositionTask()
Description: Brings the arm and tray up to scoring position at the same time in autonomous mode.
parameters: none
returns: none
*/
void ScoringMachineToScoringPositionInAutonomousMode()
{

  //Moves the arm up a little so that the tray wont hit the ground when we move the tray to scoring position.
  motor[ArmMotor2] = 20;
  motor[ArmMotor1] = 20;
  wait10Msec(50);

  //move the tray to scoring position
  StartTask(TrayToScoringPositionTask)

  //move the arm to scoring position.
  ArmToScoringPosition();
}
