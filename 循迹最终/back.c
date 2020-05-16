#include<reg52.h>



sbit IN1=P1^1;
sbit IN2=P1^2;

sbit IN3=P1^3;
sbit IN4=P1^4;


void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //
		for(j=112;j>0;j--);
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

