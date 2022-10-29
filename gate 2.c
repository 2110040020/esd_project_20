#include<reg51.h>
sbit sensor=P1^0;
sbit relay1=P1^1;
sbit relay2=P1^2;
void delay();
void main()
{
relay1=0;
relay2=0;
while(1)
{
if(sensor==0)
{
relay1=1;
relay2=0;
delay();
relay1=0;
relay2=1;
delay();
}
	if(sensor==1)
	{
relay1=0;
relay2=0;

}
}
}
void delay()
{
unsigned int i,j;
for(i=0;i<100000;i++)
	{
}
}

