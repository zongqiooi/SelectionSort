#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "color.h"

/* There is a total of 6 functions in this linkedList.c file */

/* NAME      : createLinkedList */
/* PURPOSE   : Create a linked list with head and count to store the integer array copy for printing the log on terminal */
/* IMPORTS   : None */
/* EXPORTS   : LL (linked list) */
/* ASSERTIONS: */
/*    PRE    : This function is called from the selectionSort.c to create a linked list */
/*    POST   : The linked list is created to store all the integer array copy for printing the log on the terminal */
/* REMARKS   : This algorithm is obtained from Practical 6 */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : insertLast */
/* PURPOSE   : Create a new linked list node and insert the integer array copy into the new linked list node when a swap action is occurred */
/* IMPORTS   : *list (linked list), *entry (data of the linked list node) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function is called by the selectionSort() function in selectionSort.c when a swap action is occurred */
/*    POST   : The new linked list node is created and the data from the integer array copy will be stored inside the new linked list node */
/* REMARKS   : This algorithm is obtained from Practical 6 */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : printLinkedList */
/* PURPOSE   : Print the integer array copy contained in all the linked list nodes on the terminal after the selection sort algorithm is finished */
/* IMPORTS   : *list (linked list), funcPtr (function pointer) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : The printResult() function will be called to print the integer array copy on the terminal */
/*    POST   : The values in the integer array copy in all the linked list nodes are printed on the terminal at the end of the program */
/* REMARKS   : This algorithm is obtained from Practical 6 */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : freeLinkedList */
/* PURPOSE   : Free the memories contained in all the linked list nodes and linked list */
/* IMPORTS   : *list (linked list), funcPtr (function pointer) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : The freeNode() function will be called to free all the memories */
/*    POST   : The memories contained in all the linked list nodes and linked list are freed */
/* REMARKS   : This algorithm is obtained from Practical 6 */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : printResult */
/* PURPOSE   : Print the integer array copy contained in all the linked list nodes on the terminal */
/* IMPORTS   : *data (data that points to the integer array copy) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function is called by the printLinkedList() function */
/*    POST   : The values in the integer array copy in all the linked list nodes are printed on the terminal */
/* REMARKS   : This algorithm is obtained from Practical 6 */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : freeNode */
/* PURPOSE   : Free the memories contained in all the linked list nodes */
/* IMPORTS   : *data (data that points to the integer array copy) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function is called by the freeLinkedList() function */
/*    POST   : The memories in all the linked list nodes are freed */
/* REMARKS   : This algorithm is obtained from Practical 6 */

LinkedList *createLinkedList()
{
	LinkedList *LL = NULL; 
	
	LL = (LinkedList *)malloc(sizeof(LinkedList)); /* create a linked list */
	LL->head = NULL; 
	LL->count = 0; 
	
	return LL; 
} 
	
void insertLast(LinkedList *list, void *entry)
{
	LinkedListNode *newNode = NULL;
	
	newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode)); /* create a new linked list node */
	newNode->data = entry; 
	newNode->next = NULL; 
	
	if(list->head == NULL) /* when there is no linked list node in the linked list */
	{
		list->head = newNode; /* points the head of the linked list to the new linked list node */
	}
	else /* when there is one or more linked list node in the linked list */
	{
		LinkedListNode *curr = NULL; /* create a current pointer for the purpose of pointing to next linked list node */
		curr = list->head; /* points the current pointer to where the head of the linked list points to */
		
		while(curr->next != NULL) 
		{
			curr = curr->next; /* the current pointer will point to the next linked list node until the last linked list node is reached */
		}
	
		curr->next = newNode; /* insert new linked list node into the linked list when last linked list node is reached */
	}

	list->count++; 
}

void printLinkedList(LinkedList *list, listFunc funcPtr)
{
	int i = 0; /* loop variable i */
	LinkedListNode *curr = NULL; 
	
	curr = list->head; 
	
	for(i = 0; i < ((list->count) - 1); i++) /* move to the last linked list node to obtain the sorted integer array */
	{
		curr = curr->next;
	}
	
	(*funcPtr)(curr->data); /* call the printResult() function to print the sorted integer array */
	curr = list->head; /* points the curr back to the linked list head */
	
	while(curr != NULL) /* print all the log contained in the linked list node on the terminal */
	{
		(*funcPtr)(curr->data); /* call the printResult() function to print the integer array information after every swap */
		curr = curr->next;
	}
}

void freeLinkedList(LinkedList *list, listFunc funcPtr)
{
	LinkedListNode *curr = NULL;
	LinkedListNode *nextCurr = NULL;
	
	curr = list->head; 
	
	while(curr != NULL) /* free all the linked list node */
	{
		nextCurr = curr->next; 
		(*funcPtr)(curr->data); 
		free(curr);
		curr = nextCurr; 
	}
	
	free(list); /* free the linked list */
}

void printResult(void *data)
{
	int i = 0;                /* loop variable i */
	static int runOnce = 0;   /* allow some specific code to be runned once only */
	static int noValue = 0;   /* to keep track the current number of the linked list node being accessed in the linked list */
	
	if(runOnce == 0) /* this part will only run once to print out the sorted integer array as the first line on the terminal */
	{
		system("clear");
		printf("Sorted Array: ");
		
		for(i = 0; i < ((Numbers *)data)->noElements; i++)
		{	
			greenPrint(((Numbers *)data)->iArray[i]); /* print the sorted integer array in green color */
		}
		
		printf("\n\n");
		printf("Process log:\n");
		runOnce = 1; 
	}
	else
	{
		for(i = 0; i < ((Numbers *)data)->noElements; i++) /* print every elements of the integer array in a horizontal line */
		{	
			if(i < ((Numbers *)data)->swapTimes)
			{
				greenPrint(((Numbers *)data)->iArray[i]); /* print the swapped integers in green color */
			}
			else
			{
				printf("%03d ", ((Numbers *)data)->iArray[i]);
			}
		}
		
		if((noValue >= 0 && noValue <= (((Numbers *)data)->noElements) - 2) && ((Numbers *)data)->swapDetect == 1) /* for the case when swapping is occurred */
		{
			printf("\nValue number %d is %03d after replacing %03d.\n\n", noValue + 1, ((Numbers *)data)->iArray[noValue], ((Numbers *)data)->iArray[((Numbers *)data)->minIndex]);
		}
		else if((noValue >= 0 && noValue <= (((Numbers *)data)->noElements) - 2) && ((Numbers *)data)->swapDetect == 0) /* for the case when swapping is not occurred */
		{
			printf("\nValue number %d is %03d. It was already in the right spot.\n\n", noValue + 1, ((Numbers *)data)->iArray[((Numbers *)data)->minIndex]);
		}
		else /* for the last line on the terminal */
		{
			printf("\nThen, the last number is %03d.\n\n", ((Numbers *)data)->iArray[noValue]);
		}
		
		noValue += 1;
	}
}

void freeNode(void *data)
{
	free(((Numbers *)data)->iArray); /* free the integer array */
	free((Numbers *)data); /* free the linked list node */
}
