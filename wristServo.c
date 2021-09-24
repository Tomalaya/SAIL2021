
task wristServoStart() {						 		// Start handServoStart task
	USEBTN(Btn5U);
	USEBTN(Btn5D);
	int j = 0; 											 			// Initiate i here outside of while loop lexical scope

	while(true) { 									 			// Run forever
		UPDATEBTN(Btn5U);
		UPDATEBTN(Btn5D);
		if(BTNPRESSED(Btn5U)) { 			 			// If the Button is down, run this:

		j = 127;

		} else if(BTNPRESSED(Btn5D)) { 			// Else, if Button is down, run this:

		j = -127;

	  }
		motor[WristServo] = j;     			// Add whatever j is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
