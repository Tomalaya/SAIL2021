
int armCh2 = 0;														// Declare Global Integer armCh2 and set it to 0
task armStart() {													// Start task armStart
	int armMotorSpeed = 0;									// Declare Local Integer armMotorSpeed and set it to 0
	while(true) {														// Loop forever
		armCh2 = vexRT[Ch2];									// set armCh2 to the Y Axis of the Right Joystick

		if(armCh2 > 20 || armCh2 < -20) {			// If armCh2 is greater than 20 or armCh2 is less than -20
			armMotorSpeed = armCh2;							// Set armMotorSpeed to armCh2
		}
		else {																// Else,
			armMotorSpeed = 0;									// Set armMotorSpeed to 0
		}
		motor[ArmMotor] = 0 + armMotorSpeed;  // Set Arm Motor to 0 + armMotorSpeed
		wait1Msec(20);												// Wait 200 Milliseconds
	}
}
