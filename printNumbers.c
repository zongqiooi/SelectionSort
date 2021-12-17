#include <stdio.h>
#include <stdlib.h>
#include "printNumbers.h"
#include "color.h"
#include "newSleep.h"

/* NAME      : printNumbers */
/* PURPOSE   : Print the arrow and the integers contained in the integer array on the terminal */
/* IMPORTS   : *iArray (integer array that contains all the integers), noElements (number of integers in the integer array), sleep (interval of sleeping time), */
/*             spaces (number of spaces before printing the arrow), minIndex (index of the current minimum integer), swapTimes (number of swapped integers) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to print out the arrow and the integers contained in the integer array on the terminal */
/*    POST   : The arrow and the integers contained in the integer will be printed on the terminal */
/* REMARKS   : None */

void printNumbers(int *iArray, int noElements, float sleep, int spaces, int minIndex, int swapTimes)
{
	int i = 0; /* loop variable i */
	
	system("clear");
	printf("\n");

	for(i = 0; i < noElements; i++)
	{
		if(i < swapTimes) /* print the swapped integers in green color */
		{		
			greenPrint(iArray[i]);
		}
		else if(i == minIndex) /* print the current minimum integer in red color */
		{
			redPrint(iArray[i]);
		}
		else /* print the other integers in default white color */
		{
			printf("%03d ", iArray[i]);
		}
	}

	printf("\n");
	
	for(i = 0; i < spaces; i++) /* print the spaces before the arrow */
	{
		printf("    "); 
	}
	
	printf(" ^\n"); /* print the arrow below the integers */
	newSleep(sleep); /* delay the output for the arrow animation */
}
