
task plowMotorStart() {
	USEBTN(Btn8U);
	int reversed = 1;
	while(true) {
		UPDATEBTN(Btn8U);
  	if(!(autonomous))   {
			if(BTNPRESSED(Btn8U)) 	{
				motor[PlowMotor] = 127 * reversed;
				reversed *= -1;
			}
			if(BTNRELEASED(Btn8U)){
	    	motor[PlowMotor] = 0;
			}
		}
		wait1Msec(20);
	}
}
