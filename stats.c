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

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int isSortedFlag = FALSE;
  unsigned char* arrPtr = test;

  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */

void sort_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

float find_minimum(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

float find_maximum(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

float find_mean(int arrSize, unsigned char* arrPtr)
{
}

float find_median(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

void print_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}

void print_statistics(int arrSize, unsigned char* arrPtr, int* isSortedFlag)
{
}





