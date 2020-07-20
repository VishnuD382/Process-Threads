#include <stdlib.h>
#include <stdio.h>

#ifndef _randomGenerator_h
#define _randomGenerator_h

//Main function only... It just sends back a random array of any given number...
int *randomGenerator(int *straightArray);

void *threadProcess(void *myArgs);

void *searchArray(void *inArgs);
int searchFunction(int *randomArray, int size, int target, int numofInts);

int getType();

#endif // ! _randomGenerator_h
