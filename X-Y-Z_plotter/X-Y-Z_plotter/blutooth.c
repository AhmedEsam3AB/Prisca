/*
 * blutooth.c
 *
 * Created: 09/03/2019 6:56:00 PM
 * Author : PRISCA
 */ 
#include "Include.h"
#include <stdlib.h>
//***second_value_function***
//this function take one variable, and search in it about the location of ","
//then put the characters after "," in a new array of characters
//then convert string to integer value ,then return it
int third_value (char* String)
{
	int i = 0,j=0;
	char third_v[100];
	for (int i = 0 ; i < 100 ;i++)
	{
		third_v [i] = 0;
	}
	while(1)
	{
		if (String [i] == '-'){
			third_v [j] = String[j+i+1];
			if (String [j+i+2] == ';')
			break;
			j++;
		}
		else
		i++;
	}
	return (atoi(third_v));
}

int second_value (char* String)
{
    int i = 0,j=0;
	char second_v[100];
	for (int i = 0 ; i < 100 ;i++)
	{
		second_v [i] = 0;
	}
    while(1)
    {
        if (String [i] == ','){
				second_v [j] = String[j+i+1];
				if (String [j+i+2] == '-')
				break;
				j++;
		}
		else
		i++;
    }
    return (atoi(second_v));
}


//***subtraction_function***
//it takes two variables, one call by reference and other call by value
//call by reference is used to make a change in it, to save the new value
//this function return a value that the motor have to move
//this value could be negative or positive, it realize the direction of movements
int sub_function (int *current_pos, int new_pos)
{
    int x = new_pos - *current_pos;
    *current_pos = new_pos;
    return x;
}