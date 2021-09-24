
task handServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn6U);
	USEBTN(Btn6D);
	while(true) {  												// Run forever
		UPDATEBTN(Btn6U);
		UPDATEBTN(Btn6D);
		if(BTNPRESSED(Btn6U)) { 			 		// If the Button is down, run this:

				i = 127;												// Set i to 127

		} else if(BTNPRESSED(Btn6D)) { 		// Else, if Button is down, run this:
				i = -127;													// Set i to 127
	  }
		motor[HandServo] = i;   // Add whatever i is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
