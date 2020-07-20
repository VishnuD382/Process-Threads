#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "multitest.h"

//Zero out the array
void zeroArray(double *array, int size)
{
	//It's a loop to zero out the array... This isn't rocket science (IT'S COMPUTER SCIENCE!)...
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    return NULL;
}

double average(double array[], int size)
{
    //Take the average of the steps
	double sum = 0;
    int i = 0;

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return (sum / size);
}

float variance(double *array, int size, double avg)
{
	//Get the variance of the steps
    int i;
    double var = 0;
    int temp = 0;
    for (i = 0; i < size; i++)
        var += (array[i] - avg) *
               (array[i] - avg);

    return (float)(var / size);
}

float std(float var)
{
	//Standard dev.
    return sqrt(var);
}

int main(char **argv, int argc)
{
	//define time tables
    struct timeval start;
    struct timeval end;

    //Make all of our timetables	
	double aTime = 0, bTime = 0, cTime = 0, dTime = 0, eTime = 0, fTime = 0, gTime = 0, hTime = 0;

    double minA = INT_MAX, minB = INT_MAX, minC = INT_MAX, minD = INT_MAX, minE = INT_MAX, minF = INT_MAX, minG = INT_MAX, minH = INT_MAX;

    double maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN, maxD = INT_MIN, maxE = INT_MIN, maxF = INT_MIN, maxG = INT_MIN, maxH = INT_MIN;

    double avgA = 0, avgB = 0, avgC = 0, avgD = 0, avgE = 0, avgF = 0, avgG = 0, avgH = 0;

	//define our first step
    int j = 0, i = 0;

    int size = 2000;
    int numOfInts = 1000;
    int target = 13;

    int *testArray;

    testArray = randomGenerator(size);

	int result[8];
    int avgSet = 5; //amount of time you want to run each part.

	//get the time
    double *timeArray = malloc(avgSet * sizeof(double));

    zeroArray(timeArray, avgSet);

	//show original array
    while (i < size)
    {

        printf("testArray[%d] = %d\n", i, testArray[i]);

        i++;
    }

	//run our search
    for (i = 0; i < avgSet; i++) // PART A
    {
        gettimeofday(&start, 0);

        result[0] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);

        aTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (aTime < minA)
            minA = aTime;
        if (aTime > maxA)
            maxA = aTime;

        timeArray[i] = aTime;
    }
	
	//get our information regarding time.
    avgA = average(timeArray, avgSet);
    double varA = variance(timeArray, avgSet, avgA);
    double stdA = std(varA);

    zeroArray(timeArray, avgSet);

    /////////////////////////////////////////////////////////

	//Repeat siz more times with different numbers
    numOfInts = 500;

    for (i = 0; i < avgSet; i++) // PART B
    {
        gettimeofday(&start, 0);

        result[1] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);

        bTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (bTime < minB)
            minB = bTime;
        if (bTime > maxB)
            maxB = bTime;

        timeArray[i] = bTime;
    }

    avgB = average(timeArray, avgSet);
    double varB = variance(timeArray, avgSet, avgB);
    double stdB = std(varB);

    zeroArray(timeArray, avgSet);

    /////////////////////////////////////////////////////////

    numOfInts = 250;

    for (i = 0; i < avgSet; i++) // PART C
    {
        gettimeofday(&start, 0);

        result[2] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);

        cTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (cTime < minC)
            minC = cTime;
        if (cTime > maxC)
            maxC = cTime;

        timeArray[i] = cTime;
    }

    avgC = average(timeArray, avgSet);
    double varC = variance(timeArray, avgSet, avgC);
    double stdC = std(varC);

    zeroArray(timeArray, avgSet);

    /////////////////////////////////////////////////////////

    numOfInts = 125;

    for (i = 0; i < avgSet; i++) // PART D
    {
        gettimeofday(&start, 0);

        result[3] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);
        dTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (dTime < minD)
            minD = dTime;
        if (dTime > maxD)
            maxD = dTime;

        timeArray[i] = dTime;
    }
    avgD = average(timeArray, avgSet);
    double varD = variance(timeArray, avgSet, avgD);
    double stdD = std(varD);

    zeroArray(timeArray, avgSet);

    /////////////////////////////////////////////////////////

    numOfInts = 100;

    for (i = 0; i < avgSet; i++) // PART E
    {
        gettimeofday(&start, 0);

        result[4] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);
        eTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (eTime < minE)
            minE = eTime;
        if (eTime > maxE)
            maxE = eTime;

        timeArray[i] = eTime;
    }
    avgE = average(timeArray, avgSet);
    double varE = variance(timeArray, avgSet, avgE);
    double stdE = std(varE);
    zeroArray(timeArray, avgSet);

    /////////////////////////////////////////////////////////

    numOfInts = 50;

    for (i = 0; i < avgSet; i++) // PART F
    {
        gettimeofday(&start, 0);

        result[5] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);
        fTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (fTime < minF)
            minF = fTime;
        if (fTime > maxF)
            maxF = fTime;

        timeArray[i] = fTime;
    }
    avgF = average(timeArray, avgSet);
    double varF = variance(timeArray, avgSet, avgF);
    double stdF = std(varF);
    zeroArray(timeArray, avgSet);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    numOfInts = 20;

    for (i = 0; i < avgSet; i++) // PART G
    {
        gettimeofday(&start, 0);

        result[6] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);
        gTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (gTime < minG)
            minG = gTime;
        if (gTime > maxG)
            maxG = gTime;

        timeArray[i] = gTime;
    }
    avgG = average(timeArray, avgSet);
    double varG = variance(timeArray, avgSet, avgG);
    double stdG = std(varG);
    zeroArray(timeArray, avgSet);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    numOfInts = 250;
    size = 20000;
    testArray = randomGenerator(size);

    for (i = 0; i < avgSet; i++) // PART H
    {
        gettimeofday(&start, 0);

        result[7] = searchFunction(testArray, size, target, numOfInts);

        gettimeofday(&end, 0);
        hTime = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

        if (hTime < minH)
            minH = hTime;
        if (hTime > maxH)
            maxH = hTime;

        timeArray[i] = hTime;
    }
    avgH = average(timeArray, avgSet);
    double varH = variance(timeArray, avgSet, avgH);
    double stdH = std(varH);
    zeroArray(timeArray, avgSet);



    ///////////////////////////////////////////////////////////////////////////////////////////////////



	//print results

	if (getType())
	{
	
		printf("\n\n////////////////////////////////////////\n");
		printf("/         Process testing              /\n");
		printf("////////////////////////////////////////\n\n");

	}

	else
	{
		printf("\n\n////////////////////////////////////////\n");
		printf("/         Thread testing              /\n");
		printf("///////////////////////////////////////\n\n");

	}

	printf("\n%d was found at index %d in the array", target, result[0]);
	printf("\nAverage time to complete A: %lf for %d steps \n", avgA, 2);
    printf("\n\nMax in A %lf\t Min in A %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxA, minA, varA * 100000, stdA);
    printf("--------------------------------------------\n");
	

	printf("\n%d was found at index %d in the array", target, result[1]);
    printf("\nAverage time to complete B: %lf for %d steps \n", avgB / 10, 4);
    printf("\n\nMax in B %lf\t Min in B  %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxB, minB, varB * 100000, stdB);
    printf("--------------------------------------------\n");

	printf("\n%d was found at index %d in the array", target, result[2]);
    printf("\nAverage time to complete C: %lf for %d steps \n", avgC / 10, 8);
    printf("\n\nMax in C %lf\t Min in C %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxC, minC, varC * 100000, stdC);
    printf("--------------------------------------------\n");
	
	printf("\n%d was found at index %d in the array", target, result[3]);
    printf("\nAverage time to complete D: %lf for %d steps \n", avgD / 10, 16);
    printf("\n\nMax in D %lf\t Min in D %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxD, minD, varD * 100000, stdD);
    printf("--------------------------------------------\n");

	printf("\n%d was found at index %d in the array", target, result[4]);
    printf("\nAverage time to complete E: %lf for %d steps \n", avgE / 10, 20);
    printf("\n\nMax in E %lf\t Min in E %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxE, minE, varE * 100000, stdE);
    printf("--------------------------------------------\n");

	printf("\n%d was found at index %d in the array", target, result[5]);
    printf("\nAverage time to complete F: %lf for %d steps \n", avgF / 10, 40);
    printf("\n\nMax in F %lf\t Min in F %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxF, minF, varF * 100000, stdF);
    printf("--------------------------------------------\n");

	printf("\n%d was found at index %d in the array", target, result[6]);
    printf("\nAverage time to complete G: %lf for %d steps \n", avgG / 10, 40);
    printf("\n\nMax in G %lf\t Min in G %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxG, minG, varG * 100000, stdG);
    printf("--------------------------------------------\n");

	printf("\n%d was found at index %d in the array", target, result[7]);
    printf("\nAverage time to complete H: %lf for %d steps \n", avgH / 10, 80);
    printf("\n\nMax in H %lf\t Min in H %lf \nVariance %lf \t Standard Deviation %lf\n\n", maxH, minH, varH * 100000, stdH);
    printf("--------------------------------------------\n");

    return 0;
}
