int iterationsNumber = 0;
bool autoStop(bool close) {
        if(close || (vexRT[Btn7D] || vexRT[Btn7L] || vexRT[Btn7R] || vexRT[Btn7U] || vexRT[Btn5D]
         	|| vexRT[Btn5U] || vexRT[Btn6U] || vexRT[Btn6D]) &&
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
	go(127, 127, 24); // Straight, 22 Iterations
  	go(-127, 127, 6); // Left, 5 Iterations
  	go(127, 127, 38);   // Half Speed, Straight, 35 Iterations
  	go(-127, -127, 5);
  	go(-127, 127, 12);    // Spin Around, 12 Iterations
  	autoStop(true);
}
void startlight()	{
	int end = 0;
	int iterations[8] = {0, 5, 10, 15, 20, 25, 30, 35};
	go(60, 60, 3); // Go Forward
  	go(127, 127, 7); // Go Forward
  	go(63, -63, 9); // Go Right
  	go(127, 127, 18);  // Go Forward
  	go(50, 50, 10);
  	autoStop(true);
}
void gotoauto()		{
	int end = 0;

	go(-127, -127, 10);
	go(127, 20, 10);
	go(127, 127, 5);
	go(10, 127, 10);
	go(127, 127, 10);

}
/*void randomValues()		{
	for(int i = 0; i < rand; i++) {
		go(rand, rand, rand);
	}
}*/

/* public static void main(String[] args) {
 	System.out.println("Java is better than c, Tom!");
    try {
   		AnnoyTom.run();
   	} catch(NullPointerException n) {
  		n.printStackTrace();
 	}
   }
 */
task autoStart() {
	USEBTN(Btn8L);
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	USEBTN(Btn8R);
	while(true) {
		UPDATEBTN(Btn8L);
		UPDATEBTN(Btn8D);
		UPDATEBTN(Btn8U);
		UPDATEBTN(Btn8R);

		if (BTNPRESSED(Btn8L)) {
            autonomous = true;
        }
        if(autonomous)	{
            if(BTNPRESSED(Btn8U))   {
            	pipefetch();
            }else if(BTNPRESSED(Btn8D))	{
            	startlight();
            }else if(BTNPRESSED(Btn8R))	{
            	gotoauto();
            }/*else if(BTNPRESSED(Btn5D))	{
				randomValues();
            }*/
        }
        autoStop(false);
        wait1Msec(20);
    }
}
