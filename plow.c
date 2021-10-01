
task plowMotorStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	int lastI = 0;
	while(true) {  												// Run forever
		UPDATEBTN(Btn8U);
		UPDATEBTN(Btn8D);
		lastI = i;
		if(GETBTN(Btn8U)) { 			 		// If the Button is down, run this:
			i+=10;
		} else if(GETBTN(Btn8D)) { 		// Else, if Button is down, run this:
			i -= 10;
	     }
	    if(i < -127)i = -127; else if(i > 127) i = 127;
	    if(lastI != i) {

	            motor[PlowMotor] = i;   // Add whatever i is to the motor
            
		}
		wait1Msec(20);							// wait 20 milliseconds
	}
}
