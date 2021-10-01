task lightServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn7U);
	USEBTN(Btn7D);
	USEBTN(Btn7R);
	USEBTN(Btn7L);
	int lastI = 0;
	while(true) {  												// Run forever
		UPDATEBTN(Btn7U);
		UPDATEBTN(Btn7D);
		UPDATEBTN(Btn7R);
		UPDATEBTN(Btn7L);
		lastI = i;
		if(GETBTN(Btn7U)) { 			 		// If the Button is down, run this:
			i+=10;
		} else if(GETBTN(Btn7D)) { 		// Else, if Button is down, run this:
			i -= 10;
	    } else if(GETBTN(Btn7L)) {      //full reset
	        i = -127;
	    } else if(GETBTN(Btn7R)) {
	        i +=2;
	    }
	  if(i < -127)i = -127; else if(i > 127) i = 127;
	  if(lastI != i) {
			motor[LightpoleServo] = i;   // Add whatever i is to the motor
		}
		wait1Msec(20);							// wait 20 milliseconds
	}
}
