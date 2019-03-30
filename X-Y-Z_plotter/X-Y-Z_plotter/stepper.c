/*
 * stepper.h
 *
 * Created: 25/10/2018 10:14:48 ã
 *  Author: eng_s
 * This library controls the bipolar Stepper Motor with the A9488 driver
 * with 4 stepper A,B,C,D
 * the step pin is control the speed of rotation by the rate of change
 * in it with msx pins.
 * and the DIR pin is control the direction of rotation cw or ccw
 */
#include "stepper.h"
#include<util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
int speed;
void STpinChange(int a, int b)
{
	if(b == 0)
	{
		if(a == St_PORTA0)
		PORTA &= ~(1<<PA0);
		else if(a == St_PORTA1)
		PORTA &= ~(1<<PA1);
		else if(a == St_PORTA2)
		PORTA &= ~(1<<PA2);
		else if(a == St_PORTA3)
		PORTA &= ~(1<<PA3);
		else if(a == St_PORTA4)
		PORTA &= ~(1<<PA4);
		else if(a == St_PORTA5)
		PORTA &= ~(1<<PA5);
		else if(a == St_PORTA6)
		PORTA &= ~(1<<PA6);
		else if(a == St_PORTA7)
		PORTA &= ~(1<<PA7);
		else if(a == St_PORTB0)
		PORTB &= ~(1<<PB0);
		else if(a == St_PORTB1)
		PORTB &= ~(1<<PB1);
		else if(a == St_PORTB2)
		PORTB &= ~(1<<PB2);
		else if(a == St_PORTB3)
		PORTB &= ~(1<<PB3);
		else if(a == St_PORTB4)
		PORTB &= ~(1<<PB4);
		else if(a == St_PORTB5)
		PORTB &= ~(1<<PB5);
		else if(a == St_PORTB6)
		PORTB &= ~(1<<PB6);
		else if(a == St_PORTB7)
		PORTB &= ~(1<<PB7);
		else if(a == St_PORTC0)
		PORTC &= ~(1<<PC0);
		else if(a == St_PORTC1)
		PORTC &= ~(1<<PC1);
		else if(a == St_PORTC2)
		PORTC &= ~(1<<PC2);
		else if(a == St_PORTC3)
		PORTC &= ~(1<<PC3);
		else if(a == St_PORTC4)
		PORTC &= ~(1<<PC4);
		else if(a == St_PORTC5)
		PORTC &= ~(1<<PC5);
		else if(a == St_PORTC6)
		PORTC &= ~(1<<PC6);
		else if(a == St_PORTC7)
		PORTC &= ~(1<<PC7);
		else if(a == St_PORTD0)
		PORTD &= ~(1<<PD0);
		else if(a == St_PORTD1)
		PORTD &= ~(1<<PD1);
		else if(a == St_PORTD2)
		PORTD &= ~(1<<PD2);
		else if(a == St_PORTD3)
		PORTD &= ~(1<<PD3);
		else if(a == St_PORTD4)
		PORTD &= ~(1<<PD4);
		else if(a == St_PORTD5)
		PORTD &= ~(1<<PD5);
		else if(a == St_PORTD6)
		PORTD &= ~(1<<PD6);
		else if(a == St_PORTD7)
		PORTD &= ~(1<<PD7);
	}
	else
	{
		if(a == St_PORTA0)
		PORTA |= (1<<PA0);
		else if(a == St_PORTA1)
		PORTA |= (1<<PA1);
		else if(a == St_PORTA2)
		PORTA |= (1<<PA2);
		else if(a == St_PORTA3)
		PORTA |= (1<<PA3);
		else if(a == St_PORTA4)
		PORTA |= (1<<PA4);
		else if(a == St_PORTA5)
		PORTA |= (1<<PA5);
		else if(a == St_PORTA6)
		PORTA |= (1<<PA6);
		else if(a == St_PORTA7)
		PORTA |= (1<<PA7);
		else if(a == St_PORTB0)
		PORTB |= (1<<PB0);
		else if(a == St_PORTB1)
		PORTB |= (1<<PB1);
		else if(a == St_PORTB2)
		PORTB |= (1<<PB2);
		else if(a == St_PORTB3)
		PORTB |= (1<<PB3);
		else if(a == St_PORTB4)
		PORTB |= (1<<PB4);
		else if(a == St_PORTB5)
		PORTB |= (1<<PB5);
		else if(a == St_PORTB6)
		PORTB |= (1<<PB6);
		else if(a == St_PORTB7)
		PORTB |= (1<<PB7);
		else if(a == St_PORTC0)
		PORTC |= (1<<PC0);
		else if(a == St_PORTC1)
		PORTC |= (1<<PC1);
		else if(a == St_PORTC2)
		PORTC |= (1<<PC2);
		else if(a == St_PORTC3)
		PORTC |= (1<<PC3);
		else if(a == St_PORTC4)
		PORTC |= (1<<PC4);
		else if(a == St_PORTC5)
		PORTC |= (1<<PC5);
		else if(a == St_PORTC6)
		PORTC |= (1<<PC6);
		else if(a == St_PORTC7)
		PORTC |= (1<<PC7);
		else if(a == St_PORTD0)
		PORTD |= (1<<PD0);
		else if(a == St_PORTD1)
		PORTD |= (1<<PD1);
		else if(a == St_PORTD2)
		PORTD |= (1<<PD2);
		else if(a == St_PORTD3)
		PORTD |= (1<<PD3);
		else if(a == St_PORTD4)
		PORTD |= (1<<PD4);
		else if(a == St_PORTD5)
		PORTD |= (1<<PD5);
		else if(a == St_PORTD6)
		PORTD |= (1<<PD6);
		else if(a == St_PORTD7)
		PORTD |= (1<<PD7);
	}
}
void Steper_pins(char a)
{
	if(a & 1)
	STpinChange(ms1,1);
	else
	STpinChange(ms1,0);
	
	if(a & 2)
	STpinChange(ms2,1);
	else
	STpinChange(ms2,0);
	
	if(a & 4)
	STpinChange(ms3,1);
	else
	STpinChange(ms3,0);
	
	if(a & 8)
	STpinChange(StepA,1);
	else
	STpinChange(StepA,0);
	if(a & 16)
	STpinChange(DIRA,1);
	else
	STpinChange(DIRA,0);
	if(a & 32)
	STpinChange(StepB,1);
	else
	STpinChange(StepB,0);
	if(a & 64)
	STpinChange(DIRB,1);
	else
	STpinChange(DIRB,0);
	if(a & 128)
	STpinChange(StepC,1);
	else
	STpinChange(StepC,0);
	if(a & 256)
	STpinChange(DIRC,1);
	else
	STpinChange(DIRC,0);
	if(a & 512)
	STpinChange(StepD,1);
	else
	STpinChange(StepD,0);
	if(a & 1024)
	STpinChange(DIRD,1);
	else
	STpinChange(DIRD,0);
	
}

void steper_1step(){ // to make a full 1 step with 2 phase
	STpinChange(ms1,0);        // ms1 = 0,ms2 = 0,ms3 = 0 from a9488 data sheet
	STpinChange(ms2,0);
	STpinChange(ms3,0);
}
void steper_Hstep(){// to make a half 1 step with 1-2 phase ms1 = 1,ms2 = 0,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,0);
	STpinChange(ms3,0);
}
void steper_Qstep(){// to make a Quarter 1 step with w1-2 phase ms1 = 0,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,0);
	STpinChange(ms2,1);
	STpinChange(ms3,0);
}
void steper_Estep(){// to make a Eighth 1 step with 2w1-2 phase ms1 = 1,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,1);
	STpinChange(ms3,0);
}
void steper_Sstep(){// to make a Sixteenth 1 step with 4w1-2 phase ms1 = 1,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,1);
	STpinChange(ms3,1);
}
//library interface description
void StepperInit(int steps,int16_t sp)  //types of steps (1,2,6,8,16),speed of rotation in rpm
{
	switch (steps){
		case 1:steper_1step();break;
		case 2:steper_Hstep();break;
		case 6:steper_Qstep();break;
		case 8:steper_Estep();break;
		case 16:steper_Sstep();break;
	}
	speed = sp;
}
void setspeed(int sp){
	sp=(1000/sp);//1step = 1 mm 
	while(sp > 0){
		_delay_ms(1);
		sp-=1;
	}
}
void Stepper_A_rev(bool clockw,uint8_t NuOfSteps){//rotate clockwise or ccw , number of steps for stepperA
	if (clockw)
	{
		STpinChange(DIRA,1);
	}
	else
	{
		STpinChange(DIRA,0);
	}
	
	while (NuOfSteps > 0)
	{
		STpinChange(StepA,1);
		_delay_ms(1); 
		STpinChange(StepA,0);
		setspeed(speed);
		NuOfSteps -= 1;
	}
}
void Stepper_B_rev(bool clockw,uint8_t NuOfSteps){//rotate clockwise or ccw , number of steps for stepperB
	if (clockw)
	{
		STpinChange(DIRB,1);
	}
	else
	{
		STpinChange(DIRB,0);
	}
	
	while (NuOfSteps != 0)
	{
		STpinChange(StepB,1);
		_delay_ms(1); //1Hz = 60 rpm & t = 1/f &1s = 1000ms
		STpinChange(StepB,0);
		setspeed(speed);
		NuOfSteps -= 1;
	}
}
void Stepper_C_rev(bool clockw,uint8_t NuOfSteps){//rotate clockwise or ccw , number of steps for stepperC
	if (clockw)
	{
		STpinChange(DIRC,1);
	}
	else
	{
		STpinChange(DIRC,0);
	}
	
	while (NuOfSteps != 0)
	{
		STpinChange(StepC,1);
		_delay_ms(1); //1Hz = 60 rpm & t = 1/f &1s = 1000ms
		STpinChange(StepC,0);
		setspeed(speed);
		NuOfSteps -= 1;
	}
}
void Stepper_D_rev(bool clockw,uint8_t NuOfSteps){//rotate clockwise or ccw , number of steps for stepperC
	if (clockw)
	{
		STpinChange(DIRD,1);
	}
	else
	{
		STpinChange(DIRD,0);
	}
	
	while (NuOfSteps != 0)
	{
		STpinChange(StepD,1);
		_delay_ms(1); //1Hz = 60 rpm & t = 1/f &1s = 1000ms
		STpinChange(StepD,0);
		setspeed(speed);
		NuOfSteps -= 1;
	}
}