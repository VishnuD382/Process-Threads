#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


//This is just to generate the array... I figured it easier to read if it wasn't in the driver program

int *swap(int *array, int rand, int num)
{

	//swap our number

    int temp = array[num];

    array[num] = array[rand];

    array[rand] = temp;

    return array;
}

//Make a random array!!!
int *randomGenerator(int size)
{
	//random me!
    srand(time(0));

	//define array size
    int arraySize = size;
    int i, j;

	//make array
    int *randomArray = malloc(arraySize * sizeof(int));

	//make array
    for (j = 0; j < size; ++j)
    {
        randomArray[j] = j;
    }

	//swivel numbers
    for (i = 0; i < size; i++)
    {
        int random = rand() % (i + 1);
        swap(randomArray, random, i);
    }

	//return the array
    return randomArray;
}

