
#include "ArmLib.c"

task ArmControlTask()
{
  nMotorEncoder[arm] = 0;

  TJoystick joystick_sm;      // User defined variable access
  while(true)
  {

			      //Update joystick settings
			    getJoystickSettings(joystick_sm);

			      //If the down button on the Dpad is pressed, move the arm to score from the low dispenser
			    if(IsJoy2Button4Pressed(joystick_sm) == true)
			    {
			      motor[Arm] = 40;

			    } // control hoop to drag the rolling goal
			    else if(IsJoy2Button2Pressed(joystick_sm) == true)
			    {
			        if(gHookInResetPos == false)
			          ResetHoop();
			        else
			        {
			          ResetArm();
			          LowerHoop();
			          gHookInResetPos = false;
			        }

			    }

			    else if(IsJoy2Button1Pressed(joystick_sm) == true)
			    {
			        nMotorEncoderTarget[arm]= 1700;
              motor[arm]=40;
               while ( (nMotorRunState[arm] != runStateIdle) )
							  {

							    wait1Msec(30);
							  }
							  motor[arm]=0;

			        //ArmToPosition(scoreheight);
			    }

			    else if(IsJoy2Button3Pressed(joystick_sm) == true)
			    {
             if(SensorValue[Touch] == 0)
			          motor[Arm] = -30;
			       else
			          motor[Arm] = 0 ;

			    }
          //move to the position to score from the low dispenser when the down button on the Dpad is pressed
			    else if(IsDOWNJoy2DPadPressed(joystick_sm) == true)
			    {
			      ArmToPosition(lowheight);

			    }

			    //If the left button on the Dpad is pressed, move the arm to score from the middle dispenser
			    else if(isLEFTJoy2DPadPressed(joystick_sm) == true)
			    {
            ArmToPosition(middleheight);
			    }

			    //If the up button on the Dpad is pressed, move the arm to score from the high dispenser
			    else if(IsUPJoy2DPadPressed(joystick_sm) == true)
			    {
            ArmToPosition(highheight);
			    }

			    else if(isRIGHTJoy2DPadPressed(joystick_sm) == true)
			    {
			      ResetArm();
			    }

			    //If button 5 is pressed on joystick 2, turn the claw to collect batons
			    else if(IsJoy2Button5Pressed(joystick_sm) == true)
			    {
			      hogCPU();
			      CLAWS_ROTATE_REV
			      //wait1Msec(4925);
			      wait1Msec(930);
			      CLAWS_STOP
			      releaseCPU();
			    }
			    else if(IsJoy2Button7Pressed(joystick_sm) == true)
			    {
			      hogCPU();
			      CLAWS_ROTATE_FWD
			      //wait1Msec(4925);
			      wait1Msec(100);
			      CLAWS_STOP
			      releaseCPU();
			    }
			    //If button 6 is pressed on joystick 2, open the trapdoor
			    else if(IsJoy2Button6Pressed(joystick_sm) == true)
			    {
			      ServoRotate(trapdoor,180);
			    }

			    //if button 8 is pressed on joystick 2, close the trapdoor
			    else if(IsJoy2Button8Pressed(joystick_sm) == true)
			    {
			      ServoRotate(trapdoor,52);
			    }

			    else if(joystick_sm.joy2_Tophat == -1)
			    {
			      motor[Arm] = 0;
			    }
      wait1Msec(20);

  }
}
