
task wristServoStart() {
	while(vexRT[Btn5U] == 1) {
		j++;
		if(j >= 100) {
			j = 100;
		}
		//Determine Speed here
		motor[WristServo] = 0 + j;
	}
}
task wristServoReverse() {
	if(j >= 100) {
			j = 100;
	}
	while(vexRT[Btn5D] == 1) {
		j++;
		motor[WristServo] = 0 - j;
	}
	wait1Msec(20);
}
