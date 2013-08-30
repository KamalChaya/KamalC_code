

//function for moving the robot
void move(int leftpwr,
                 int leftdegrees,
                 int rightpwr,
                 int rightDegrees)
{

  int leftDelta = 0;
  int rightDelta = 0;

  //giving PID control
 nMotorPIDSpeedCtrl[rightm] = mtrEncoderReg;
 nMotorPIDSpeedCtrl[leftm] = mtrEncoderReg;

 nMotorEncoderTarget[leftm] = leftdegrees;
 nMotorEncoderTarget[rightm] = rightDegrees;
  motor[leftm] = leftpwr ;
  motor[rightm] = rightpwr ;

  ClearTimer(T1);

	while( (nMotorRunState[leftm] != runStateIdle) && (nMotorRunState[rightm] != runStateIdle))
  //While lefm rightm are still running (haven't yet reached their target):
  {
      if(time1[T1] > 5000)
      {
        nxtDisplayTextLine(6, "Timeout...",);
        break;
      }
      wait1Msec(10);
  }

  //Stop motors and remove PID control
 // motor[leftm]=0;
 // motor[rightm]=0;
 nMotorPIDSpeedCtrl[rightm] = mtrNoReg;
 nMotorPIDSpeedCtrl[leftm] = mtrNoReg;

  //display the left and right encoder
  nxtDisplayTextLine(2, "re:%d,le:%d", nMotorEncoder[rightm], nMotorEncoder[leftm]);

}

//function for moving the robot
void move(int leftpwr,
                 int rightpwr,
                 int milliseconds)
{

  int leftDelta = 0;
  int rightDelta = 0;


  motor[leftm] = leftpwr ;
  motor[rightm] = rightpwr ;
  wait1Msec(milliseconds);
  motor[leftm] = 0 ;
  motor[rightm] = 0 ;

}

//the variations of the move function:
void moveFwd(int pwr, int degrees)
{
  move(pwr, degrees, pwr, degrees);
}

void moveBwd(int pwr, int degrees)
{
  move(-pwr, -degrees, -pwr, -degrees);
}

void spinClockWise(int pwr,
                 int degrees)
{
  move(pwr, degrees, -pwr, -Degrees);
}

void spinAntiClockWise(int pwr,
                 int degrees)
{
  move(-pwr, -degrees, pwr, Degrees);
}
