
task plowMotorStart() {						 			// Start handServoStart task
																				// Initiate i here outside of while loop lexical scope
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	while(true) {  											// Run forever

	UPDATEBTN(Btn8U);
	UPDATEBTN(Btn8D);
	if(GETBTN(Btn8U)) 	{								// If the Button is down, run this:
		motor[PlowMotor] = 127;
	} else if(GETBTN(Btn8D))    {
	    motor[PlowMotor] = -127;
	}
	wait1Msec(20);											// wait 20 milliseconds
	}
}
