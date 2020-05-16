#include <reg52.h>

sbit light1=P2^0;
sbit light2=P2^1;

sbit light5=P2^2;
sbit light6=P2^3;

sbit     sensor1=P1^5;
sbit     sensor2=P1^6;

sbit IN1=P1^1;
sbit IN2=P1^2;

sbit IN3=P1^3;
sbit IN4=P1^4;
sbit PWMA=P2^4;
sbit PWMB=P2^5;

void gostraight();
void goleft();
void goright();
void stop();
void backleft();
void backright();

void turnleft();
void turnright();

void maxleft();
void maxright();
void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //
		for(j=112;j>0;j--);
}


void newdelay(unsigned int xms)		
{
	  unsigned int k;
     	while(k--);
}

void time1clock();//84  88         188     196
	unsigned int pwmA=94;
	unsigned int pwmB=100;
	unsigned int num=0;

timeleft=1;
timeright=1;

int main()
{
	time1clock();
while(1)
{
     if(light1==0&&light2==1&&light5==1&&light6==0)
{

		if(sensor2==0)
	{
		
	gostraight();

	}
	else{
IN1=0;
IN2=0;
IN3=0;
IN4=0;
delay(80);
IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(30);
IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(10);		
		
	}

}


else if(light1==0&&light2==1&&light5==0&&light6==0)
{
	if(sensor2==0)
	{
		
goleft();

	}	
	else{IN1=0;
IN2=0;
IN3=0;
IN4=0;
delay(80);
IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(30);
IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(10);		
		
	}
	

}
else if(light1==1&&light2==1&&light5==0&&light6==0)
{
	if(sensor2==0)
	{
	
		
turnleft();
	}
	else{IN1=0;
IN2=0;
IN3=0;
IN4=0;
delay(80);
IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(30);
IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(10);		
		
	}

}

else if(light1==1&&light2==0&&light5==0&&light6==0)
{
	if(sensor2==0)
	{
	
		
turnleft();
	}
	else{IN1=0;
IN2=0;
IN3=0;
IN4=0;
delay(80);
IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(30);
IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(10);		
		
	}
}
else if(light1==1&&light2==1&&light5==1&&light6==0)
{
	if(sensor2==0)
	{
	
		
turnleft();
	}
	else{
IN1=0;
IN2=0;
IN3=0;
IN4=0;
delay(80);
IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(30);
IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(10);		
		
	}
}

	

 else if(light1==0&&light2==0&&light5==1&&light6==0)
{
	goright(); // 	
		
}
 else if(light1==0&&light2==0&&light5==0&&light6==1)
{
turnright(); 
}
else if(light1==0&&light2==0&&light5==1&&light6==1)
{
turnright(); 
}
else if(light1==0&&light2==1&&light5==1&&light6==1)
{
	
	/*if(timeright==1)
	{
		turnleft();
	timeright++;	
	
	}*/
	/*if(sensor1==1&&timeright==1)
	{
	gostraight();
	timeright++;
	}
	else
{
	
}*/
		turnright(); 
	
}
else if (sensor1==1&&light1==1&&light2==1&&light5==1&&light6==1&&sensor2==1)
{
stop();
}
else if (light1==1&&light2==1&&light5==1&&light6==1)
{
stop();
	delay(3);
}
//脱离轨道
else if (sensor1==1&&light1==0&&light2==0&&light5==0&&light6==0&&sensor2==0)
{
  maxleft();//turnleft();
}


else if (sensor1==0&&light1==0&&light2==0&&light5==0&&light6==0&&sensor2==1)
{
	
maxright();//turnright();
	
}

else if (sensor1==1&&sensor2==1)
{
	maxright();
	
}










else if (light1==0&&light2==0&&light5==0&&light6==0)
{
gostraight();
}

else 
{
gostraight();
}
}
}


//子函数

void time1clock()
{	
EA=1;
ET1=1;						  
TMOD=0x10;					
	TH1=0xFF;//倒计时1ms
	TL1=0xff;
TR1=1;					  	
}

void time1() interrupt 3	
{

	TH1=0xFF;//倒计时1us
	TL1=0xff;
num++;
if(num>400)
{num=0;
}
if(num<=pwmA)
{
PWMA=1;

}		
else{ 
PWMA=0;   }


if(num<=pwmB)
{
PWMB=1 ;
}	
else
{PWMB=0;
}
}

void maxright()
{

IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(3);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}


void maxleft()
{

IN1=0;
IN2=1;
IN3=1;
IN4=0;
delay(6);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}


void turnright()
{

IN1=1;
IN2=0;
IN3=0;
IN4=1;
delay(1);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}


void turnleft()
{

IN1=0;
IN2=1;
IN3=1;
IN4=0;
delay(1);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}

void gostraight()
{

IN1=0;
IN2=1;
IN3=0;
IN4=1;
delay(1);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}
void goright()
{

IN1=0;
IN2=0;
IN3=0;
IN4=1;
delay(1);
IN1=0;
IN2=0;
IN3=0;
IN4=0;

}
void goleft()
{

IN1=0;
IN2=1;
IN3=0;
IN4=0;
delay(1);
IN1=0;
IN2=0;
IN3=0;
IN4=0;

}


void stop()
{
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														;
IN1=0;
IN2=0;
IN3=0;
IN4=0;

}
void backleft()
{

IN1=1;
IN2=0;
IN3=0;
IN4=0;
	delay(3);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}
void backright()
{

IN1=0;
IN2=0;
IN3=1;
IN4=0;
	delay(3);
IN1=0;
IN2=0;
IN3=0;
IN4=0;
}

