#pragma config(Sensor, in1,    potentiometer,  sensorPotentiometer)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           tailMotor,     tmotorVex269_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port9,           leftMotor,     tmotorVex269_MC29, openLoop, reversed)

//THis defines the slots for button states, so we can see when they go up or down
enum BUTTONS{
    BUTTON5UPPER,
    BUTTON5LOWER,
    BUTTON6UPPER,
    BUTTON6LOWER,
    BUTTON7LEFT,
    BUTTON7RIGHT,
    BUTTON7UP,
    BUTTON7DOWN,
    BUTTON8LEFT,
    BUTTON8RIGHT,
    BUTTON8UP,
    BUTTON8DOWN
};

//This is where we store the button state.  0 is up, 1 is down
int bs[12]={0,0,0,0,0,0,0,0,0,0,0,0};

//Check if a button has changed state or is depressed.
//    Return  1 (>0) when a button is first pressed
//    Return -1 (<0) when a button is first pressed
//    Return  0 if the state has not changed
int chkButton (int cs, int btn) {
	if (cs && !bs[btn]) {
		bs[btn] = 1;
		return 1; //This button just went down
	} else if (!cs && bs[btn]) {
		bs[btn] = 0;
		return -1; //button was just released
	}

	return 0; //This button state has not changed
}

//This Task controls the ARM
task Arm() {

	while(true) {
		if (2 == chkButton(vexRT[Btn7U], BUTTON7UP)) {
		}
	/*int goVal = SensorValue(potentiometer);

			motor[rightMotor] = 0;
			motor[leftMotor] = 0;
			motor[tailMotor] = goVal > 4000 ? 127 : goVal * 127 / 4000;
			continue;
		*/
		wait1Msec(20);
	}

}

//Ignore the joystick becaus eit may float around the middle.  ANything less than DEADZONE is considered
//not a real value
#define JSDEADZONE 20

//This is the functionto control driving the robot. IN this case a 3 Omniwheeled Bot
void Drive()
{
		// This is the robot heading, in radians.  Direction is based on X,Y grid,  0 degrees is right,
		//  90 Stratight ahead ahead, 180 left, and 270  is directly behind.
		float Direction = 0;
		float Velocity = 127; //Motor speed, -127 to 127
		float rot = 0; //Rotational moro speed, -127 to 127

		if (vexRT[Btn5U]) {
			Direction = degreesToRadians(180); //Strafe Left
		} else if (vexRT[Btn6U]) {
			Direction = degreesToRadians(0); //Strafe Right
		} else {
			// Grab current right joystick vertical and horizontal values
			int vX = vexRT[Ch1];
			int vY = vexRT[Ch2];

			// Check absolute value (unsigned) to ensure they are not in the deadzone)
			if (abs(vX) < JSDEADZONE) vX = 0;
			if (abs(vY) < JSDEADZONE) vY = 0;

			// Overall robot velocity. Velocity is the hypoteneuse of the X=vX,vY Triangle
			// A positive Velocity means we are moving forward, negative, backwards.
			Velocity = sqrt((vX*vX)+(vY*vY)) * (vX <0 ? -1:1);

			// Using ARCTangent to get the direction of Velocity.  arctangent divides by X, so we have to make sure it is non-zero
			if (vX) {
				Direction = atan(vY/vX);
			} else {
				// if no X, then we are either moving straight up (90) or down if vY < 0
				Direction  = degreesToRadians(vY < 0 ? 270: 90);
			}
		}

		// Check to see if we are adding in rotation from left stick.  Rotation speed is the same for each wheel,
		// since they circle the robot
		rot = -vexRT[Ch4];
		if (abs(rot) < JSDEADZONE) rot = 0;

		// Mix roation in with driving.  We can't exceed max motor speed, so we may have to dial back Velocity to add
		// ability to add motor speed for rotation.  Get the magnitude of total motor speed needed, adn give Velocity
		// and roation each their proportional add-in for motor speed
		float magnitude = abs(Velocity) + abs(rot);
		if (magnitude) {
			Velocity = Velocity * abs(Velocity) / magnitude ;
		 	rot = rot * abs(rot) / magnitude;
		}

		// Calculate the speed for each motor by getting its vector for the direction the motor is placed
		float rs = (Velocity * cos(degreesToRadians(120)-Direction));  //Right wheel aims at 120 degrees
		float ls = (Velocity * cos(degreesToRadians(240)-Direction)); //Left aims at 240.
		float	ts = (Velocity * cos(/*degreesToRadians(0)*/-Direction));  //Tail wheel aims at 0

		// Assign the speed to each motor, mixing velocity and rotation
		motor[rightMotor] = rs + rot;
		motor[leftMotor] = ls + rot;
		motor[tailMotor] = ts + rot;
}

task main()
{

	startTask(Arm);
	while (true) {
		Drive();
		wait1Msec(20);
	}
	stopTask(Arm);
}
