
#define MIN_POWER 10

//function to ramp down the power
void StopMtr(int mtr, int pwr)
{
  //the power of the robot can be modeled with the sine function.
  //Thus multipling with the sine of the dummy variable i will ramp down the power
  for (int i = 90 ; i < 0; i--)
  {
    pwr = pwr * sin(i);
    nxtDisplayTextLine(3, "p: %d",pwr);

    motor[mtr] = pwr;
    wait1Msec(10);
  }
}



task DriveRobot()
{

  TJoystick joystick_dt;

  int motDPower, prevmotDPower, motEPower, prevmotEPower ;

  bool bTouched4 = false;
  bool bTouched3 = false;

  //remove the PID control
  nMotorPIDSpeedCtrl[leftm]= mtrNoReg;
  nMotorPIDSpeedCtrl[rightm]= mtrNoReg;

  while(true)
  {
    getJoystickSettings(joystick_dt);  //Update joystick/game values to see if enabled

    //User Control Code here
	  motDPower = joystick_dt.joy1_y1 * 0.7; //scale down joystick values so that motor values correspond to joystick values.
    motEPower = joystick_dt.joy1_y2 * 0.7;


    //this is because we dont want the motors to move when we only move the joystick a little bit.
    if (abs(motDPower) <= MIN_POWER)
    {
      //StopMtr(rightm, prevmotDPower);
      motDPower = 0;
    }

     if(abs(motEPower) <= MIN_POWER)
     {
       //StopMtr(leftm, prevmotEPower);
       motEPower = 0;
     }


    //Right arcmturn (going forward) if Button5 on joystick 1 is pressed
    if( IsJoy1Button5Pressed(joystick_dt) == true)
    {
    		motDPower  = 60;
    		motEPower = 20;

    }

   	//Left arc turn (going forward) if Button5 on joystick 1 is pressed
    if( IsJoy1Button6Pressed(joystick_dt) == true)
    {
        motDPower = 60;
        motEPower = 60;
    }

    //Right arc turn (going backwards) if Button7 on joystick 1 is pressed
    if( IsJoy1Button7Pressed(joystick_dt) == true)
    {
    		motDPower = -60;
    		motEPower = -20;
    }

   	//Left arc turn (going backward) if Button5 on joystick 1 is pressed
    if( IsJoy1Button8Pressed(joystick_dt) == true)
    {
        motDPower = -60;
        motEPower = -60;
    }

    //If button 2 is pressed, go straight forward slowly. This is when we are close to the rack and we want to go exactly straight forward.
    if( IsJoy1Button2Pressed(joystick_dt) == true)
    {
        motDPower = 25;
        motEPower = 25;
    }

    //If button 1 is pressed, go straight backward. This is when we are close to the rack and we want to go exactly straight backward.
    if( IsJoy1Button1Pressed(joystick_dt) == true)
    {
        motDPower = -25;
        motEPower = -25;
    }

    //inch forward
    if( IsUPJoy1DpadPressed(joystick_dt) == true)
    {
      move(50,50,100);
    }

    //inch backward
    if( isDOWNJoy1DPadPressed(joystick_dt) == true)
    {
      move(-50,-50,100);
    }

    //inch clockwise(right)
    if( isRIGHTJoy1DPadPressed(joystick_dt) == true)
    {
      spinClockWise(50, 100);
    }

    //inch counterclockwise(left)
    if ( isLEFTJoy1DPadPressed(joystick_dt) == true)
    {
      spinAntiClockWise(50, 100);
    }

    // finally power the motors
    nxtDisplayTextLine(2, "LDrv:%d RDrv:%d", motDPower, motEPower);

    //else power motors
    {
        motor[leftm] = motDPower;
	      motor[rightm] = motEPower;
	  }


	  prevmotEPower = motEPower ;
	  prevmotDPower = motDPower ;

    wait10Msec(20);
  }


}
