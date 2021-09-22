#pragma config(Motor,  port2,           rightwheel,    tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port9,           leftwheel,     tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port4,           HandServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           WristServo,    tmotorServoStandard, openLoop)


task autoStart()		{
//hi


int i = 1;
int j =1;


while(true)	{

        while(i < 100000)		{
            motor(rightwheel)=120;
            motor(leftwheel)=120;
            i++;
}
			while(j<120000)      {
            motor(rightwheel)=-120;
            motor(leftwheel)=-120;
            j++;
}


}



















}