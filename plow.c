
task plowMotorStart() {
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	while(true) {
		UPDATEBTN(Btn8U);
		UPDATEBTN(Btn8D);
  		if(!(autonomous))   {
			if(BTNPRESSED(Btn8U)) 	{
				motor[PlowMotor] = 127;
			}
			if(BTNPRESSED(Btn8D)) 	{
				motor[PlowMotor] = -127;
			}
			if(BTNRELEASED(Btn8U)){
	    	motor[PlowMotor] = 0;
			}
			if(BTNRELEASED(Btn8D)){
	    	motor[PlowMotor] = 0;
			}
			}
		wait1Msec(20);
	}
}
