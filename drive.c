#pragma config(Motor,  port2,           RightWheel,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           ClawServo,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           BackWheel,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           LeftWheel,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//todo: learn stuff

task main() {
    //Main Drive Function
	while(true) {
		while(vexRT[joy1_x1] == 0) {
			motor[RightWheel] = 0;
	  }
		while(vexRT[joy1_x1] > 20) {
			motor[RightWheel]= vexRT[joy1_x1];
		}
		while(vexRT[joy1_x1] < -20) {
			motor[RightWheel]= vexRT[joy1_x1];
			motor[LeftWheel] = vexRT[joy1_x1] + vexRT[joy1_x1] + vexRT[joy1_x1];
		}
	}
}
