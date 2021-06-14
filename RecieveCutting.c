#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include  "RecieveCutting.h"

extern char* GPSLine ;
extern char* lat_str;
extern char* lon_str;	
extern int latDotIndex;
extern int lonDotIndex;
extern float lat2;
extern float lon2;
extern char* GPSLines;



unsigned char UART_Read(void)
{
	while((UART7_FR_R & 0x0010) != 0); // Check FIFO
	return ((uint8_t)UART7_DR_R & 0xFF) ; // return first 8 bits of data register
}

void Receive_Str(void) // function to get the array from the GPS
{
char*	fixflagstr;
int FixFlag = 0;
int i ;
unsigned char inputChar;
while ( FixFlag == 0)
{
	
	// getting $GPGGA line 
	
inputChar = UART_Read();
				if(inputChar =='$')
					{
					inputChar = UART_Read();
						if(inputChar=='G')
							{
								inputChar = UART_Read();
									if(inputChar=='P')
										{
											inputChar = UART_Read();
											if(inputChar=='G')
												{
													inputChar = UART_Read();
													if(inputChar=='G')
														{
															inputChar = UART_Read();
																	if(inputChar=='A')
																		{
																			inputChar = UART_Read();
																				if(inputChar==',')
																				{
																					for(i = 0; i<70 ;i++)
																					{ 
																						GPSLine[i]= UART_Read();
																					}
																				
																				}
																			
	
																		}
																		
														}
														
														
											 }
												
											
									}
										
								
						 }
							
							
					}
			

   //		getting lat string , lon string & fix flag from GPS Line				
	 
	lat_str = strtok (GPSLine,",");		//fake lat string
	lat_str = strtok (NULL,",");		  // Real lat string			
	lon_str = strtok (NULL,",");		 //fake lon string
	lon_str = strtok (NULL,",");     // Real lat string	
	fixflagstr = strtok (GPSLine,"E");		//fake fix string
	fixflagstr = strtok (NULL,",");		//Real fix string			

if (fixflagstr[0] == '1' || fixflagstr[1] == '1' || fixflagstr[2] == '1' )
	{
		FixFlag = 1 ;
	}						

}	
}	
	

/*
void Cutting(void)
{		
int ii;
int jj;
int kk;
int firstcomma;
int thirdcoma;
char str [9]  ;
char strr [10] ;
int commacounter = 0;


for (  ii = 0 ; ii < 70 ; ii++)
				{
					if( GPSLine[ii]== ',' )
						{
							commacounter++;
						}
					if (commacounter == 0)
						{
							firstcomma = ii+1;
						}
					if (commacounter == 3 )
                        {
							thirdcoma = ii;
							break;
						}
				}
				for (  jj = 0 ; jj < 9 ; jj++)
				{
							str [jj] = GPSLine [firstcomma+jj+1];

				}
			for (  kk = 0 ; kk < 10 ; kk++)
				{
							strr [kk] = GPSLine [thirdcoma+kk+1];

				}
lat_str = str;
lon_str = strr;
}
*/


void latlonStrtoInt (void){
int i ;	
char* LatDivide ;
char* LatNum;
char* LonDivide ;
char* LonNum;
	

				i = 0;
				for ( i = 0 ; i < 9 ; i++)
				{
					if(lat_str[i]=='.')
						{
							latDotIndex = i;
	
						}	
				}
				
				
				i = 0 ;
				for ( i = 0 ; i < 10 ; i++)
				{
					if(lon_str[i]=='.')
						{
							lonDotIndex = i;
	
						}	
				}
				
					
					
					
					LatDivide[0] = lat_str [latDotIndex-2];
					LatDivide[1] = lat_str [latDotIndex-1];
					i = latDotIndex;
					for( i = latDotIndex ; i <  9 ; i++)
					{
						LatDivide [i] = lat_str [i];
					}
					

				
					i = 0 ;
					for( i = 0 ; i <  latDotIndex ; i++)
					{
						LatNum [i] = lat_str [i];
					}
					
					
					LonDivide[0] = lon_str [lonDotIndex-2];
					LonDivide[1] = lon_str [lonDotIndex-1];
					i = lonDotIndex;
					for(  i = lonDotIndex ; i <  10 ; i++)
					{
						LonDivide [i] = lon_str [i];
					}
		
				
					i = 0 ;
					for( i = 0 ; i <  lonDotIndex ; i++)
					{
						LonNum [i] = lon_str [i];
					}
										
						
				lat2 = atof(LatNum) + (atof(LatDivide)/60 );
				lon2 = atof(LonNum) + (atof(LonDivide)/60 );
					
				/*lat2 = 48.1173;
					" 48"
					"07.038, N"
					"011"
					"31.000, E"
				lon2 = 11.5166;*/

}
