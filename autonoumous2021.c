#pragma config(Motor,  port2,           rightwheel,    tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port9,           leftwheel,     tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port4,           HandServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           WristServo,    tmotorServoStandard, openLoop)


task autoStart()		{



int i = 1;
int j =1


while(true)	{

        while(i < 100000)
            motor(rightwheel)=127|;
            motor(leftwheel)=127;
            i++;
}       else()      {
            motor(rightwheel)=-127;
            motor(leftwheel)-127;
            j++;
}


}



















}