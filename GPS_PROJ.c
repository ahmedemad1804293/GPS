#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "Micro_Controller_Init.h"
#include "Delay.h"
#include "Lcd.h"
#include "Distance.h"
#include "LedON.h"

void SystemInit(){}

int distance = 0 ;
float lat_start , lon_start  , lat_dest , lon_dest ;
void distanceInMetersBetweenEarthCoordinates(float lat1,float lon1,float lat2 , float lon2 ) ;
float lat1,lon1,lat2,lon2;
const float PI = 3.14159265358979323846264338327950288;
const int earthRadiusKm = 6371;
int Z , m; char distance_Str [5] ;

int main(){
	
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2) );
	
	Micro_Controller_Init();
	LCD_Init();
	
	// take start point (fixed point) from GPS store them in lat_start,lon_start (not done yet)
	
	
	lat_start = 30.06484890173206;                  // dummy start lat to test 
	lon_start = 31.274821238090986;									// dummy start lon to test
	
	lat1 = lat_start ;															
	lon1 = lon_start ;
	
	lat2 = lat_start; 				
	lon2 = lon_start;
	
	
	 
	while(1){
		
	
	if ( lat1!=lat2 && lon1!=lon2 ){
	LCD_Command(1);						/* clear display */
	LCD_Command(0x80); 			/* lcd cursor location */
	Delay_milli(500);
		
	sprintf(distance_Str,"%d",distance);
	
		
		if(distance<10)
		{
			m = 1 ;
		}
		else if(distance<100)
		{
			
			m = 2 ;
		}
		else if(distance<1000)
		{
		
			m = 3 ;
		}
		else if(distance<10000)
		{
			m = 4 ;
		}
		else if(distance<100000)
		{
			m = 5 ;
		}
	
	for( Z = 0 ; Z < m ; Z++)
	{
		LCD_Data(distance_Str[Z]);
		Delay_milli(1);
	}	  
	
	Delay_milli(500);
		
	}	
	 
	distanceInMetersBetweenEarthCoordinates( lat1, lon1, lat2 ,  lon2);
	
		
	if  (distance>=100)   {	led_on_100 () ;  } // will turn on after 100 m
	if ((GPIO_PORTF_DATA_R &0x1) == 0) { 
		  
			lat_dest = lat2	 ;		 					/* store lat of destiantion point */ 
		  lon_dest = lon2  ;		         /* store lon of destination point */ 	
	    LCD_Command(1)   ;						/* clear display */
	    LCD_Command(0x80); 					 /* lcd cursor location */
			Delay_milli(100) ;
			LCD_Data ('D')   ;
			Delay_milli(1)   ;
			LCD_Data('I')    ;
			Delay_milli(1)   ;
			LCD_Data('S')    ;
	  	Delay_milli(1)   ;
		  LCD_Data('T')    ;
	  	Delay_milli(1)   ;
			LCD_Data('A')    ;
			Delay_milli(1)   ;
		  LCD_Data('N')    ;
	  	Delay_milli(1)   ;
			LCD_Data('C')    ;
	  	Delay_milli(1)   ;
			LCD_Data('E')    ;
	  	Delay_milli(1)   ;
		  LCD_Data('=')    ;
	  	Delay_milli(1)   ;
		  LCD_Data(' ')    ;
	  	Delay_milli(1)   ;
			
		for( Z = 0 ; Z < m ; Z++)
	{
		LCD_Data(distance_Str[Z]);
		Delay_milli(1);
	}	  

		LCD_Data('m')  		 ;
		Delay_milli(500);
		led_on_dest() ;
			
		break; 
}
		
}	
}
