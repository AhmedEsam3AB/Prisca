/*
 * X-Y_plotter.c
 *
 * Created: 09/03/2019 08:14:08 PM
 * Author : PRISCA
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <string.h>
#include <stdbool.h> // library for boolean variable
#include "Include.h"
bool statusx = 0; // to control the direction of x rotation
bool statusy = 0; // to control the direction of y rotation
bool statusz = 0; // to control the direction of z rotation
void Init(void);// initial library to set up the external devices
/*static variables that initialize only once */
static int old_val_1 = 0;
static int old_val_2 = 0;
static int old_val_3 = 0;
//three variables that contain numbers that convert from string/
int value_1;
int value_2;
int value_3;

//two values that send to movement function/
int x;
int y;
int z;
char String [150]  ;

int main(void)
{
	Init();
	while (1)
	{
		for (int i = 0 ; i < 100 ;i++)
		{
			String [i] = 0;
		}
		UART_RxString(String);
		//Recive_Data(String);
		value_1 = atoi(String);           //extract first value
		value_2 = second_value (String); //call function to extract second value
		value_3 = third_value (String); //call function to extract third value

				if (!(value_1>250||value_2>250||value_3>250||value_1<0||value_2<0||value_3<0)) // if the values don't skip the plate ,use it
		{
			x = sub_function (&old_val_1, value_1);     //call function to extract first step
			y = sub_function (&old_val_2, value_2);    //call function to extract second step
			z = sub_function (&old_val_3, value_3);    //call function to extract second step
  			value_1 = 0;
  			value_2 = 0;
			value_3 = 0;
			 
		}		
		if (x < 0 ){ // if the distance give a negative number make it positive and change the direction of motor rotation
			x *=-1;
			statusx = 1;
		}
		else
		statusx = 0;
		if (y < 0 ){
			y *=-1;
			statusy = 1;
		}
		else
		statusy = 0;
		if (z < 0 ){
			z *=-1;
			statusz = 1;
		}
		else
		statusz = 0;
		
		
		Stepper_A_rev(statusx,(x*100));
		Stepper_B_rev(statusy,(y*100));
		Stepper_C_rev(statusy,(z*100));
		x=0;
		y=0;
		z=0;
	}
}
void Init(void)
{
	StepperInit(16,1000);
	DDRC |=0XFF;
	DDRA |= (1<<PA7);
	UART_Init(9600);
	//UART_INIT();
}





