/*******************************************************************************
 * #####   #####   ######  ##  ##  ######
 * ##  ##  ##  ##    ##    ##  ##  ##
 * ##  ##  ##  ##    ##    ##  ##  #####
 * ##  ##  #####     ##     ####   ##
 * ##  ##  ##  ##    ##     ####   ##
 * #####   ##  ##  ######    ##    ######
 *******************************************************************************/
/* Drive and movement functions */

float rs,ls,ts;
JoystickState js;

//This is the functionto control driving the robot. IN this case a 3 Omniwheeled Bot
void Drive()
{
	// This is the robot heading, in radians. Direction is based on X,Y grid, 0 degrees is right,
	// 90 Stratight ahead ahead, 180 left, and 270 is directly behind.
	js.Direction = 0;
	js.Magnitude = 127; //Motor speed, -127 to 127
	float rot = 0; //Rotational motoe speed, -127 to 127

	if (vexRT[Btn5U]) {
		js.Direction = degreesToRadians(180); //Strafe Left
	} else if (vexRT[Btn6U]) {
		js.Direction = degreesToRadians(0); //Strafe Right
	} else {
		getJoystickState(true, js);
	}

	// Check to see if we are adding in rotation from left stick. Rotation speed is the same for each wheel,
	// since they circle the robot
	rot = -vexRT[Ch4];
	if (abs(rot) < JSDEADZONE) rot = 0;

	// Mix roation in with driving. We can't exceed max motor speed, so we may have to dial back Velocity to add
	// ability to add motor speed for rotation. Get the magnitude of total motor speed needed, adn give Velocity
	// and roation each their proportional add-in for motor speed
	float magnitude = abs(js.Magnitude) + abs(rot);
	if (magnitude) {
		js.Magnitude = js.Magnitude * abs(js.Magnitude) / magnitude ;
		rot = rot * abs(rot) / magnitude;
	}

	// Calculate the speed for each motor by getting its vector for the direction the motor is placed
	rs = (js.Magnitude * cos(degreesToRadians(120)-js.Direction)); //Right wheel aims at 120 degrees
	ls = (js.Magnitude * cos(degreesToRadians(240)-js.Direction)); //Left aims at 240.
	ts = (js.Magnitude * cos(/*degreesToRadians(0)*/-js.Direction)); //Tail wheel aims at 0

	//Full power!
	if (abs(ts) < 40 && (abs(rs)>100 || abs(ls)>100)) {
		int diff = abs(rs) > abs(ls) ? 127-abs(rs) : 127-abs(ls);
		if (rs>0) rs += diff; else rs -= diff;
		if (ls>0) ls += diff; else ls -= diff;
	}
	// Assign the speed to each motor, mixing velocity and rotation
	motor[rightMotor] = rs + rot;
	motor[leftMotor] = ls + rot;
	motor[tailMotor] = ts + rot;
}
