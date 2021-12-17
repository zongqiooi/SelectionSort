#include <stdlib.h>
#include "selectionSort.h"
#include "linkedList.h"
#include "swapNumbers.h"
#include "printNumbers.h"

/* NAME      : selectionSort */
/* PURPOSE   : Perform the selection sort algorithm for all the integers contained in the integer array */
/* IMPORTS   : *iArray (integer array that contains all the integers), noElements (number of integers in the integer array), sleep (interval of sleeping time) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to perform selection sort algorithm in ascending order */
/*    POST   : The integers contained in the integer array will be sorted in ascending order after carrying out the selection sort algorithm */
/* REMARKS   : None */

void selectionSort(int *iArray, int noElements, float sleep)
{
	int i = 0;                      /* loop variable i */
	int j = 0;                      /* loop variable j */
	int k = 0;                      /* loop variable k */
	int distance = 0;               /* distance between the current integer and the current minimum integer */
	int minIndex = 0;               /* index of the current minimum integer in the integer array */
	int swapTimes = 0;              /* number of swap times occurred */
	int swapDetect = 0;             /* determine whether the swapping of the integers has occurred */
	Numbers *numbersPtr = NULL;     /* pointer that points to the struct called Numbers */
	LinkedList *numbersLL = NULL;   /* linked list */
	
	numbersLL = createLinkedList(); /* create a linked list */

	for(i = 0; i < (noElements - 1); i++) /* check for all the integers except the last integer in the integer array */
	{
		minIndex = i; 
		swapDetect = 0;
		
		for(j = i + 1; j < noElements; j++) 
		{
			printNumbers(iArray, noElements, sleep, j - 1, minIndex, swapTimes); /* print the integer array and arrow on the terminal */
			
			if(iArray[j] < iArray[minIndex]) /* perform value checking for the integers */
			{
				swapDetect = 1;
				minIndex = j;
				distance = minIndex - i - 1; 			
			}
		}

		printNumbers(iArray, noElements, sleep, j - 1, minIndex, swapTimes); /* the checking starts from "i + 1" so need to call printNum() function one more time to match all the arrows */
		
		if(swapDetect == 1) /* perform the swapping animation if and only if the current index is not the minimum index */
		{
			swapNumbers(iArray, noElements, &iArray[minIndex], &iArray[i], distance, minIndex, i, sleep, swapTimes);
		}
		
		swapTimes += 1;
		numbersPtr = (Numbers *)malloc(sizeof(Numbers)); /* create a struct to store all the information in linked list node */
		numbersPtr->minIndex = minIndex; 
		numbersPtr->swapTimes = swapTimes;
		numbersPtr->swapDetect = swapDetect;
		numbersPtr->noElements = noElements; 
		numbersPtr->iArray = (int *)malloc(noElements * sizeof(int)); 
		
		for(k = 0; k < noElements; k++) /* create a copy of integer array */
		{
			numbersPtr->iArray[k] = iArray[k]; 
		}
		
		insertLast(numbersLL, numbersPtr); /* insert the integer array after every swap */
	}
	
	numbersPtr = (Numbers *)malloc(sizeof(Numbers)); /* create a struct to store all the information in linked list node */
	numbersPtr->swapTimes = swapTimes + 1;
	numbersPtr->noElements = noElements; 
	numbersPtr->iArray = (int *)malloc(noElements * sizeof(int)); 
	
	for(k = 0; k < noElements; k++) /* create a copy of integer array */
	{
		numbersPtr->iArray[k] = iArray[k]; 
	}
	
	insertLast(numbersLL, numbersPtr); /* insert the last integer array that skipped the selection sort algorithm */
	printLinkedList(numbersLL, &printResult); /* print all the contents in the linked list on the terminal at the end of program */
	freeLinkedList(numbersLL, &freeNode); /* free all the memories in the linked list after printing all the contents on the terminal */
}
