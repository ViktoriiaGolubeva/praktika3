#include <8051.h>

void s1out(short position,short maxPosition)
{
	short str[8]={160+2,160+9,160+11,160+19,160+15,160+17,160+9,160+32};
	unsigned int i=0;
	unsigned short length = 8;
	short current = 0;
	P0=0x80;
	P2=0x1;
	P2=0x0;

	if(position+length>maxPosition)
	{
		for(i=length-(position+length-maxPosition);i<length;i++)
		{
			if(current == maxPosition) break;
			current++;
			P0=str[i];
			P2=0x3;
			P2=0x2;
		}
		i = (position+length-maxPosition)-1;
	}

	for(;i<position; i++)
	{
		if(current == maxPosition) break;
		current++;
		P0=6;
		P2=0x3;
		P2=0x2;
	}
	for (i=0;i<length;i++)
	{
		if(current == maxPosition) break;
		current++;
		P0 = str[i];
		P2=0x3;
		P2=0x2;
	}
}


void s2out()
{
unsigned char *str2="222";
unsigned int i;
P0=0xC6;
P2=0x1;
P2=0x0;


for(i=0;i<3;i++)
{
P0 = str2[i];
P2=0x3;
P2=0x2;
}
}

void main()
{

short position = 0;
short maxPosition = 16;
P0 = 0x38;
P2 = 0x1;
P2 = 0x0;
s2out();
while(1){
s1out(position,maxPosition);
if(position<maxPosition) position++;
else
position=0;

}
}

