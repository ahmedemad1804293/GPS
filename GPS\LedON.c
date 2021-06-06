#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "LedON.h"


void led_on_100(){
	
		GPIO_PORTF_DATA_R |=0x2;		// turning led RED F1  after 100 meter
	
} 



void led_on_dest(){
		

		
		GPIO_PORTF_DATA_R |=0x4; 	// turning led BLUE F2 on destination
		

} 
