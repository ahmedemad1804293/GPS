#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "Lcd.h"
#include "Delay.h"


void LCD_Data(unsigned char data  ){
	
	GPIO_PORTA_DATA_R |=   0x20; //  RS --> 1
	GPIO_PORTA_DATA_R &=  ~0xC0; //  E, R/W --> 0
	GPIO_PORTB_DATA_R  =   data;
	GPIO_PORTA_DATA_R |=   0x80; //	E --> 1
	Delay_micro(0);
	GPIO_PORTA_DATA_R &=  ~0xA0; // E --> 0
	Delay_micro(40);
	
}

void LCD_Command(unsigned char cmd ){
	
	GPIO_PORTA_DATA_R &= ~0xE0; //  E , R/W,  RS --> 0
	GPIO_PORTB_DATA_R  =  cmd;
	GPIO_PORTA_DATA_R |=0x80; //	E --> 1
	Delay_micro(0);
	GPIO_PORTA_DATA_R &= ~0x80; // E --> 0
	
	if(cmd < 4) 
	{
		Delay_milli(2); // delay for 2 milli second
	}	
	else
	{	
		Delay_micro(40); // delay for 40 micro second
	}

}

void LCD_Init(){
	
	/* initialization sequence */
	Delay_milli(20); 
	LCD_Command(0x30);
	Delay_milli(5);
	LCD_Command(0x30);
	Delay_micro(100);
	LCD_Command(0x30); //Wake Up
	LCD_Command(0x38); //8-bits,2 display line
	LCD_Command(0x06); //increments automatically
	LCD_Command(0x01); //clear display
	LCD_Command(0x0F); //Turn on display


}

