/*
 * blutooth.c
 *
 * Created: 09/03/2019 6:56:00 PM
 * Author : PRISCA
 */ 
#include "Include.h"
//***second_value_function***
//this function take one variable, and search in it about the location of ","
//then put the characters after "," in a new array of characters
//then convert string to integer value ,then return it
int second_value (char* String)
{
    int i,j;
    int length = strlen (String);
    char h [length];
    for (i=0;i< length;i++)
    {
        if (String [i] == ',')
          break;
    }
    for (j=0;j<length;j++)
        h [j] = String[j+i+1];
    return (atoi(h));
}
int third_value (char* String)
{
	int i,j;
	int length = strlen (String);
	char h [length];
	for (i=0;i< length;i++)
	{
		if (String [i] == '-')
		break;
	}
	for (j=0;j<length;j++)
	h [j] = String[j+i+1];
	return (atoi(h));
}
//***subtraction_function***
//it takes two variables, one call by reference and other call by value
//call by reference is used to make a change in it, to save the new value
//this function return a value that the motor have to move
//this value could be negative or positive, it realize the direction of movements
int sub_function (int* current_pos, int new_pos)
{
    int x = new_pos - *current_pos;
    *current_pos = new_pos;
    return x;
}
