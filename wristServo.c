
task wristServoStart() {						 // Start handServoStart task
	int j = 0; 											 // Initiate i here outside of while loop lexical scope
	while(true) { 									 // Run forever
		if(vexRT[Btn5U] == 1) { 			 // If the Button is down, run this:
		  j++;												 // Add 1 to i here
		  if(j >= 127) {							 // If i counts to higher than 127,
			  j = 127;									 // Set i to 127
		  }
		} else if(vexRT[Btn5D] == 1) { // Else, if Button is down, run this:
			j--;												 // Subtract 1 from i here
			if(j <= -127) {							 // if i is less than 127, then
			  j = -127;									 // Set i to -127
	    }
	  }
		motor[WristServo] = 0 + j;     // Add whatever i is to the motor
	}
	wait10Msec(20); 								 // wait 200 milliseconds
}
