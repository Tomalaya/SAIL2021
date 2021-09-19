
task handServoStart() {
	while(vexRT[Btn6U] == 1) {
		i++;
		if(i >= 127) {
			i = 127;
		}
		//Determine Speed here
		motor[HandServo] = 0 + i;
	}
}
task handServoReverse() {

	while(vexRT[Btn6D] == 1) {
		i++;
		if(i >= 127) {
			i = 127;
	  }
		motor[HandServo] = 0 - i;
	}
	wait1Msec(20);
}
