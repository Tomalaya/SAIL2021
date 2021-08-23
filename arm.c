/*******************************************************************************
 *    ##    #####   ##      ##
 *   ####   ##  ##  ###    ###
 *  ##  ##  ##  ##  ####  ####
 *  ######  #####   ## #### ##
 *  ##  ##  ##  ##  ##  ##  ##
 *  ##  ##  ##  ##  ##      ##
 *******************************************************************************/
 /* ARM Control functions, including claw */

int clawOpen = 0;	//1 if claw isopen, 0 if closed
int armPos = 0;		//Arm position, read from potentiometer
int targetArm = 0;	//Target arm position to move the arm
int doArmMove = 0;	//Set to 1 to enact arm movement
int armSpeed = 100; //Speed at which arm should move

/* This task moves the arm up and down. */
/* All tasks must introduce waits in any loop so the OS can task swap and run mutliple operations */
task ArmMove() {
	while (true) {

		//Get the current arm position
		armPos = SensorValue(potentiometer);

		//See if we should be moving, if not just wait and loop
		if (!doArmMove) {
			wait1Msec(20);
			continue;
		}

		//ARM requested to move
		if (armPos > targetArm) { //Target is less than arm, move up
			while (doArmMove && armPos > targetArm) {
				motor[armMotor] = -armSpeed;
				armPos = SensorValue(potentiometer);
				wait1Msec(20);
			}
			//done moving, stop the motor
			motor[armMotor] = 0;
			doArmMove = 0; // <-- IMPORTANT, stop arm move request
		} else {
			while (doArmMove && armPos < targetArm) { //Target is more than arm, move down
				motor[armMotor] = armSpeed;
				armPos = SensorValue(potentiometer);
				wait1Msec(20);
			}
			//done moving, put a little power on the motor to stop drift down from gravity
			motor[armMotor] = 10;
			wait1Msec(100);

			motor[armMotor] = 0;
			doArmMove = 0; // <-- IMPORTANT, stop arm move request
		}
	}
}

/* By potentiometer, 1000 is top of arm position, 2350 is the lower arm position */
#define ARMTOP 1000
#define ARMBOTTOM 2350

/* ARM Speed by motor power */
#define ARMFAST 100
#define ARMSLOW 40

#define MOVEARM(pos,spd) targetArm = pos; armSpeed = spd; doArmMove = 1

/* This Task controls the ARM and claw from inputs from the controller */
/* All tasks must introduce waits in any loop so the OS can task swap and run mutliple operations */
task Arm() {

	motor[clawMotor] = 0;  //Initially set our claw closed on app startup

	while(true) {
		//Check all of our ARM/Claw buttons
		int b7u = chkButton(vexRT[Btn7U], BUTTON7UP);		//7U moves arm auto all the way up
		int b7d = chkButton(vexRT[Btn7D], BUTTON7DOWN);		//7D moves arm auto all the way down
		int b7r = chkButton(vexRT[Btn7R], BUTTON7RIGHT);	//7R & 7L both toggle the claw
		int b7l = chkButton(vexRT[Btn7L], BUTTON7LEFT);
		int b5d = chkButton(vexRT[Btn5D], BUTTON5LOWER);	//5D moves arm up until released or top reached
		int b6d = chkButton(vexRT[Btn6D], BUTTON6LOWER);	//5D moves arm down until released or bottom reached

		if (1 == b7u && armPos > ARMTOP) {
			MOVEARM (ARMTOP,ARMFAST);
		} else if (1 == b7d && armPos < ARMBOTTOM) {
			MOVEARM (ARMBOTTOM,ARMFAST);
		} else if (1 == b5d && armPos > ARMTOP) {
			MOVEARM (ARMTOP,ARMSLOW);
		} else if (1 == b6d && armPos < ARMBOTTOM) {
			MOVEARM (ARMBOTTOM,ARMSLOW);
		} else if (-1 == b5d || -1 == b6d) {
			doArmMove = 0; //5D or 6D release, stop the arm
		}

		if (1 == b7r || 1 == b7l) {		//7R & 7L both toggle the claw
			motor[clawMotor] = clawOpen ? 0 : -127;
			clawOpen = 1-clawOpen;
		}

		wait1Msec(20);
	}

}
