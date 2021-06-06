#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "Micro_Controller_Init.h"

void Micro_Controller_Init(void){
	

	SYSCTL_RCGCGPIO_R  |= 0X23; //clock enable for A,B,F
	while ( (SYSCTL_PRGPIO_R &0x23) == 0 ){}
		
		 /* PORTF_Init */
		
	GPIO_PORTF_LOCK_R  = 0x4C4F434B ;
	GPIO_PORTF_CR_R    = 0x0F ;
	GPIO_PORTF_DIR_R   = 0x0E ;
	GPIO_PORTF_DEN_R   = 0x0F ;
	GPIO_PORTF_PUR_R   = 0x01 ;
	GPIO_PORTF_AMSEL_R = 0X00 ;
	GPIO_PORTF_AFSEL_R = 0x00 ;
	GPIO_PORTF_PCTL_R  = 0X00 ;
		
		
		/* LCD's ports initilization (A&B) */
		
		GPIO_PORTB_DIR_R   = 0xFF ;    // PB0-PB7 --> D0-D7
		GPIO_PORTB_DEN_R   = 0xFF ; 
		GPIO_PORTB_AMSEL_R = 0X00 ;
		GPIO_PORTB_AFSEL_R = 0x00 ;
		GPIO_PORTB_PCTL_R  = 0X00 ;
		
	
		GPIO_PORTA_DIR_R   |=0xE0   ; // PA7,PA6,PA5 --> E, R/W, RS 
		GPIO_PORTA_DEN_R   |=0xE0   ; 
		GPIO_PORTA_AMSEL_R &= ~0XE0 ;
		GPIO_PORTA_AFSEL_R &= ~0XE0 ;  
		GPIO_PORTA_PCTL_R  &= ~0XE0 ;
		
		// don't forget to reintialize A port after doing the UART part (not done yet)

}
