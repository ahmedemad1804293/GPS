#ifndef LCD_H
#define LCD_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "C:/keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <TM4C123.h>

void LCD_Data(unsigned char data  );
void LCD_Command(unsigned char cmd) ;
void LCD_Init(void);

#endif
