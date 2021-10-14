
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
        vexRT[Btn6D] ||
        vexRT[Btn5U] ||
        vexRT[Btn5D];
}

task autoStart() {					//GO FAST, THAN TURN LEFT							// Start task armStart
	USEBTN(Btn8L);
	while(true) {
		UPDATEBTN(Btn8L);

		if(BTNPRESSED(Btn8L)) {
            autonomous = true;
        }
        while(autonomous)   {
			int end = 0;
			playSound(soundBlip);									// Play a sound to indicate task is running
			motor[LeftWheel] = -127;
			motor[RightWheel] = -127;
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
            motor[PlowMotor] = -127;
            while(autonomous && end++<5)
                if(autoStop())  {
                autonomous=false;
                motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
                }
            if (!autonomous){
        	    motor[LeftWheel] = 0;
        	    motor[RightWheel] = 0;
        	    break;
            }
            autonomous = false;
			end = 0;
            motor[LeftWheel] = -127;
            motor[RightWheel] = -127;
			while(autonomous && end++<18)   {
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

}
