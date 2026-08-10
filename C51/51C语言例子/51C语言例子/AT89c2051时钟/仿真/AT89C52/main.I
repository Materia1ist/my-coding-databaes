
#line 1 "..\main.c" /0




 
 
 
  
#line 1 "C:\KEIL\C51\INC\ATMEL\REG51.H" /0






 
 
 
 
 
 
 sfr P0   = 0x80;
 sfr P1   = 0x90;
 sfr P2   = 0xA0;
 sfr P3   = 0xB0;
 sfr PSW  = 0xD0;
 sfr ACC  = 0xE0;
 sfr B    = 0xF0;
 sfr SP   = 0x81;
 sfr DPL  = 0x82;
 sfr DPH  = 0x83;
 sfr PCON = 0x87;
 sfr TCON = 0x88;
 sfr TMOD = 0x89;
 sfr TL0  = 0x8A;
 sfr TL1  = 0x8B;
 sfr TH0  = 0x8C;
 sfr TH1  = 0x8D;
 sfr IE   = 0xA8;
 sfr IP   = 0xB8;
 sfr SCON = 0x98;
 sfr SBUF = 0x99;
 
 
 
 
 sbit CY   = 0xD7;
 sbit AC   = 0xD6;
 sbit F0   = 0xD5;
 sbit RS1  = 0xD4;
 sbit RS0  = 0xD3;
 sbit OV   = 0xD2;
 sbit P    = 0xD0;
 
 
 sbit TF1  = 0x8F;
 sbit TR1  = 0x8E;
 sbit TF0  = 0x8D;
 sbit TR0  = 0x8C;
 sbit IE1  = 0x8B;
 sbit IT1  = 0x8A;
 sbit IE0  = 0x89;
 sbit IT0  = 0x88;
 
 
 sbit EA   = 0xAF;
 sbit ES   = 0xAC;
 sbit ET1  = 0xAB;
 sbit EX1  = 0xAA;
 sbit ET0  = 0xA9;
 sbit EX0  = 0xA8;
 
 
 sbit PS   = 0xBC;
 sbit PT1  = 0xBB;
 sbit PX1  = 0xBA;
 sbit PT0  = 0xB9;
 sbit PX0  = 0xB8;
 
 
 sbit RD   = 0xB7;
 sbit WR   = 0xB6;
 sbit T1   = 0xB5;
 sbit T0   = 0xB4;
 sbit INT1 = 0xB3;
 sbit INT0 = 0xB2;
 sbit TXD  = 0xB1;
 sbit RXD  = 0xB0;
 
 
 sbit SM0  = 0x9F;
 sbit SM1  = 0x9E;
 sbit SM2  = 0x9D;
 sbit REN  = 0x9C;
 sbit TB8  = 0x9B;
 sbit RB8  = 0x9A;
 sbit TI   = 0x99;
 sbit RI   = 0x98;
 
 
#line 8 "..\main.c" /0
 
 
 
 
 code unsigned char table[]=
 {0xFD,0x25,0xBB,0xAF,0x67,0xCF,0xDF,0xA5,0xFF,0xEF};
 
 
 unsigned char l_posit=0;	 
 unsigned char ly_tt=0;		 
 unsigned char ly_miao=0;	 
 unsigned char ly_fen=25;	 
 unsigned char ly_shi=12;	 
 
 
 sbit SMG_q = P3^0;	 
 sbit SMG_b = P3^1;	 
 sbit SMG_s = P3^2;	 
 sbit SMG_g = P3^3;	 
 
 
 void display(unsigned char shi,unsigned char fen); 
 void delay(unsigned int timer); 
 void init();					 
 
 
 void main()
 {
 init();					 
 while(1){
 if(ly_tt==20){			 
 ly_tt=0;
 ly_miao++;
 if(ly_miao==60){	 
 ly_miao=0;
 ly_fen++;
 if(ly_fen==60){	 
 ly_fen=0;
 ly_shi++;
 if(ly_shi==24) 
 ly_shi=0;
 }
 }
 }
 display(ly_shi,ly_fen);		 
 delay(100);
 }
 }
 
 
 void init()
 {
 ly_tt=0;
 TMOD=0X01;		 
 TH0=(65536-50000)/256;	 
 TL0=(65536-50000)%256;
 EA=1;		 
 ES=0;		 
 ET0=1;		 
 TR0=1;		 
 }
 
 
 void timer() interrupt 1
 {
 TH0=(65536-50000)/256;	 
 TL0=(65536-50000)%256;
 ly_tt++;					 
 }
 
 
 void display(unsigned char shi,unsigned char fen)
 {
 P1=0X00;			 
 switch(l_posit){
 case 0:		 
 SMG_q=0;
 SMG_b=1;	
 SMG_s=1;		
 SMG_g=1;
 P1=table[shi/10];	 
 break;
 case 1:		 
 SMG_q=1;
 SMG_b=0;	
 SMG_s=1;		
 SMG_g=1;
 P1=table[shi%10];
 break;
 case 2:		 
 SMG_q=1;
 SMG_b=1;	
 SMG_s=0;		
 SMG_g=1;
 P1=table[fen/10];
 break;
 case 3:		 
 SMG_q=1;
 SMG_b=1;	
 SMG_s=1;		
 SMG_g=0;
 P1=table[fen%10];
 break;
 }
 l_posit++;		 
 if(l_posit>3)
 l_posit=0;	
 }
 
 void delay(unsigned int timer){		
 while(timer--);
 }
