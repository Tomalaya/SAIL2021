
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
			motor[LeftWheel] = 120;							// Set Left Motor to 120
			motor[RightWheel] = 120;						// Set Right Motor to 120

			while(autonomous && end++<20)   {
       	        if (autoStop()) {autonomous = false;
       	        motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
       	        break;}
			    wait1Msec(100);
			}
            if (!autonomous){
        	    motor[LeftWheel] = 0;
        	    motor[RightWheel] = 0;
        	    break;
            }
            motor[LeftWheel] = -120;							// Set Left Motor to 120
            motor[RightWheel] = -120;                           // Set Right Motor to 120
			end = 0;
			while(autonomous && end++<20)   {
        	    if (autoStop()) {autonomous=false;
        	    motor[LeftWheel] = 0;
                motor[RightWheel] = 0;
        	    break;}
          	        wait1Msec(100);
		    }
            motor[RightWheel] = 0;
            motor[LeftWheel] = 0;
            autonomous = false;
	    }
        wait1Msec(20);	                                        //Wait 20 Milliseconds
    }

}
