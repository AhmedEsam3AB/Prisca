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
#include <util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
int speed;
void STpinChange(int a, int b)
{
	if(b == 0)
	{
		if(a == St_PORTA0)
		PORTA &= ~(1<<PORTA0);
		else if(a == St_PORTA1)
		PORTA &= ~(1<<PORTA1);
		else if(a == St_PORTA2)
		PORTA &= ~(1<<PORTA2);
		else if(a == St_PORTA3)
		PORTA &= ~(1<<PORTA3);
		else if(a == St_PORTA4)
		PORTA &= ~(1<<PORTA4);
		else if(a == St_PORTA5)
		PORTA &= ~(1<<PORTA5);
		else if(a == St_PORTA6)
		PORTA &= ~(1<<PORTA6);
		else if(a == St_PORTA7)
		PORTA &= ~(1<<PORTA7);
		else if(a == St_PORTB0)
		PORTB &= ~(1<<PORTB0);
		else if(a == St_PORTB1)
		PORTB &= ~(1<<PORTB1);
		else if(a == St_PORTB2)
		PORTB &= ~(1<<PORTB2);
		else if(a == St_PORTB3)
		PORTB &= ~(1<<PORTB3);
		else if(a == St_PORTB4)
		PORTB &= ~(1<<PORTB4);
		else if(a == St_PORTB5)
		PORTB &= ~(1<<PORTB5);
		else if(a == St_PORTB6)
		PORTB &= ~(1<<PORTB6);
		else if(a == St_PORTB7)
		PORTB &= ~(1<<PORTB7);
		else if(a == St_PORTC0)
		PORTC &= ~(1<<PORTC0);
		else if(a == St_PORTC1)
		PORTC &= ~(1<<PORTC1);
		else if(a == St_PORTC2)
		PORTC &= ~(1<<PORTC2);
		else if(a == St_PORTC3)
		PORTC &= ~(1<<PORTC3);
		else if(a == St_PORTC4)
		PORTC &= ~(1<<PORTC4);
		else if(a == St_PORTC5)
		PORTC &= ~(1<<PORTC5);
		else if(a == St_PORTC6)
		PORTC &= ~(1<<PORTC6);
		else if(a == St_PORTC7)
		PORTC &= ~(1<<PORTC7);
		else if(a == St_PORTD0)
		PORTD &= ~(1<<PORTD0);
		else if(a == St_PORTD1)
		PORTD &= ~(1<<PORTD1);
		else if(a == St_PORTD2)
		PORTD &= ~(1<<PORTD2);
		else if(a == St_PORTD3)
		PORTD &= ~(1<<PORTD3);
		else if(a == St_PORTD4)
		PORTD &= ~(1<<PORTD4);
		else if(a == St_PORTD5)
		PORTD &= ~(1<<PORTD5);
		else if(a == St_PORTD6)
		PORTD &= ~(1<<PORTD6);
		else if(a == St_PORTD7)
		PORTD &= ~(1<<PORTD7);
	}
	else
	{
		if(a == St_PORTA0)
		PORTA |= (1<<PORTA0);
		else if(a == St_PORTA1)
		PORTA |= (1<<PORTA1);
		else if(a == St_PORTA2)
		PORTA |= (1<<PORTA2);
		else if(a == St_PORTA3)
		PORTA |= (1<<PORTA3);
		else if(a == St_PORTA4)
		PORTA |= (1<<PORTA4);
		else if(a == St_PORTA5)
		PORTA |= (1<<PORTA5);
		else if(a == St_PORTA6)
		PORTA |= (1<<PORTA6);
		else if(a == St_PORTA7)
		PORTA |= (1<<PORTA7);
		else if(a == St_PORTB0)
		PORTB |= (1<<PORTB0);
		else if(a == St_PORTB1)
		PORTB |= (1<<PORTB1);
		else if(a == St_PORTB2)
		PORTB |= (1<<PORTB2);
		else if(a == St_PORTB3)
		PORTB |= (1<<PORTB3);
		else if(a == St_PORTB4)
		PORTB |= (1<<PORTB4);
		else if(a == St_PORTB5)
		PORTB |= (1<<PORTB5);
		else if(a == St_PORTB6)
		PORTB |= (1<<PORTB6);
		else if(a == St_PORTB7)
		PORTB |= (1<<PORTB7);
		else if(a == St_PORTC0)
		PORTC |= (1<<PORTC0);
		else if(a == St_PORTC1)
		PORTC |= (1<<PORTC1);
		else if(a == St_PORTC2)
		PORTC |= (1<<PORTC2);
		else if(a == St_PORTC3)
		PORTC |= (1<<PORTC3);
		else if(a == St_PORTC4)
		PORTC |= (1<<PORTC4);
		else if(a == St_PORTC5)
		PORTC |= (1<<PORTC5);
		else if(a == St_PORTC6)
		PORTC |= (1<<PORTC6);
		else if(a == St_PORTC7)
		PORTC |= (1<<PORTC7);
		else if(a == St_PORTD0)
		PORTD |= (1<<PORTD0);
		else if(a == St_PORTD1)
		PORTD |= (1<<PORTD1);
		else if(a == St_PORTD2)
		PORTD |= (1<<PORTD2);
		else if(a == St_PORTD3)
		PORTD |= (1<<PORTD3);
		else if(a == St_PORTD4)
		PORTD |= (1<<PORTD4);
		else if(a == St_PORTD5)
		PORTD |= (1<<PORTD5);
		else if(a == St_PORTD6)
		PORTD |= (1<<PORTD6);
		else if(a == St_PORTD7)
		PORTD |= (1<<PORTD7);
	}
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
		_delay_us (500);
		sp-=1;
	}
}
void Stepper_A_onerev(bool clockw)
{
	STpinChange(StepA,1);
	setspeed(speed);
	STpinChange(StepA,0);
	_delay_us (50);
}
void Stepper_B_onerev(bool clockw)
{
	STpinChange(StepB,1);
	setspeed(speed);
	STpinChange(StepB,0);
	_delay_us (50);
}
void Stepper_C_onerev(bool clockw)
{
	STpinChange(StepC,1);
	setspeed(speed);
	STpinChange(StepC,0);
	_delay_us (50);
}
void Stepper_D_onerev(bool clockw)
{
	STpinChange(StepD,1);
	setspeed(speed);
	STpinChange(StepD,0);
	_delay_us (50);
}
void Stepper_A_rev(bool clockw,long NuOfSteps){//rotate clockwise or ccw , number of steps for stepperA
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
		Stepper_A_onerev(clockw);
		NuOfSteps -= 1;
	}
}
void Stepper_B_rev(bool clockw,long NuOfSteps){//rotate clockwise or ccw , number of steps for stepperB
	if (clockw)
	{
		STpinChange(DIRB,1);
	}
	else
	{
		STpinChange(DIRB,0);
	}
	
	while (NuOfSteps > 0)
	{
		Stepper_B_onerev(clockw);
		NuOfSteps -= 1;
	}
}
void Stepper_C_rev(bool clockw,long NuOfSteps){//rotate clockwise or ccw , number of steps for stepperC
	if (clockw)
	{
		STpinChange(DIRC,1);
	}
	else
	{
		STpinChange(DIRC,0);
	}
	
	while (NuOfSteps > 0)
	{
		Stepper_C_onerev(clockw);
		NuOfSteps -= 1;
	}
}
void Stepper_D_rev(bool clockw,long NuOfSteps){//rotate clockwise or ccw , number of steps for stepperC
	if (clockw)
	{
		STpinChange(DIRD,1);
	}
	else
	{
		STpinChange(DIRD,0);
	}
	
	while (NuOfSteps > 0)
	{
		Stepper_D_onerev(clockw);
		NuOfSteps -= 1;
	}
}