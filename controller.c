/*******************************************************************************
 *   ####   ######  ##      #####
 *  ##  ##    ##    ##      ##  ##
 *  ##        ##    ##      ##  ##
 *  ##        ##    ##      #####
 *  ##  ##    ##    ##      ##  ##
 *   ####     ##    ######  ##  ##
 *******************************************************************************/
 /* Controller/joystick helper functions */

//This defines the slots for button states, so we can see when they go up or down
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

//This is where we store the button state, in a bitmask. 0 is up, 1 is down
int buttonState = 0;
#define BS(x) (buttonState & (1<<x))
#define BSDOWN(x) (buttonState |= (1<<x))
#define BSUP(x) (buttonState &= ~(1<<x))

//Check if a button has changed state or is depressed.
//		Return  1 (>0) when a button is first pressed
//		Return -1 (<0) when a button is first pressed
//		Return  0 if the state has not changed
int chkButton (int cs, int btn) {
	if (cs && !(BS(btn))) {
		BSDOWN(btn);
		return 1; //This button just went down
	} else if (!cs && BS(btn)) {
		BSUP(btn);
		return -1; //button was just released
	}

	return 0; //This button state has not changed
}

//Sometimes ignore the joystick because it may float around the middle. Anything less than DEADZONE is considered
//not a real value
#define JSDEADZONE 20

typedef struct {
	float Direction;  //The angluar direction the joystick is pointing, in radians
	float Magnitude;  //The magnitude the joystick is pushed in that direction, 0 to 127
} JoystickState;


void getJoystickState(bool bRightJoystick, JoystickState &js) {
	// Grab current right joystick vertical and horizontal values
	int vX = vexRT[bRightJoystick ? Ch1 : Ch3];
	int vY = vexRT[bRightJoystick ? Ch2 : Ch4];

	// Check absolute value (unsigned) to ensure they are not in the deadzone)
	if (abs(vX) < JSDEADZONE) vX = 0;
	if (abs(vY) < JSDEADZONE) vY = 0;

	// Gte the magnitude, or distance from center, which is the hypoteneuse of the X=vX,vY Triangle
	// A positive magnitude means we are positive in the X direction.
	js.Magnitude = sqrt((vX*vX)+(vY*vY))  * (vX <0 ? -1:1);

	// Using ARCTangent to get the direction of the joystick. arctangent divides by X, so we have to make sure it is non-zero
	if (vX) {
		js.Direction = atan(vY/vX);
	} else {
		// if no X, then we are either moving straight up (90) or down if vY < 0
		js.Direction = degreesToRadians(vY < 0 ? 270: 90);
	}
}
