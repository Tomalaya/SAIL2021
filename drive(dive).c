#pragma config(Motor,  port2,           leftwheel,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rightwheel,    tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//This
//    Area
//        Is
//          The
//             Code
//                 For
//                    The
//                       Wheels
task main()
{
// All values are reversed
	while (true)	{
		while (vexRT[joy1_x2]>20)   {
		//forwards
			motor(leftwheel)=-127;
			motor(rightwheel)=-127;
		}

		while (vexRT[joy1_x2]<-20)		{
		//backwards
			motor(leftwheel)=127;
			motor(rightwheel)=127;
		}


		while (vexRT[joy1_x2]<20 && vexRT[joy1_x2]>-20)   {
		// N U L L
			motor(leftwheel)=0;
			motor(rightwheel)=0;
		}


		while (vexRT[joy1_y1]<-20)   {
		//turn left
			motor(leftwheel)=127;
			motor(rightwheel)=-127;
		}

		while (vexRT[joy1_y1]>20)		{
		//turn right
			motor(leftwheel)=-127;
			motor(rightwheel)=127;

		}
	}

    while (true)        {

        while(vexRT[Btn6U])    {
            motor (rightwheel)=127;
				}

    }






















}