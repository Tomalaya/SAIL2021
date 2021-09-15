task armStart() {
	while(true) {
		int armMotorSpeed = 0;
		if(vexRT[Ch2] > 20 && vexRT[Ch2] < -20) {
			armMotorSpeed = vexRT[Ch2];
	  }
		motor[ArmMotor] = 0 + armMotorSpeed;
	}
}
