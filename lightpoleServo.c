
int x = 0;
task lightServoStart() {						 			// Start handServoStart task
	int i = 67; 												// Initiate i here outside of while loop lexical scope
	int g = 0;
	USEBTN(Btn7D);
	USEBTN(Btn7U);
	USEBTN(Btn7L);
	USEBTN(Btn7R);
	int lastI = 0;
	motor[GateServo] = 127;
	motor[LightpoleServo] = i;
	wait1Msec(500);
	motor[GateServo] = -127;
	while(true) {  												// Run forever
	  UPDATEBTN(Btn7D);
		UPDATEBTN(Btn7U);
		UPDATEBTN(Btn7L);
		UPDATEBTN(Btn7R);

		lastI = i;
		x = g;
		if(BTNPRESSED(Btn7U)) { 			 		// If the Button is down, run this:
			i -= 10;
		} else if(BTNPRESSED(Btn7D)) { 		// Else, if Button is down, run this:
			i += 10;
	  } else if(BTNPRESSED(Btn7L)) {
    	if(g)	{
      	motor[GateServo] = -127;
      	g = 0;
    	} else {
    		motor[GateServo] = 127;
      	g = 1;
     	}
	  } else if(BTNPRESSED(Btn7R)) {
	  	i -= 2;
	  }
	  if(!(autonomous))   {
	  if(i < -103) { i = -103; } else if(i > 67) { i = 67;}
	  if(lastI != i) {
	    motor[LightpoleServo] = i;   // Add whatever i is to the motor
    }
	  wait1Msec(20);							// wait 20 milliseconds
      }
	}
}
