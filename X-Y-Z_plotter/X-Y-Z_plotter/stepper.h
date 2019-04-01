/*
 * stepper.h
 *
 * Created: 25/10/2018 10:14:48 م
 *  Author: eng_s
 * This library controls the bipolar Stepper Motor with the A9488 controller 
 */
#include<util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
#ifndef stepper_H_
#define stepper_H_
#define St_PORTA0 0
#define St_PORTA1 1
#define St_PORTA2 2
#define St_PORTA3 3
#define St_PORTA4 4
#define St_PORTA5 5
#define St_PORTA6 6
#define St_PORTA7 7
#define St_PORTB0 10
#define St_PORTB1 11
#define St_PORTB2 12
#define St_PORTB3 13
#define St_PORTB4 14
#define St_PORTB5 15
#define St_PORTB6 16
#define St_PORTB7 17
#define St_PORTC0 20
#define St_PORTC1 21
#define St_PORTC2 22
#define St_PORTC3 23
#define St_PORTC4 24
#define St_PORTC5 25
#define St_PORTC6 26
#define St_PORTC7 27
#define St_PORTD0 30
#define St_PORTD1 31
#define St_PORTD2 32
#define St_PORTD3 33
#define St_PORTD4 34
#define St_PORTD5 35
#define St_PORTD6 36
#define St_PORTD7 37
#define cw 1
#define ccw 0
#define ms1 St_PORTC0    //ms1 pin from the driver connect to portA0
#define ms2 St_PORTC1    //ms2 pin from the driver connect to portA1
#define ms3 St_PORTC2    //ms3 pin from the driver connect to portA2
#define StepA St_PORTC4  //step pin for first stepper from the driver connect to portA3
#define DIRA St_PORTC3   //direction pin for first stepper from the driver connect to portA4
#define StepB St_PORTC5  //step pin for 2nd stepper from the driver connect to portA5
#define DIRB St_PORTC6   //direction pin for 2nd stepper from the driver connect to portA6
#define StepC St_PORTC7  //step pin for 3rd stepper from the driver connect to portA7
#define DIRC St_PORTA0   //direction pin for 3rd stepper from the driver connect to portB0
#define StepD St_PORTB1  //step pin for 4th stepper from the driver connect to portB1
#define DIRD St_PORTB2   //direction pin for 4th stepper from the driver connect to portB2
void STpinChange(int a, int b);
void StepperInit(int steps,int16_t sp) ;
void Stepper_A_onerev(bool clockw);
void Stepper_B_onerev(bool clockw);
void Stepper_C_onerev(bool clockw);
void Stepper_D_onerev(bool clockw);
void Stepper_A_rev(bool clockw,long NuOfSteps);
void Stepper_B_rev(bool clockw,long NuOfSteps);
void Stepper_C_rev(bool clockw,long NuOfSteps);
void Stepper_D_rev(bool clockw,long NuOfSteps);
void setspeed(int sp);
void steper_1step();
void steper_Hstep();
void steper_Qstep();
void steper_Estep();
void steper_Sstep();
#endif
