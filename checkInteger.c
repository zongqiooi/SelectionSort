#include <stdio.h>
#include "checkInteger.h"

/* NAME      : checkInteger */
/* PURPOSE   : Check the data type for the sleep time command line argument or the data type for the number of random integers to be generated */
/* IMPORTS   : *value (string input for the sleep time command line argument or the string input for the number of random integers to be generated), */
/*             *check (determine whether to perform selection sort algorithm), type (the type of the string input to be checked) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to perform data type error checking for the sleep time command line argument or the number of random integers to be generated */
/*    POST   : The data type for the sleep time command line argument or the data type for the number of random integers to be generated will be checked */
/* REMARKS   : type == 1 (check for the input data type for the sleep time command line argument); type == 2 (check for the input data type for the number of random integers to be generated) */
/*             check == 0 (selection sort algorithm will not be carried out); check == 1 (selection sort algorithm will be carried out) */

void checkInteger(char *value, int *check, int type)
{
	int dot = 0;           /* number of dots in the input */
	char *input = value;   /* string input */
	
	if(type == 1) /* check for sleep time command line argument and only allow float data type */
	{
		while(*input != '\0') /* check if the sleep time command line argument contains character */
		{
			if((*input < '0' || *input > '9') && (*input != '.'))
			{
				*check = 0; 
			}
			
			input++;
		}
		
		input = value; /* reset pointer to point to the first character again */
		
		while(*input != '\0') /* check if the sleep time command line argument contains more than 1 dot symbol */
		{
			if(*input == '.')
			{
				dot += 1; 
			}
			
			input++;
		}
		
		input--; /* reset pointer to point to the last character again */ 
		
		if(*input == '.') /* check if the sleep time command line argument ends with a dot symbol */
		{
			*check = 0; 
		}
		
		input = value; /* reset pointer to point to the first character again */
		
		if(*input == '.') /* check if the sleep time command line argument starts with a dot symbol */
		{
			*check = 0; 
		}

		if(*check == 0 || dot != 1)
		{
			*check = 0;
			printf("Invalid data type for the sleep time. Please only enter a float value for the sleep time.\n");
		}
	}
	else if(type == 2) /* check for the input of the number of random integers to be generated and only allow integer data type */
	{
		*check = 1; 
		
		while(*input != '\0') /* check if the input of the number of random integers to be generated contains a character */
		{
			if(*input < '0' || *input > '9')
			{
				*check = 0;
			}
			
			input++;
		}
	}
}
