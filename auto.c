
bool autoStop() {

        return vexRT[Btn7U]
        || vexRT[Btn7D]
        || vexRT[Btn7L]
        || vexRT[Btn7R]
        || vexRT[Btn8D]
        || vexRT[Btn8L]
        || vexRT[Btn8R]
        || vexRT[Btn6U]
        || vexRT[Btn6D]
        || vexRT[Btn5U]
          || vexRT[Btn5D];

}


task autoStart() {												// Start task armStart
	USEBTN(Btn8U);
	bool autonomous = false;
	while(true) {
		UPDATEBTN(Btn8U);

		if(BTNPRESSED(Btn8U)) {

            autonomous = true;

			int end = 0;
			playSound(soundBlip);									// Play a sound to indicate task is running

			motor[LeftWheel] = 120;							// Set Left Motor to 120
			motor[RightWheel] = 120;						// Set Right Motor to 120
			 while(end++<20)   {
                if (autoStop()) {autonomous = false; break;}
			    wait1Msec(1000);

			 }
             if (!autonomous){
                break;
             }


             motor[LeftWheel] = -120;							// Set Left Motor to 120
             motor[RightWheel] = -120;                           // Set Right Motor to 120


			 end = 0;
			 while(end++<20)   {
                if (autoStop()) {autonomous=false; break;}
                wait1Msec(100);





		    }

	    }
        wait1Msec(20);	                                        //Wait 20 Milliseconds
    }

}
