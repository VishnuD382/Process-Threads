#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int result = 0;

int getType()
{

	return 1;

}

//Search array process
int searchArrayProcs(int *randomArray, int length, int target, int procNum)
{
	//loop
	int i = 0;
	for (i = 0; i < length; i++)
	{
		//test it
		printf("Testing [%d]: %d\n", procNum * length + i, randomArray[i + procNum * length]);

		//if equal
		if (target == randomArray[procNum * length + i])
		{
			printf("-____ found in proc %d, randdom[%d] \n", procNum, procNum * length + i);
			return i; ////(procNum * length + i);
		}
	}

	//return if not found
	return 251;
}

int searchFunction(int *randomArray, int size, int target, int numOfInts)
{

	//need to find the element IF FOUND return the location of where it was found.
	//have one process deal with 250 integers.

	//define vars
	int answer = 0;
	int i = 0;
	int j = 0;

	//do you really read these?
	//get the PID
	int pid;

	//status
	int status;

	//define the size of the sections
	int numInts = numOfInts;	  // how many ints each process searches
	int numProc = size / numInts; // Makes 2 children: each child should search through 5 ints

	//remainder for any numbers outside the division
	int remainder = 0;

	//define remainder
	if (size % numInts != 0)
	{
		remainder = (size % numInts);
		numProc++;
	}

	//a
	int a = 0;

	//set pid holder for the child
	pid_t child;

	//Which process?
	printf("size %d, numProc %d\n", size, numProc);

	//loop to fork
	for (i = 0; i < numProc; i++)
	{
		child = fork(); //  forks makes child processes

		//Don't wann fork bomb
		if (child < 0)
		{

			//No bueno
			printf("ERROR!!! \n");
			exit(0);
		}

		else if (child == 0)
		{

			//Bueno! Do stuff...
			printf("child %d\n", getpid());

			if (remainder == 0)
				a = (searchArrayProcs(randomArray, numInts, target, i));

			else if (remainder != 0 && i == (numProc - 1))
				a = (searchArrayProcs(randomArray, remainder, target, i));

			exit(a);
		}
	}

	//check return vals
	for (i = 0; i < numProc; i++)
	{
		//PID!!! And now we wait.....
		pid = wait(&status);


		//Exit status check
		if (WIFEXITED(status))
		{
			//Failed!
			if (WEXITSTATUS(status) == 251) // failed
				printf("---------DID NOT FIND in proc\n");
			//ANSWER
			else
			{
				answer = WEXITSTATUS(status);
				//answer = answer + (numOfInts * i);
			}

			printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
		}
	}

	//RETURN!
	return answer;
};
