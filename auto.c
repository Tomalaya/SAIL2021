bool bestAuto = true;

bool autoStop(bool close) {
        if(close || (vexRT[Btn7D] || vexRT[Btn7L] || vexRT[Btn7R] || vexRT[Btn7U] || vexRT[Btn5D]
             || vexRT[Btn5U] || vexRT[Btn6U] || vexRT[Btn6D]) &&
             (autonomous))    {
            motor[LeftWheel] = 0;
            motor[RightWheel] = 0;
            motor[ArmMotor] = 0;
            autonomous = false;
            return true;
        }
        return false;
    }
#define go(ls, rs, t)                \
    motor[LeftWheel] = ls;            \
      motor[RightWheel] = rs;            \
      for(end = 0; end<t; end++)    {    \
          if (autoStop(false)) {        \
            return;                    \
        }                            \
    wait1Msec(100);                    \
  }
int thirdStep[] = {23, 6, 38, 5, 9, 5};

void pipefetch()	{
	int end = 0;
	// Comments are the iteration amounts for our course.
	// New iteration numbers are for the Demo Day course.
		if(bestAuto) {
			go(100, 127, 18); // 20
	  	go(-127, 127, 7); // 6
	  	go(127, 127, 80);   // 32
	  /*	go(-127, -127, 5);
	  	motor[ArmMotor] = -127;
	  	go(-127, 127, 12);    // 9
	  	go(127, 127, 7);			// 5
	    handPosition = -127;
	  	WristPosition = -37;
	  	motor[ArmMotor] = 0;
	  	motor[HandServo] = handPosition;
	  	motor[WristServo] = WristPosition;*/
	  	slowMode = 0.5;
	  	autoStop(true);
  	} else {
	  	go(100, 127, 20);
	  	go(-127, 127, 6);
	  	go(127, 127, 32);
	  	go(-127, -127, 5);
	  	motor[ArmMotor] = -127;
	  	go(-127, 127, 9);
	  	go(127, 127, 5);
	    handPosition = -127;
	  	WristPosition = -37;
	  	motor[ArmMotor] = 0;
	  	motor[HandServo] = handPosition;
	  	motor[WristServo] = WristPosition;
	  	slowMode = 0.5;
	  	autoStop(true);
  	}
}

int step1[] = {3, 9, 2, 14, 3, 3};

void startlight()    {        //45 to the left, foreward, left, foreward
    int end = 0;
    go(-65, 65, step1[0]);  // 3 Turn Left
    go(127, 127, step1[1]); // 7 Forward
    go(65, -65, step1[2]);	// 2 Right
    go(127, 127, step1[3]);	// 15 Forward
    go(-65, 65, step1[4]);	// 6 Left
    go(65, 65, step1[5]); 	// 5 Forward
      autoStop(true);
}
int step2[] = {5, 3, 15, 6, 10};

void gotoauto()        {  //back up, turn right, foreward, left, foreward
    int end = 0;
    go(-65, -65, step2[0]);
    go(-65, -65, step2[1]);
    go(127, 127, step2[2]);
    go(-127, 127, step2[3]);
    go(127, 127, step2[4]);
    autoStop(true);

}
/*void randomValues()        {
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
        if(autonomous)    {
            if(BTNPRESSED(Btn8U))   {
                pipefetch();
            }else if(BTNPRESSED(Btn8D))    {
                startlight();
            }else if(BTNPRESSED(Btn8R))    {
                gotoauto();
            }/*else if(BTNPRESSED(Btn5D))    {
                randomValues();
            }*/
        }
        autoStop(false);
        wait1Msec(20);
    }
}
