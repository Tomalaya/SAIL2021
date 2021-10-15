task wristServoStart() {						 			// Start wristServoStart task
	int i = 127; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn5U);
	USEBTN(Btn5D);
	int lastI = 0;
	motor[WristServo] = i;
	while(true) {  												// Run forever
		UPDATEBTN(Btn5U);
		UPDATEBTN(Btn5D);
		lastI = i;
		if(!(autonomous))	{
		if(GETBTN(Btn5U)) { 			 		// If the Button is down, run this:
			i+=10;
		} else if(GETBTN(Btn5D)) { 		// Else, if Button is down, run this:
			i -= 10;
	    }
	    if(i < -127)i = -127; else if(i > 127) i = 127;
	    if(lastI != i) {
			motor[WristServo] = i;   // Add whatever i is to the motor
	    }
	  }
		wait1Msec(20);							// wait 20 milliseconds
	}
}
