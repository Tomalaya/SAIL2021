
task wristServoStart() {						 		// Start handServoStart task
	int j = 0; 											 			// Initiate i here outside of while loop lexical scope
	while(true) { 									 			// Run forever
		if(vexRT[Btn5U] == 1) { 			 			// If the Button is down, run this:

			for(int k = 0; k < 127; k++) {		// Declare int k, if k is greater than -127, subtract 1 from k and,
				j = k;													// Set j to k
				wait10Msec(10);									// Wait 100 Milliseconds
		  }
		} else if(vexRT[Btn5D] == 1) { 			// Else, if Button is down, run this:

			for(int k = 0; k > -127; k--) {		// Declare int k, if k is greater than -127, subtract 1 from k and,
				j = k;													// Set j to k
				wait1Msec(20);									// Wait 100 Milliseconds
		  }
	  }
		motor[WristServo] = 0 + j;     			// Add whatever i is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
