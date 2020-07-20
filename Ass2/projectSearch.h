#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#ifndef _search_h
#define _search_h

//Main function only... It just sends back a random array of any given number...
void *searchArray(void *inArgs);
int searchFunction(int *randomArray, int size, int target, int numofInts);

#endif // ! _search_h

//I think this is not using a macro.

//#define searchFunction(x, args, argsb, argsc) search(x, args, argsb, argsc); // if we change the names of the fork and threads now, it should work as we intended it to. I will just add an empty parameter to fork.

//searchFunction(testArray, size, target, numOfInts);
