task armStart() {
	USEBTN(Ch2);
	int armMotorSpeed = 0;
	int lastarmMotorSpeed = 0;
	while(true) {
		UPDATEBTN(Ch2);
		lastarmMotorSpeed = armMotorSpeed;
		if((abs(GETBTN(Ch2)) > 10)) {
			armMotorSpeed = GETBTN(Ch2);
		}
		else {
			armMotorSpeed = 0;
		}
		if(!(autonomous) && lastarmMotorSpeed != armMotorSpeed)   {
			motor[ArmMotor] = 0 + armMotorSpeed * slowMode;
		}
		wait1Msec(20);
	}
}
