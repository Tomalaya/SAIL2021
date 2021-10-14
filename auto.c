
bool autoStop() {
        return
        vexRT[Btn7D] ||
        vexRT[Btn7L] ||
        vexRT[Btn7R] ||
        vexRT[Btn7U] ||
        vexRT[Btn8D] ||
        vexRT[Btn8U] ||
        vexRT[Btn8R] ||
        vexRT[Btn6U] ||
        vexRT[Btn6D] ;
}

task autoStart() {					//GO FAST, THAN TURN LEFT							// Start task armStart
	USEBTN(Btn8L);
	USEBTN(Btn5U);
	USEBTN(Btn5D);
	while(true) {
		UPDATEBTN(Btn8L);
		UPDATEBTN(Btn5D);
		UPDATEBTN(Btn5U);

		if(GETLASTBTN(Btn8L)) {
            autonomous = true;
            if(BTNPRESSED(Btn5U))   {Auto1 = true;}
            else if(BTNPRESSED(Btn5D))  {Auto2 = true;}

            while(Auto1)   {
			    int end = 0;
			    playSound(soundBlip);									// Play a sound to indicate task is running
			    motor[LeftWheel] = 127;
			    motor[RightWheel] = 127;
                while(autonomous && end++<22) {
                    if (autoStop()) {
                        autonomous=false;
                        motor[LeftWheel] = 0;
                        motor[RightWheel] = 0;
                        break;
                    }
        }
        while(autonomous)   {
			int end = 0;
			playSound(soundBlip);									// Play a sound to indicate task is running
			motor[LeftWheel] = 127;			motor[RightWheel] = 127;
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

                motor[PlowMotor] = 0;
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
	        }
        wait1Msec(20);	                                        //Wait 20 Milliseconds

    }
    while(autonomous && Auto2)   {
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
    /*
                motor[PlowMotor] = -127;
                while(autonomous && end2++<20)   {
                    if(autoStop())  {
                        autonomous=false;
                        motor[LeftWheel] = 0;
                        motor[RightWheel] = 0;
                    }
                    wait1Msec(100);
                }
    */ 

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


}
