
task autoStart() {												// Start task armStart
	int lastBtn8U = 0;
	int btn8U = 0;
	while(true) {
		lastBtn8U = btn8U;
		btn8U = vexRT[btn8U];
			if(btn8U && !lastBtn8U) {
				int i = 0;														// Declare Global Integer i
				int j = 0;														// Declare Global Integer j
				int end = 0;
				playSound(soundBlip);									// Play a sound to indicate task is running

					motor[LeftWheel] = 120;							// Set Left Motor to 120
					motor[RightWheel] = 120;						// Set Right Motor to 120
					i++;																// Increment i by 1


			  while(end++<20)   {
              if (vexRT[btn7U], vexRT[Btn7D]| vexRT[Btn7L]| vexRT[Btn7R]| vexRT[Btn8D]| vexRT[Btn8L]| vexRT[Btn8R]| vexRT[Btn6U]| vexRT[Btn6D]| vexRT[Btn5U]| vexRT[Btn5D]) {autonomous=false; break;}
			  wait1Msec(100);

			  }



			  while(j < 100000) {										// Loop until j hits 100,000
			  	motor[LeftWheel] = 120;							// Set Left Motor to 120
			  	motor[RightWheel] = 120;						// Set Right Motor to 120
			  	j++;																// Increment j by 1
			  }

				wait1Msec(20);												// Wait 20 Milliseconds
		}

	}
}
