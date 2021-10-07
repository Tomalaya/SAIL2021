
int x = 0;
task lightServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	USEBTN(Btn7D);
	USEBTN(Btn7U);
	USEBTN(Btn7L);
	USEBTN(Btn7R);
	int lastI = 0;
	while(true) {  												// Run forever
		UPDATEBTN(Btn7D);
		UPDATEBTN(Btn7U);
		UPDATEBTN(Btn7L);

		UPDATEBTN(Btn7R);
		lastI = i;
		x = i;
		if(BTNPRESSED(Btn7U)) { 			 		// If the Button is down, run this:
			i+=10;
		} else if(BTNPRESSED(Btn7D)) { 		// Else, if Button is down, run this:
			i -= 10;
	    } else if(BTNPRESSED(Btn7L)) {      //full reset
	        i = -127;
	    } else if(BTNPRESSED(Btn7R)) {
	        i +=2;
	    }
	  if(i < -127)i = -127; else if(i > 127) i = 127;
	  if(lastI != i) {
			motor[LightpoleServo] = i;   // Add whatever i is to the motor
		}
		wait1Msec(20);							// wait 20 milliseconds
	}
}
