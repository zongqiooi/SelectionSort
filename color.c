#include <stdio.h>
#include <stdlib.h>
#include "color.h"

/* There is a total of 2 functions in this color.c file */

/* NAME      : redPrint */
/* PURPOSE   : Print the current minimum integer in red color */
/* IMPORTS   : value (current minimum integer to be printed in red color) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to print the current minimum integer in red color */
/*    POST   : The current minimum integer is printed in red color */
/* REMARKS   : None */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/* NAME      : greenPrint */
/* PURPOSE   : Print the swapped integers in green color */
/* IMPORTS   : value (swapped integers to be printed in green color) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : This function will be called to print the swapped integers in green color */
/*    POST   : The swapped integers are printed in green color */
/* REMARKS   : None */

void redPrint(int value)
{
	printf("\033[0;31m"); 
	printf("%03d ", value); /* current minimum integer will be printed in red color */
	printf("\033[0m");
}

void greenPrint(int value)
{
	printf("\033[0;32m"); 
	printf("%03d ", value); /* swapped integers will be printed in green color */
	printf("\033[0m");
}
