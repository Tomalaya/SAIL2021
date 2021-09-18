
int armCh2 = 0;
task armStart() {
	int armMotorSpeed = 0;
	while(true) {
		armCh2 = vexRT[Ch2];

		if(armCh2 > 20 || armCh2 < -20) {
			armMotorSpeed = armCh2;
	  }
	  else {
	  	armMotorSpeed = 0;
	  }
		motor[ArmMotor] = 0 + armMotorSpeed;
		wait1Msec(20);
	}
}
