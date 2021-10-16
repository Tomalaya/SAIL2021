
bool autoStop(bool close) {
        if(close || (vexRT[Btn7D] || vexRT[Btn7L] || vexRT[Btn7R] || vexRT[Btn7U] || vexRT[Btn5D]
         	|| vexRT[Btn5U] || vexRT[Btn8R] || vexRT[Btn6U] || vexRT[Btn6D]) &&
         	(autonomous))	{
        	motor[LeftWheel] = 0;
        	motor[RightWheel] = 0;
        	autonomous = false;
        	return true;
        }
        return false;
}
#define go(ls, rs, t)						\
	motor[LeftWheel] = ls;				\
  motor[RightWheel] = rs;				\
  for(end = 0; end<t; end++)	{	\
  	if (autoStop(false)) {			\
    	return;										\
    }														\
    wait1Msec(100);							\
  }
void pipefetch()	{
	int end = 0;
	go(127, 127, 22);
    go(-127, 127, 6);
    go(80, 127, 90);
    autoStop(true);
}
void startlight()	{
	int end = 0;

	go(60, 60, 3); // Go Forward
  go(127, 127, 8); // Go Forward
  go(63, -63, 10); // Go Right
  go(127, 127, 17);  // Go Forward
  go(50, 50, 10);
  autoStop(true);
}
/*void randomValues()		{
	int end = 0;
	go(9999999, 99999999999999, 99999999999999999999999);
	go(1, 1, 1);
	go(31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679, 31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679, 1);
	go(9938, 57623678, 574856557556547647565);
}*/
task autoStart() {
	USEBTN(Btn8L);
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	while(true) {
		UPDATEBTN(Btn8L);
		UPDATEBTN(Btn8D);
		UPDATEBTN(Btn8U);

		if (BTNPRESSED(Btn8L)) {
            autonomous = true;
        }
        if(autonomous)	{
            if(BTNPRESSED(Btn8U))   {
            	pipefetch();
            }else if(BTNPRESSED(Btn8D))	{
            	startlight();
            }/*else if(BTNPRESSED(Btn5D))	{
				randomValues();
            }*/
        }
    }
}
