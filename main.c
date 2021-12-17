#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "createArray.h"
#include "checkInteger.h"
#include "selectionSort.h"

/* NAME      : main */
/* PURPOSE   : Check for all the initial conditions to perform the selection sort algorithm and initialize all the variables */
/* IMPORTS   : None */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : The program will run the main function first */
/*    POST   : The main function will check all the initial conditions. If all the initial conditions are correct, the program will start to perform the selection sort algorithm */
/* REMARKS   : check == 0 (selection sort algorithm will not be carried out); check == 1 (selection sort algorithm will be carried out) */

int main(int argc, char *argv[])
{	
	int check = 1;        /* to determine whether should perform the selection sort algorithm */
	int noElements = 0;   /* number of integers in the integer array */
	int *iArray = NULL;   /* integer array */
	float sleep = 0;      /* lenght of sleeping time */
	
	if(argc < 2 || argc > 3)
	{
		printf("Please enter only 2 or 3 command line arguments.\n"); 
	}
	else
	{
		srand(time(NULL)); /* create a random seed */
		checkInteger(argv[1], &check, 1); /* check the errors for the sleep time command line argument */
		
		if(argc == 2 && check == 1)
		{	
			iArray = createArray("None", argc, &noElements, &check); /* call function to create an integer array */ 
		}
		else if(argc == 3 && check == 1)
		{
			iArray = createArray(argv[2], argc, &noElements, &check); /* call function to create an integer array */ 
		}
		
		if(check == 1)
		{
			sleep = atof(argv[1]);
			selectionSort(iArray, noElements, sleep); /* start to perform the selection sort algorithm */
		}
	}
	
	free(iArray); /* free the integer array */
	
	return 0;
}
