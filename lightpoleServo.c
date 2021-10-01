task lightServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn8L);
	USEBTN(Btn8R);
	USEBTN(Btn7L);
	USEBTN(Btn7R);
	int lastI = 0;
	while(true) {  												// Run forever
		UPDATEBTN(Btn8L);
		UPDATEBTN(Btn8R);
		UPDATEBTN(Btn7L);
		UPDATEBTN(Btn7R);
		lastI = i;
		if(BTNPRESSED(Btn8L)) { 			 		// If the Button is down, run this:
			i+=10;
		} else if(BTNPRESSED(Btn8R)) { 		// Else, if Button is down, run this:
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
