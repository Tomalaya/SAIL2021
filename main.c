#pragma config(Motor,  port2,           RightWheel,    tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port4,           ArmMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           HandServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           WristServo,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           LeftWheel,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include <arm.c>															// Include File arm.c
#include <handServo.c>												// Include File handServo.c
#include <wristServo.c>												// Include File wristServo.c
#include <auto.c>															// Include File auto.c

task main() {																	// Main Task
	int leftSpeed = 0;													// Initialize integer leftSpeed
	int rightSpeed = 0;													// Initialize integer rightSpeed
	int left2Speed = 0;													// Initialize integer left2Speed
	int right2Speed = 0;												// Initialize integer right2Speed
	startTask(wristServoStart); 								// Start the wristServoStart Task
	startTask(handServoStart);  								// Start the handServoStart Task
	startTask(armStart);												// Start the armStart Task
	while(true) {																// Start a while loop
		if(vexRT[Ch3] < 20 && vexRT[Ch3] > -20) {	// Check if the Left Joystick Y Axis is in the middle
			rightSpeed = 0;													// If the Left Joystick Y Axis is, set rightSpeed to 0
			leftSpeed = 0;													// If the Left Joystick Y Axis is, set leftSpeed to 0
		} else {																	// Else, if the Left Joystick Y Axis is NOT,
			rightSpeed = -vexRT[Ch3];							  // Set rightSpeed to the (-)value of the Left Joystick Y Axis
			leftSpeed = -vexRT[Ch3];								// Set leftSpeed to the (-)value of the Left Joystick Y Axis
		}
		if(vexRT[Ch4] < 20 && vexRT[Ch4] > -20) { // Check if the Left Joystick X Axis is in the middle
			right2Speed = 0;												// If the Left Joystick X Axis is, set right2Speed to 0
			left2Speed = 0;													// If the Left Joystick X Axis is, set left2Speed to 0
		} else {																	// Else, if the Left Joystick X Axis is NOT,
			right2Speed = vexRT[Ch4];								// Set right2Speed to the (-)value of the Left Joystick X Axis
			left2Speed = vexRT[Ch4];								// Set left2Speed to the (-)value of the Left Joystick X Axis
		}
		if(vexRT[Btn8U] == 1) {										// If Button 8U is Down,
			startTask(autoStart);										// Start Task autoStart
	  }
	  if(vexRT[Btn7L] == 1) {
	  	right2Speed = -right2Speed;
	    left2Speed = -left2Speed;
	    rightSpeed = -rightSpeed;
	    leftSpeed = -leftSpeed;
		}
		motor[RightWheel]= 0 + rightSpeed + right2Speed; 		// Add rightSpeed and right2Speed to the Right Wheel Motor
		motor[LeftWheel]= 0 + (-leftSpeed) - (-left2Speed);	// Add the negative of leftSpeed and add left2Speed to the Left Wheel Motor

		wait1Msec(20);														// Wait 20 Milliseconds
	}
}