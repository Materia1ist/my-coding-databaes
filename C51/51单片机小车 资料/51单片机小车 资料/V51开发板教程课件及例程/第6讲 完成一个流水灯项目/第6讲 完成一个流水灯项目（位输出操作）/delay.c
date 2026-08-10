#include "main.h"
void delay(uint xms)				
{
	uint i,j;
	for(i=xms;i>0;i--)		      //i=xms¼´ÑÓÊ±Ô¼xmsºÁÃë
		for(j=112;j>0;j--);
}

void delay560us(void)				
{
	uint j;
	for(j=63;j>0;j--);
}

void delay4500us(void)
{
  	uint j;
	for(j=516;j>0;j--);
}
 