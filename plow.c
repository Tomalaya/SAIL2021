
task plowMotorStart() {						 			// Start handServoStart task

	USEBTN(Btn8U);
	USEBTN(Btn8D);

	while(true) {  											// Run forever

	UPDATEBTN(Btn8U);
	UPDATEBTN(Btn8D);
  if(!(autonomous))   {
	if(BTNPRESSED(Btn8U)) 	{								// If the Button is down, run this:
		motor[PlowMotor] = 127;
	} else if(BTNPRESSED(Btn8D))    {                       // Else the Button is down, run this:
	    motor[PlowMotor] = -127;
	}
	if(BTNRELEASED(Btn8D) || BTNRELEASED(Btn8U)){
	    motor[PlowMotor] = 0;
	}
	}
	wait1Msec(20);											// wait 20 milliseconds
	}
}
