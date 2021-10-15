
bool autoStop() {
        return
        vexRT[Btn7D] ||
        vexRT[Btn7L] ||
        vexRT[Btn7R] ||
        vexRT[Btn7U] ||
        vexRT[Btn5D] ||
        vexRT[Btn5U] ||
        vexRT[Btn8R] ||
        vexRT[Btn6U] ||
        vexRT[Btn6D] ;
}
bool Auto2 = false;
task autoStart() {					//GO FAST, THAN TURN LEFT							// Start task armStart
	USEBTN(Btn8L);
	USEBTN(Btn8U);
	USEBTN(Btn8D);
	workoriswear = 0;
	while(true) {
		UPDATEBTN(Btn8L);
		UPDATEBTN(Btn8D);
		UPDATEBTN(Btn8U);

		if(BTNPRESSED(Btn8L)) {
            autonomous = true;
            if(BTNPRESSED(Btn8U))   {
                while(autonomous)   {
                    workoriswear = 1;
                	int end = 0;
                    motor[LeftWheel] = 127;
                    motor[RightWheel] = 127;
                    while(autonomous && end++<22)   {
                        if (autoStop()) {
                            autonomous=false;
                            motor[LeftWheel] = 0;
                            motor[RightWheel] = 0;
                            break;
                        }
                        wait1Msec(100);
                        }
                        end = 0;
                        if (!autonomous){
                            motor[LeftWheel] = 0;
                            motor[RightWheel] = 0;
                            break;
                        }
                        motor[LeftWheel] = -127;
                        motor[RightWheel] = 127;
                        while(autonomous && end++<6)   {
                            if (autoStop()) {
                                autonomous=false;
                                motor[LeftWheel] = 0;
                                motor[RightWheel] = 0;
                                break;
                            }
                            wait1Msec(100);
                        }
                        motor[LeftWheel] = 0;
                        motor[RightWheel] = 0;

                        motor[PlowMotor] = 0;

                        if (!autonomous){
                            motor[LeftWheel] = 0;
                            motor[RightWheel] = 0;
                            motor[PlowMotor] = 0;
                            break;
                        }


                        end = 0;

                        motor[LeftWheel] = 80;
                        motor[RightWheel] = 127;
                        while(autonomous && end++<90)   {
                            if (autoStop()) {
                                autonomous=false;
                                motor[LeftWheel] = 0;
                                motor[RightWheel] = 0;
                                break;
                            }
                            wait1Msec(100);
                        }
                        end = 0;
                        motor[RightWheel] = 0;
                        motor[LeftWheel] = 0;
                        autonomous = false;
                        wait1Msec(20);
                    }
                }
            else if(BTNPRESSED(Btn8D))   {
            	while(autonomous)   {
    	int end2 = 0;
    	motor[LeftWheel] = 127;
    	motor[RightWheel] = 127;
        while(autonomous && end2++<22)   {
            if (autoStop()) {
                autonomous=false;
                motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
                break;
            }
            wait1Msec(100);
        }
        end2 = 0;
        if (!autonomous){
            motor[LeftWheel] = 0;
            motor[RightWheel] = 0;
            break;
        }
        motor[LeftWheel] = 127;
        motor[RightWheel] = -127;
        while(autonomous && end2++<6)   {
            if (autoStop()) {
                autonomous=false;
                motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
                break;
            }
            wait1Msec(100);
        }
        motor[LeftWheel] = 0;
        motor[RightWheel] = 0;


        motor[PlowMotor] = 0;
    	end2 = 0;

        motor[LeftWheel] = 80;
        motor[RightWheel] = 127;
    	while(autonomous && end2++<90)   {
            if (autoStop()) {
                autonomous=false;
            	motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
            	break;
            }
            wait1Msec(100);
    	}
    	end2 = 0;
        motor[RightWheel] = 0;
        motor[LeftWheel] = 0;
        autonomous = false;
        Auto2 = false;
    }
    wait1Msec(20);



    }}
        }



}
