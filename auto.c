
task autoStart() {												// Start task armStart
		while(true) {													// Loop forever
		playSound(soundBlip);
		while(getTimer(T1, 10) == 10) {							// Use a timer as a condition, 10 Seconds
			motor[LeftWheel] = 120;							// Set Left Motor to 120
			motor[RightWheel] = 120;						// Set Right Motor to 120
	  }
	  while(getTimer(T2, 10) == 10) {							// Use a timer as a condition, 10 Seconds
			motor[LeftWheel] = -120;						// Set Left Motor to -120
			motor[RightWheel] = -120;						// Set Right Motor to -120
	  }
		wait1Msec(20);												// Wait 20 Milliseconds
	}
}
