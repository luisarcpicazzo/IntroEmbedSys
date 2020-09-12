/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Implements function prototypes provided by "stats.h"
 *
 * Implements the function prototypes provided by the "stats.h" file.
 * Calculates and prints the statistics required for a given dataset.
 *
 * @author Luis Eduardo Archundia Picazzo
 * @date 09/09/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
#define TRUE  1
#define FALSE 0
#define ODD   1
#define EVEN  0



#define MEDIAN_INDEX_OFFSET 1

/*
 * Indicates the first half of the array based on its
 * size. with its offset. 0 to n-1.
 */
#define EVEN_HALF_ARRAY ((SIZE/2) - 1)

/*
 *  Chops the last value to get the first half of the array as an integer 
 *  then works it out from there to get to the actual median index 
 */
#define ODD_HALF_ARRAY (((SIZE - 1) / 2) - 1) 

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int sortFlag = FALSE;
  int* isSortedFlag = &sortFlag;
  unsigned char* arrPtr = test;

  /* Statistics and Printing Functions Go Here */

  print_array(SIZE, test, isSortedFlag);
 
  printf("\n\nMinimum Value:\n");
  printf("%f", find_minimum(SIZE, test, isSortedFlag));
  printf("\n");

  printf("\n\nMaximum Value:\n");
  printf("%f", find_maximum(SIZE, test, isSortedFlag));
  printf("\n\n");

  printf("\n\nMean Value:\n");
  printf("%f", find_mean(SIZE, test));
  printf("\n\n");

  printf("\n\nMedian Value:\n");
  printf("%f", find_median(SIZE, test, isSortedFlag));
  printf("\n\n");

}

/* Add other Implementation File Code Here */

void sort_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
    unsigned char tempVal;
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0 + i; j < arrSize; j++)
	{
            if(*(arrPtr + i) < *(arrPtr + j))
	    {
	        tempVal = *(arrPtr + i);
		*(arrPtr + i) = *(arrPtr + j);
		*(arrPtr + j) = tempVal;
	    }
	} 
    }
    *isSortedFlag = TRUE;
}

float find_minimum(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{   
    int minValIndex = arrSize - 1;
    float minVal = 0.0f;

    if(*isSortedFlag == FALSE)
    {
        sort_array(arrSize, arrPtr, isSortedFlag);
        minVal = *(arrPtr + minValIndex);	
    }
    else
    {
        minVal = *(arrPtr + minValIndex);
    }
    return minVal;
}

float find_maximum(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
    int maxValIndex = 0;
    float maxVal = 0.0f;

    if(*isSortedFlag == FALSE)
    {
        sort_array(arrSize, arrPtr, isSortedFlag);
        maxVal = *(arrPtr + maxValIndex);	
    }
    else
    {
        maxVal = *(arrPtr + maxValIndex);
    }
    return maxVal;
    
}

float find_mean(int arrSize, unsigned char* arrPtr)
{   
    float tempVal = 0.0f;
    float meanVal = 0.0f;
    
    for(int i = 0; i < arrSize; i++)
    {
        tempVal = tempVal + *(arrPtr + i);
    }
    return meanVal = tempVal / arrSize; 
}

float find_median(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
    int arrType = 0;
    int index = 0;
    float medianVal = 0.0f;
    float tempVal = 0.0f;

    if(*isSortedFlag == FALSE)
    {
        sort_array(arrSize, arrPtr, isSortedFlag);
        if(arrSize % 2 == 0)
        {
            arrType = EVEN;
        }
        else
        {
            arrType = ODD;
        }    	
    }
    else
    {
        if(arrSize % 2 == 0)
        {
            arrType = EVEN;
        }  
        else
        {
            arrType = ODD;
        }
    }
    switch (arrType)
    {
        case EVEN:
	    index = EVEN_HALF_ARRAY;
	    tempVal = *(arrPtr + index) + *(arrPtr + index + MEDIAN_INDEX_OFFSET);
	    medianVal = tempVal/2;
	    break;

       	case ODD:
	    index = ODD_HALF_ARRAY;
	    medianVal = *(arrPtr + index + MEDIAN_INDEX_OFFSET);
	    break;
    }
    return medianVal;
 
}

void print_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
    int it = 0;
    int tempArraySize = (arrSize/4);
    int pastIter = 0;
    int tempVar = 0;
    if(*isSortedFlag == FALSE)
    {
	// Print unsorted array
	for(int it = 0; it < arrSize; it++)
        {	
	    if(it == 10 || it == 20 || it == 30)
	    {
                printf("\n");
	    }
            if(it == arrSize - 1)
            { 
                printf("%d ", *(arrPtr + it));
            }
            else
            {
                printf("%d, ", *(arrPtr + it));
            }
        }
	
        sort_array(arrSize, arrPtr, isSortedFlag);
	print_array(arrSize, arrPtr, isSortedFlag);
    } 
    else
    {
        // Print sorted array
        printf("\n\nSorted Array:\n");
	for(int it = 0; it < arrSize; it++)
        {
            if(it == arrSize - 1)
            { 
                printf("%d ", *(arrPtr + it));
            }
            else
            {
                printf("%d, ", *(arrPtr + it));
            }
        }

        

    }
}

void print_statistics(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}





