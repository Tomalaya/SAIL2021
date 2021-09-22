#pragma config(Motor,  port2,           rightwheel,    tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port9,           leftwheel,     tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port4,           HandServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           WristServo,    tmotorServoStandard, openLoop)


task autoStart()		{



int i = 1;


while(true) 	{													// Loop forever
	playSound(soundBlip);

		motor[LeftWheel] = 120;							// Set Left Motor to 120
	 motor[RightWheel] = 120;						// Set Right Motor to 120

	 i ++;

	}
	while(getTimer(T2, 10) == 10) {							// Use a timer as a condition, 10 Seconds
		motor[LeftWheel] = -120;						// Set Left Motor to -120
		motor[RightWheel] = -120;						// Set Right Motor to -120
	}
	wait1Msec(20);												// Wait 20 Milliseconds
}



}



}























}
