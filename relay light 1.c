#include<reg51.h>
sbit ir=P1^0;
sbit load=P2^0;
void main()
{
   load=0;
   ir=0;
 while(1)
 {
   if(ir==1)
   {
     load=1;
		 while(ir==1);
   }
	 else
	 {
		 load=0;
	 }
 }
 }