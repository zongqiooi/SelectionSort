#include <stdio.h>
#include <stdlib.h>
#include "swapNumbers.h"
#include "color.h"
#include "newSleep.h"

/* NAME      : swapNumbers */
/* PURPOSE   : Perform swapping of numbers and output the swapping animation when carrying out the selection sort algorithm */
/* IMPORTS   : *iArray (integer array that contains all the integers), noElements (number of integers in the integer array), *min (current minimum integer found in the integer array), */
/*             *current (current integer that is being checked in the integer array), distance (distance between the current integer and the current minimum integer), */
/*             minIndex (index of the current minimum integer), currentIndex (index of the current integer), sleep (interval of sleeping time), swapTimes (number of swapped integers) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to swap the position of the current integer and the current minimum integer */
/*    POST   : The position of the current integer and the current minimum integer will be swapped */
/* REMARKS   : None */

void swapNumbers(int *iArray, int noElements, int *min, int *current, int distance, int minIndex, int currentIndex, float sleep, int swapTimes)
{
	int i = 0;           /* loop variable i */
	int j = 0;           /* loop variable j */
	int temp = 0;        /* temporary integer for swapping */
	int loopTimes = 0;   /* number of repetitions for the loop */
	
	loopTimes = distance + 2;
	
	/* Printing the integers in the integer array on the terminal and perform the swapping animation */
	for(i = 0; i < loopTimes; i++)
	{
		system("clear");
		
		/* Printing the first line on the terminal */
		for(j = 0; j < (currentIndex + i); j++)
		{
			printf("    "); 
		}
				
		printf("%03d ", *current);
		printf("\n");
		
		/* Printing the second line on the terminal */
		for(j = 0; j < noElements; j++)
		{
			if(j == minIndex || j == currentIndex)
			{
				printf("    ");
			}
			else if(j < swapTimes)
			{
				greenPrint(iArray[j]); /* print the swapped integers in green color */
			}
			else
			{
				printf("%03d ", iArray[j]);
			}
		}
		
		printf("\n");
		
		/* Printing the third line on the terminal */
		if(distance != -1)
		{
			printf("    ");
		}
		
		for(j = 0; j < distance; j++)
		{
			printf("    "); 
		}
	
		for(j = 0; j < currentIndex; j++)
		{
			printf("    "); 
		}
		
		redPrint(*min); /* print the current minimum integer in red color */
		printf("\n");
		distance -= 1;
		newSleep(sleep); /* delay the output for the swapping animation */
	}
	
	/* Actual swapping of the integers in the integer array address */
	temp = *min; 
	*min = *current;
	*current = temp;
}
