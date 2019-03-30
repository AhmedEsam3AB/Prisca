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
#include <stdbool.h> // library for boolean variable
#include "Include.h"
#include "lcd.h"
double posx = 0.0; // the current position of x
double posy = 0.0; // the current position of y
double posz = 0.0; // the current position of z
bool statusx; // to control the direction of x rotation
bool statusy; // to control the direction of y rotation
bool statusz; // to control the direction of z rotation
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
int step_1;
int step_2;
int step_3;
char string [12] ;
char s1[30];
char s2[30];
char s3[30];
int main(void)
{
	Init();
	while (1)
	{

		Lcd4_Clear();
		//UART_Rxstring(string);
		Recive_Data();
		value_1 = atoi(string);           //extract first value
		value_2 = second_value (string); //call function to extract second value
		value_3 = third_value (string); //call function to extract third value
		
		itoa(value_1,s1,10);
		itoa(value_2,s2,10);
		itoa(value_3,s3,10);
		Lcd4_Set_Cursor(1,1);
		Lcd4_Write_String(s1);
		Lcd4_Set_Cursor(2,1);
		Lcd4_Write_String(s2);	
		Lcd4_Set_Cursor(2,9);
		Lcd4_Write_String(s3);	
		_delay_ms(500);
		if (!(value_1>250||value_2>250||value_3>250||value_1<0||value_2<0||value_3<0)) // if the values don't skip the plate ,use it
		{
			
			step_1 = sub_function (&old_val_1, value_1);     //call function to extract first step
			
			step_2 = sub_function (&old_val_2, value_2);    //call function to extract second step
			
			step_3 = sub_function (&old_val_3, value_3);    //call function to extract third step
		}
		double x = step_1; // variable to store the received x axis
		double y = step_2; // variable to store the received y axis
		double z = step_3; // variable to store the received z axis
		double X ; // variable to control the movement of x axis
		double Y ; // variable to control the movement of x axis
		double Z ; // variable to control the movement of x axis
		
		/*-----------------------------------------------*/
		
		if (posx == 0)
		{
			X = x;
		}
		else
		{
			X = x - posx;
		}
		
		/*-----------------------------------------------*/
		
		if (posy == 0)
		{
			Y = y;
		}
		else
		{
			Y = y - posy;
		}
		
		/*-----------------------------------------------*/
		
			if (posz == 0)
			{
				Z = z;
			}
			else
			{
				Z = z - posz;
			}
		
		/*-----------------------------------------------*/
		
		if (X < 0 ){ // if the distance give a negative number make it positive and change the direction of motor rotation
			X *=-1;
			statusx = 1;
		}
		if (Y < 0 ){
			Y *=-1;
			statusy = 1;
		}
		if (Z < 0 ){
			Z *=-1;
			statusz = 1;
		}
		
		/*-----------------------------------------------*/

		while (X>=0) // go to the received position
		{
			Stepper_A_rev(statusx,1);
			X--;
		}
		while (Y>=0)
		{
			Stepper_B_rev(statusy,1);
			Y--;
		}
		while (Z>=0)
		{
			Stepper_C_rev(statusz,1);
			Z--;
		}
		posx = x;
		posy = y;
		posz = z;
		
		x = 0.0;
		y = 0.0;
		z = 0.0;


	}
}
void Init(void)
{
	StepperInit(1,1000);
	DDRC |=(1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);
	DDRB |=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);// use PB0,1,2,3,4,5 as output for LCD
	//UART_Init(9600);
	UART_INIT();
	Lcd4_Init();
}





