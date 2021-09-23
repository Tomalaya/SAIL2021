
task handServoStart() {						 			// Start handServoStart task
	int i = 0; 														// Initiate i here outside of while loop lexical scope
	int lastBtn6U = 0;
	int btn6U = 0;
	int lastBtn6D = 0;
	int btn6D = 0;
	while(true) {  												// Run forever
		lastBtn6U = btn6U;
		btn6U = vexRT[btn6U];
		lastBtn6D = btn6D;
		btn6D = vexRT[btn6D];
		if(btn6U && !lastBtn6U) { 			 			// If the Button is down, run this:
			for(int k = 0; k < 127000; k++) { // Declare int k, if k is greater than -127, subtract 1 from k and,
				i = k;													// Set j to k
				wait1Msec(20);									// Wait 100 Milliseconds
		  }
		} else if(btn6U && !lastBtn6U) { 			// Else, if Button is down, run this:
			for(int k = 0; k > -127000; k--) {// Declare int k, if k is greater than -127, subtract 1 from k and,
				i = k;													// Set j to k
				wait1Msec(100);									// Wait 100 Milliseconds
		  }
	  }
		motor[HandServo] = 0 + (i / 100);   // Add whatever i is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
