#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Delay.h"



void Delay_milli(int n){

int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++){}

}
void Delay_micro(int n){
	
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3;j++){}
	
}
