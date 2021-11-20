int speed = 0;
int k = 1;
int WristPosition = -38;
task wristServoStart() {						 			// Start wristServoStart task
	USEBTN(Btn5U);
	USEBTN(Btn5D);
	int lastI = 0;
	motor[WristServo] = WristPosition;
	k = 1;
	while(true) {  												// Run forever
		UPDATEBTN(Btn5U);
		UPDATEBTN(Btn5D);
		lastI = WristPosition;
		if(!(autonomous))	{

			if(GETBTN(Btn5U)) { 			 		// If the Button is down, run this:
				WristPosition +=1 + speed;
				k ++;
			} else if(GETBTN(Btn5D)) { 		// Else, if Button is down, run this:
				WristPosition -= 1 + speed;
				k ++;
		  }
		  if(!(k % 10)){
		  	speed ++;
			}
		  if(BTNRELEASED(Btn5U)){
		  	speed = 0;
		  	k = 1;
			} else if(BTNRELEASED(Btn5D)){
				speed = 0;
				k = 1;
			}
		  if(WristPosition < -127)WristPosition = -127; else if(WristPosition > 127) WristPosition = 127;
		  if(lastI != WristPosition) {
				motor[WristServo] = WristPosition;   // Add whatever i is to the motor
		  }
	  }
		wait1Msec(20);							// wait 20 milliseconds
	}
}
