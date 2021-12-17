#define _DEFAULT_SOURCE
#include <time.h>
#include "newSleep.h"

/* NAME      : newSleep */
/* PURPOSE   : Delay the integer output to create arrow animation and swapping animation */
/* IMPORTS   : sec (output delay time in seconds) */
/* EXPORTS   : None */
/* ASSERTIONS: */
/*    PRE    : The output has no delay and has no animation */
/*    POST   : The output will be delayed for a few seconds and it has arrow animation and swapping animation */
/* REMARKS   : This algorithm is obtained from Blackboard */

void newSleep(float sec)
{
	struct timespec ts;
	ts.tv_sec = (int) sec;
	ts.tv_nsec = (sec - ((int) sec)) * 1000000000;
	nanosleep(&ts, NULL);
}
