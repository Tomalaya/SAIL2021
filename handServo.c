int handPosition = 127;
task handServoStart() {						 			// Start handServoStart task												// Initiate i here outside of while loop lexical scope
	USEBTN(Btn6U);
	USEBTN(Btn6D);
	motor[HandServo] = handPosition;
	int lastI = 0;
	while(true) {  												// Run forever
		UPDATEBTN(Btn6U);
		UPDATEBTN(Btn6D);
		lastI = handPosition;
		if(GETBTN(Btn6U)) { 			 		// If the Button is down, run this:
			handPosition+=10;
		} else if(GETBTN(Btn6D)) { 		// Else, if Button is down, run this:
			 handPosition-= 10;
	  }
	  if(!(autonomous))   {
	  if(handPosition < -127)handPosition = -127; else if(handPosition > 127) handPosition = 127;
	  if(lastI != handPosition) {
			motor[HandServo] = handPosition;   // Add whatever i is to the motor
		}
		wait1Msec(20);							// wait 20 milliseconds
	}
	}
}
