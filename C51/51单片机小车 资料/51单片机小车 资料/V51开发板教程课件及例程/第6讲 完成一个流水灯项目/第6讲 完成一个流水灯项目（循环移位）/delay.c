#include"delay.h"

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms¼´ÑÓÊ±Ô¼xmsºÁÃë
		for(j=112;j>0;j--);
}