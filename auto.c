
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
#define go(ls, rs, t)				\
	motor[LeftWheel] = ls;			\
    motor[RightWheel] = rs;			\
    for(end = 0; end<t; end++)	{	\
    	if (autoStop(false)) {		\
        	return;					\
        }							\
        wait1Msec(100);				\
    }
void pipefetch()	{
	int end = 0;
	go(127, 127, 22);
    go(-127, 127, 6);
    go(80, 127, 90);
    autoStop(true);
}
void startlight()	{		//TODO
	int end = 0;
    go(127, 127, 22);
    go(-127, 127, 6);
    go(80, 127, 90);
    autoStop(true);
}
task autoStart() {
	USEBTN(Btn8L);
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	workoriswear = 0;
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
            }
        }
    }
}
