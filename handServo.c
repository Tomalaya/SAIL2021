
task handServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn6U);
	USEBTN(Btn6D);
	while(true) {  												// Run forever
		UPDATEBTN(Btn6U);
		UPDATEBTN(Btn6D);
		if(GETBTN(Btn6U)) { 			 		// If the Button is down, run this:
			wait1Msec(10);
			i+=10;
			if(i >= 127) {
				i = 127;
			}
		} else if(GETBTN(Btn6D)) { 		// Else, if Button is down, run this:

			wait1Msec(10);
			i -= 10;
			if(i <= -127) {
				i = -127;
			}
	  }
		motor[HandServo] = 0 + i;   // Add whatever i is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
