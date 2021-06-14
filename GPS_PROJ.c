#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "Micro_Controller_Init.h"
#include "Delay.h"
#include "Lcd.h"
#include "Distance.h"
#include "LedON.h"
#include "RecieveCutting.h"

void SystemInit(){}

int distance = 0 ;
float lat_start , lon_start  , lat_dest , lon_dest ;
void distanceInMetersBetweenEarthCoordinates(float lat1,float lon1,float lat2 , float lon2 ) ;
float lat1,lon1,lat2,lon2;
const float PI = 3.14159265358979323846264338327950288;
const int earthRadiusKm = 6371;
int Z , m; char distance_Str [5] ; 
char* GPSLine ; //"$GPRMC, 123519, A, 4807.038, N, 01131.000, E,022.4, 084.4, 230394, 003.1, W*6A"
int  GPSCharCounter = 0;
char* GPSLines;
//int  GPRMCCharCounter = 0;
//int latStringCounter=0;	
int latDotIndex = 0;
int lonDotIndex = 0;
//int lonStringCounter=0;		
char* lat_str;
char* lon_str;
int ii;

//int commaindex [2] ;
int commacounter = 0;


int main(){
	
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2) );
	
	Micro_Controller_Init();
	LCD_Init();
	
	
	Receive_Str();	
  //Cutting();	
	latlonStrtoInt();
	
	// take start point (fixed point) from GPS store them in lat_start,lon_start (not done yet)

		

	
	lat_start = lat2;                  // dummy start lat to test 30.06484890173206
	lon_start = lon2;									// dummy start lon to test 31.274821238090986
	lat1 = lat2;
	lon1 = lon2;

	 
	while(1){
	
	

	Receive_Str();
  //Cutting();		
	latlonStrtoInt();

	
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

		
	for( Z = 0 ; Z < 1000 ; Z++)
	{
		LCD_Data(distance_Str[Z]);
		Delay_milli(1);
	}	 		
		Delay_milli(500);
	
			
	
}	

	distanceInMetersBetweenEarthCoordinates( lat1, lon1, lat2 , lon2);
	
		
	if  (distance>=100)   {	led_on_100 () ;  } // red will turn on after 100 m 
	if  (distance>=1000)  {	GPIO_PORTF_DATA_R |=0x8 ;  } // green will turn on after 1000 m
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
	
