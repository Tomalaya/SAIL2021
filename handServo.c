
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
		if(btn6U && !lastBtn6U) { 			 		// If the Button is down, run this:

				i = 127;												// Set i to 127

		} else if(btn6D && !lastBtn6D) { 		// Else, if Button is down, run this:
				i = -127;													// Set i to 127
	  }
		motor[HandServo] = 0 + (i / 100);   // Add whatever i is to the motor
	}
	wait1Msec(20); 								 				// wait 20 milliseconds
}
