#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int getType()
{

	return 0;

}

//Begin of searchArray that takes void*/void*
void *searchArray(void *inArgs)
{
	//Define Struct
	struct argPack
	{

		int answer;
		int *randomArray;
		int size;
		int target;
		int step;
		int numInts;
	};

	//Instantiate struct and define characteristics that were fed in
	struct argPack *myArgs;

	myArgs = (struct argPack *)inArgs;

	int *randomArray = myArgs->randomArray;
	int length = myArgs->size;
	int target = myArgs->target;
	int procNum = myArgs->step;
	int numInts = myArgs->numInts;

	//init loops
	int i = procNum * numInts;
	int j = i + (numInts - 1);

	//Loop to search
	while (i < j)
	{
		printf("Testing: [%d] : %d\n", i, randomArray[i]);

		//Incremental search
		if (randomArray[i] == target)
		{
			printf("----------FOUND at [%d] in step number : %d\n", i, procNum + 1);
			myArgs->answer = i;
		}

		i++;
	}
	//return
	return 0;
}

//Search function that can be called from driver program. This had to be implemented so that we could incorporate the library for two separate files.
//The function search takes this same argument style, but handles it differently.
int searchFunction(int *randomArray, int size, int target, int numOfInts)
{
	//define our struct to give to the void*/void*
	typedef struct argPack
	{

		int answer;
		int *randomArray;
		int size;
		int target;
		int step;
		int numInts;

	} senderArgs;

	//instantiate it
	senderArgs myArgs;

	//make definitions
	myArgs.randomArray = randomArray;
	myArgs.size = size;
	myArgs.target = target;
	myArgs.numInts = numOfInts;

	//definte thread
	pthread_t threadId;

	//figure out size of steps.
	int numOfSections = myArgs.size / numOfInts;
	int remainder = myArgs.size % numOfInts;

	//initiate loop
	int i = 0;


	//loop
	while (i < numOfSections)
	{

		myArgs.step = i;

		pthread_create(&threadId, NULL, searchArray, (void *)&myArgs);
		pthread_join(threadId, NULL);

		i++;
	}

	//if size % (size of subsections) != 0, this will be the rest of the numbers to scan.
	//i.e 100%33 = 1 this would scan the last number.
	if (remainder > 0)
	{

		myArgs.size = remainder;
		pthread_create(&threadId, NULL, searchArray, (void *)&myArgs);
		pthread_join(threadId, NULL);
	}

	//return the final answer.
	return myArgs.answer;
}
