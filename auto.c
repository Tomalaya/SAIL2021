
task autoStart() {												// Start task armStart
		int i = 0;														// Declare Global Integer i
		int j = 0;														// Declare Global Integer j
		playSound(soundBlip);									// Play a sound to indicate task is running
		while(i < 100000) {										// Loop until i hits 100,000
			motor[LeftWheel] = 120;							// Set Left Motor to 120
			motor[RightWheel] = 120;						// Set Right Motor to 120
			i++;																// Increment i by 1
	  }
	  while(j < 100000) {										// Loop until j hits 100,000
	  	motor[LeftWheel] = 120;							// Set Left Motor to 120
	  	motor[RightWheel] = 120;						// Set Right Motor to 120
	  	j++;																// Increment j by 1
	  }
		wait1Msec(20);												// Wait 20 Milliseconds
	}
}
