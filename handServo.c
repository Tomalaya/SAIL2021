
task handServoStart() {						 // Start handServoStart task
	int i = 0; 											 // Initiate i here outside of while loop lexical scope
	while(true) { 									 // Run forever
		if(vexRT[Btn6U] == 1) { 			 // If the Button is down, run this:
		  i++;												 // Add 1 to i here
		  if(i >= 127) {							 // If i counts to higher than 127,
			  i = 127;									 // Set i to 127
		  }
		} else if(vexRT[Btn6D] == 1) { // Else, if Button is down, run this:
			i--;												 // Subtract 1 from i here
			if(i <= -127) {							 // if i is less than 127, then
			  i = -127;									 // Set i to -127
	    }
	  }
		motor[HandServo] = 0 + i;      // Add whatever i is to the motor
	}
	wait10Msec(20); 								 // wait 200 milliseconds
}
