int lightPolePosition = 67; 												// Initiate i here outside of while loop lexical scope
int x = 0;
task lightServoStart() {						 			// Start handServoStart task
	int g = 0;
	USEBTN(Btn7D);
	USEBTN(Btn7U);
	USEBTN(Btn7L);
	USEBTN(Btn7R);
	int lastI = 0;
	motor[GateServo] = 127;
	motor[LightpoleServo] = lightPolePosition;
	wait1Msec(500);
	motor[GateServo] = -127;
	while(true) {  												// Run forever
	  UPDATEBTN(Btn7D);
		UPDATEBTN(Btn7U);
		UPDATEBTN(Btn7L);
		UPDATEBTN(Btn7R);

		lastI = lightPolePosition;
		x = g;
		if(BTNPRESSED(Btn7U)) { 			 		// If the Button is down, run this:
			lightPolePosition -= 10;
		} else if(BTNPRESSED(Btn7D)) { 		// Else, if Button is down, run this:
			lightPolePosition += 10;
	  } else if(BTNPRESSED(Btn7L)) {
    	if(g)	{
      	motor[GateServo] = -127;
      	g = 0;
    	} else {
    		motor[GateServo] = 127;
      	g = 1;
     	}
	  } else if(BTNPRESSED(Btn7R)) {
	  	lightPolePosition -= 2;
	  }
	  if(!(autonomous))   {
	  if(lightPolePosition < -103) { lightPolePosition = -103; } else if(lightPolePosition > 67) { lightPolePosition = 67;}
	  if(lastI != lightPolePosition) {
	    motor[LightpoleServo] = lightPolePosition;   // Add whatever i is to the motor
    }
	  wait1Msec(20);							// wait 20 milliseconds
      }
	}
}
