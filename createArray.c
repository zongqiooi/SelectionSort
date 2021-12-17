#include <stdio.h>
#include <stdlib.h>
#include "createArray.h"
#include "checkInteger.h"

/* NAME      : createArray */
/* PURPOSE   : Create an integer array based on the command line arguments provided */
/* IMPORTS   : *filename (file name that contains the integers), argc (number of command line arguments), *noElements (number of integers in the integer array), */
/*             *check (determine whether to perform selection sort algorithm) */
/* EXPORTS   : iArray (integer array that contains all the integers) */
/* ASSERTIONS: */
/*    PRE    : This function will be called to create an integer array */
/*    POST   : If all the conditions are fulfilled, an integer array that contains 3 to 10 integers will be created  */
/* REMARKS   : argc == 2 (create a random integer array); argc == 3 (create an integer array based on the integers in the text file) */

int *createArray(char *filename, int argc, int *noElements, int *check)
{
	char input[1000];     /* string input */
	int i = 0;            /* loop variable i */
	int ch = 1;           /* for tracking the file pointer until EOF */
	int valueError = 0;   /* determine whether the integer is in the range of 0 to 999 */
	int *iArray = NULL;   /* integer array */
	FILE *inPtr = NULL;   /* input file pointer */
	
	if(argc == 2)
	{
		system("clear");
		printf("Please enter the amount of numbers you want to sort (3-10 inclusive): ");

		do
		{
			scanf("%s", input); 
			checkInteger(input, check, 2); /* check if the input is in integer data type */
						
			if(*check == 1)
			{
				*noElements = atoi(input);
				
				if(*noElements < 3 || *noElements > 10) /* check if the input is between 3 to 10 */
				{
					*check = 0;
				}
			}
			
			if (*check == 0)
			{
				printf("Invalid value or data type for the input. Please try again.\n\n");
				printf("Please enter the amount of numbers you want to sort (3-10 inclusive): ");
			}
			
		} while(*check == 0); /* keep prompting until user enters a valid value */
		
		iArray = (int *)malloc((*noElements) * sizeof(int)); /* create an integer array */
		
		for(i = 0; i < *noElements; i++)
		{
			iArray[i] = rand() % 1000;
		}
	}
	else if(argc == 3)
	{
		inPtr = fopen(filename, "r");
	
		if(inPtr == NULL)
		{
			perror("Error in opening the file");
			*check = 0;
		}
		else
		{
			while(ch != EOF)
			{
				ch = fgetc(inPtr); 
				
				if(ch == '\n') /* to check the number of integers in number.txt file */
				{
					*noElements += 1; 
				}
			} 
		
			if(*noElements < 3 || *noElements > 10) /* to check if the number of integers in number.txt file is between 3 to 10 */
			{
				*check = 0; 
				printf("Please ensure the number of integers in the number.txt is between 3 to 10 inclusively.\n");
			}
			else 
			{
				iArray = (int *)malloc((*noElements) * sizeof(int)); /* create an integer array */
				rewind(inPtr); /* relocate the file pointer to the first position */
				
				for(i = 0; i < *noElements; i++)
				{
					fscanf(inPtr, "%d\n", &iArray[i]);
					
					if(iArray[i] < 0 || iArray[i] > 999) /* to check whether the integers are between the range of 0 to 999 */
					{
						valueError = 1; 
						*check = 0; 
					}
				}
			}

			if(valueError == 1)
			{
				printf("Please ensure the value of integers in the number.txt is between 0 to 999 inclusively.\n");
			}			
						
			fclose(inPtr); /* close the file after reading */
		}
	}

	return iArray; /* return an integer array to the main function */
}
