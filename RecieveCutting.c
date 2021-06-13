#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include  "RecieveCutting.h"

extern char* GPSLine ;
extern char* lat_str;
extern char* lon_str;
extern float lat2;
extern float lon2;

char UART_Read(void)
{
	while((UART7_FR_R & 0x0010) != 0); // WHILE RECEIVER FIFO EMPTY WAITS
	return ((uint8_t)UART7_DR_R & 0xFF) ; // ANDED WITH 0xFF TO DISCARD IF ANY OTHER VALUES IN THE REGISTER
}

void Receive_Str() // function to get the array from the GPS
{
	while (1)
	{	
	int i ;
	if(UART_Read()== 'R')
	{
	
	for (i = 0; i < 70; i ++)
	{
		GPSLine[i] = 	UART_Read() ;
	}
		break;
	}
	}
}


	

	
	
void Cutting()
{		
		int i;
		int j;
		int k ;
		int x ;
		int y  ;
		int a  ;
		int b	 ;



int CommaIndex [75];
int commacounter = 0;
		
			for ( i = 0 ; i < 75 ; i++)
				{
					if(GPSLine[i]==',')
						{
							CommaIndex[commacounter] = i;
							commacounter++;
							
						}	
				}
				

				 x = CommaIndex[3];
				 y = CommaIndex[2] ;
				 a = CommaIndex[5] ;
				 b = CommaIndex[4] ;
				
			


				for(k = 0 ; k <  15 ; k++  )							
						{
							
							if( k < x-y-1){
							lat_str[k] = GPSLine[y+k+1]; 
							}
							else { lat_str[k]= ' ';}
						}


				
				for(j = 0 ; j <  15 ; j++  )
				
						{
							
							if(j < a-b-1)
							{lon_str[j] = GPSLine[b+j+1];}
							else {lon_str [j] = ' '; }
						}
				
			
				lat2 = atof(lat_str);
						
				
			
				lon2 = atof(lon_str);		
				

}

