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

  printf("\n\nUnsorted Array:\n");
  for(int it = 0; it < SIZE; it++)
  {
      if(it == SIZE - 1)
      {
          printf("%d ", test[it]);
      }
      else
      {
          printf("%d, ", test[it]);
      }
  }
 
  sort_array(SIZE, test, isSortedFlag);
 
  printf("\n\nSorted Array:\n");
  for(int it = 0; it < SIZE; it++)
  {
      if(it == SIZE - 1)
      {
          printf("%d ", test[it]);
      }
      else
      {
          printf("%d, ", test[it]);
      }
  }

  printf("\n\nMinimum Value:\n");
  printf("%f", find_minimum(SIZE, test, isSortedFlag));
  printf("\n");

  printf("\n\nMaximum Value:\n");
  printf("%f", find_maximum(SIZE, test, isSortedFlag));
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
}

float find_median(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{

    int arrType = 0;
    if(*isSortedFlag == FALSE)
    {
        sort_array(arrSize, arrPtr, isSortedFlag);     
    }
    if(arrSize % 2 == 0)
    {
        arrType = EVEN;
    }
    else
    {
        arrType = ODD;
    }
    
    switch (arrType)
    {
        case EVEN:
             break;

	case ODD:
	     break;
    }
 
}

void print_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

void print_statistics(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}





