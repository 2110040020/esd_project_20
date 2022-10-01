#include<reg51.h>
#define lcd P1

sbit led0=P3^2;
sbit led1=P3^3;
sbit led2=P3^4;
sbit led3=P3^5;

sbit sw1=P2^0;
sbit sw2=P2^1								;
sbit sw3=P2^2;
sbit sw4=P2^3;

sbit M_a=P3^0;
sbit M_b=P3^1;

sbit rs=P2^5;
sbit e=P2^7;
sbit rw=P2^6;
void Delay (unsigned int t);

void cmd (unsigned int c)
{
lcd=c;
rs=0;
rw=0;
e=1;
Delay(10);
e=0;
}
void ldata (unsigned int c)
{
lcd=c;
rs=1;
rw=0;
e=1;
Delay(10);
e=0;
}
void string (unsigned char *s)
{
while(*s)
{
ldata(*s);
++s;
Delay(10);
}
}
void Delay (unsigned int t)
{
unsigned int i,j;
for(i=0;i<t;i++)
for(j=0;j<750;j++);
}

unsigned char checkwaterlevel(void)
{
if(sw1==1)
{
if(sw1==1&sw2==1)
{
if(sw1==1&sw2==1&sw3==1)
{
if(sw1==1&sw2==1&sw3==1&sw4==1)
{
return 100;
}
return 75;
}
return 50;
}
return 25;
}
return 0;
}
void status(unsigned char status)
{
switch(status)
{
case 0:
led0 =0;
led1 =0;
led2 =0;
led3 =0;
cmd(0*80);
string("0%");
break;
case 25:
led0 =1;
led1 =0;
led2 =0;
led3 =0;
cmd(0*80);
string("25%");
break;
case 50:
led0 =1;
led1 =1;
led2 =0;
led3 =0;
cmd(0*80);
string("50%");
break;
case 75:
led0 =1;
led1 =1;
led2 =1;
led3 =0;
cmd(0*80);
string("75%");
break;
case 100:
led0 =1;
led1 =1;
led2 =1;
led3 =1;
cmd(0*80);
string("100%");
break;
}
}
void motorrun()
{
   M_a=1;
   M_b=0;
   M_a=1;
   M_b=0;
   }
void motorstop()
{
	M_a=M_b=0;
}
void main()
{
unsigned char waterstatus = 0*00;
unsigned char tmpwaterstatus = 0*01;
cmd(0x38);
cmd(0x0c);
cmd(0x01);
 while(1)
 {
 waterstatus=checkwaterlevel();
 if(waterstatus != tmpwaterstatus)
 {
 status(waterstatus);
 tmpwaterstatus = waterstatus;
 if(tmpwaterstatus!= 100)
 {
 motorrun();
 }
 else
 {
 motorstop();
 }
 }
 }
 }
 






