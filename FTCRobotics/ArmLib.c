
#define lowheight 250
#define middleheight 4000
#define highheight 6440
#define scoreheight 8800

#define CLAWS_STOP        servo(claws)=127;
#define CLAWS_ROTATE_FWD  servo(claws)=256;
#define CLAWS_ROTATE_REV  servo(claws)=0;

bool gHookInResetPos = false;
bool ArmBusy = false;

void WaitForArm()
{
  while(ArmBusy)
  {
    wait1Msec(10);
  }
}
void SetArmBusy()
{
  ArmBusy = true;
}

void SetArmIdle()
{
  ArmBusy = false;
}

void MoveArm(int power)
{
    WaitForArm();
    SetArmBusy();
    motor[arm] = power;
}
void StopArm()
{
  SetArmIdle();
  motor[arm]=0;
}


void ResetTrapdoor()
{
  ServoRotate(trapdoor,52);
}

void ResetHoop()
{
   //while touch sensor is pressed, operate the hoop
    if(gHookInResetPos == false)
    {
      ServoRotate(hoop, 30, 15);
      gHookInResetPos = true;
  }
}

void LowerHoop()
{
  if(gHookInResetPos == true)
  {
    ServoRotate(hoop, 255, 4);
    gHookInResetPos = false;
  }
}

void ResetArm()
{
  //while touch sensor isn't pressed, move the arm down until it is pressed, so the arm stops.
  while(SensorValue[Touch]==0)
	{
		motor[arm] = -30;
	}
	motor[arm]=0;
	//reset the encoder value when the arm is reset.
	nMotorEncoder[arm]=0;
}

// Thread Safe version of Reset Arm
void ResetArmEx()
{
    WaitForArm();
    SetArmBusy();

	  //while touch sensor isn't pressed, move the arm down until it is pressed, so the arm stops.
	  while(SensorValue[Touch]==0)
		{
		  	motor[arm] = -30;
		}
		StopArm();
		//reset the encoder value when the arm is reset.
		nMotorEncoder[arm]=0;

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
    case lowheight:
      targetVal = lowheight - nMotorEncoder[arm];
      break;
    case middleheight:
      targetVal = middleheight - nMotorEncoder[arm];
      break;
    case highheight:
      targetVal = highheight - nMotorEncoder[arm];
      break;
    case scoreheight:
      targetVal = scoreheight - nMotorEncoder[arm];
      break;
    default:

  }
  nxtDisplayTextLine(2, "tv:%d, nME:%d", targetVal,nMotorEncoder[arm]);
  //Move the arm up to Rack Position.
  //nMotorEncoderTarget[arm]= targetVal;

  //power the motor
  if(targetVal > 0)
  {
    motor[arm] = 100;

  }
  else
  {
    motor[arm] = -22;

  }

  //Wait until the motors stop moving
  //while ( (nMotorRunState[arm] != runStateIdle) )
  while( nMotorEncoder[arm] < targetVal)
  {
    wait1Msec(10);
  }
  motor[arm]=0;

  wait1Msec(1000);
}

/*
Function: ArmToPositionEx()
Description:
Brings the arm to rack position or scoring position - Thread Safe version
parameters:
position: what position we want the arm to go to, rack or scoring.
returns: none
*/
void ArmToPositionEx(unsigned int Position)
{
  int targetVal =0;

  // calculate incremental target postition
  switch(Position)
  {
    case lowheight:
      targetVal = lowheight - nMotorEncoder[arm];
      break;
    case middleheight:
      targetVal = middleheight - nMotorEncoder[arm];
      break;
    case highheight:
      targetVal = highheight - nMotorEncoder[arm];
      break;
    case scoreheight:
      targetVal = scoreheight - nMotorEncoder[arm];
      break;
    default:

  }
  nxtDisplayTextLine(2, "tv:%d, nME:%d", targetVal,nMotorEncoder[arm]);
  //Move the arm up to Rack Position.
  //nMotorEncoderTarget[arm]= targetVal;

  //power the motor
  if(targetVal > 0)
  {
    MoveArm(100);
  }
  else
  {
    MoveArm(-22);
  }

  //Wait until the motors stop moving
  //while ( (nMotorRunState[arm] != runStateIdle) )
  while(nMotorEncoder[arm] < targetVal)
  {
    wait1Msec(10);
  }
  StopArm();
  wait1Msec(100);// settle down
}
