
task handServoStart() {
	while(vexRT[Btn6U] == 1) {
		i++;
		if(i >= 100) {
			i = 100;
		}
		//Determine Speed here
		motor[HandServo] = 0 + i;
	}
}
task handServoReverse() {
	if(i >= 100) {
			i = 100;
	}
	while(vexRT[Btn6D] == 1) {
		i++;
		motor[HandServo] = 0 - i;
	}
}
