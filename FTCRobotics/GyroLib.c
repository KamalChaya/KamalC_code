
#include "drivers/HTGYRO-driver.h"
int GyroValue = 0;
float TimeElapsed = 0;
long currTime;
long prevTime;
float heading = 0.0;
int gPwr = 0;

float getHeading()
{

  nxtDisplayTextLine(3, "rawGyro:   %4d", HTGYROreadRot(HTGYRO));
  currTime = nPgmTime;
  nxtDisplayTextLine(4, "et:   %1.8f", (float)(currTime - prevTime)/1000.0);
  nxtDisplayTextLine(5, "%4d-%4d",currTime, prevTime);

  GyroValue = HTGYROreadRot(HTGYRO);
  if((GyroValue < 3) && (GyroValue > -3)
    GyroValue = 0;

  heading += ((float) GyroValue * (float)(currTime - prevTime)/1000.0 ) ;
  prevTime = currTime;
  return heading;
}

task CalcHeading()
{
    prevTime =currTime = nPgmTime;

    while(true)
    {

      eraseDisplay();
      getHeading() ;
      nxtDisplayTextLine(6, "heading %1.4f", heading);

      if(heading > -5)
        gPwr = 20;
      else if(heading < 5)
        gPwr = -20;
      else
      {
        gPwr = 0;
      }

      wait1Msec(10);
    }
}

void BalanceOnBridgeUsingGyro()
{
	  eraseDisplay();
	    nxtDisplayTextLine(1, "Resetting");
	    nxtDisplayTextLine(1, "heading");
	    wait1Msec(100);

	    // Start the calibration and display the offset
	    nxtDisplayTextLine(2, "Offset: %4d", HTGYROstartCal(HTGYRO));
	   // wait10Msec(1000);
	    PlaySound(soundBlip);
	    while(bSoundActive);

	  StartTask(CalcHeading);

	   gPwr = -50;
	   motor[rightm] = gPwr;
		 motor[leftm] = gPwr;
	   wait1Msec(2000);
	   //while (true)
	   {
	    gPwr = -25;
	    while(true)
	    {

	        motor[rightm] = gPwr;
		      motor[leftm] = gPwr;
		      if( (heading < 5.5) && (heading > -5.5))
		      {
		        motor[rightm] = 0;
		        motor[leftm] = 0;
	          wait1Msec(8000);
	  	      break;
	  	    }
	 	      wait1Msec(10);

	    }
	  }
}
