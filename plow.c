
task plowMotorStart() {						 			// Start handServoStart task
																				// Initiate i here outside of while loop lexical scope
		USEBTN(Btn8U);
		USEBTN(Btn8D);
		while(true) {  											// Run forever
		int i = 0;
		UPDATEBTN(Btn8U);
		UPDATEBTN(Btn8D);
		if(GETBTN(Btn8U)) 									// If the Button is down, run this:
			{
			i = vexRT[Btn8U];
		} else {
			}
		{
		i = -vexRT[Btn8U];
		}
		motor[PlowMotor] = 0 + i;
		wait1Msec(20);											// wait 20 milliseconds
	}
}
