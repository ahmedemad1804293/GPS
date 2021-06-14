#ifndef RECIEVECUTTING_H
#define RECIEVECUTTING_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>
#include "Micro_Controller_Init.h"



unsigned char UART_Read(void);
void Receive_Str(void) ;
void Cutting(void);
void latlonStrtoInt (void);


#endif
