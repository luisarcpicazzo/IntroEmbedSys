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
 * @file stats.h 
 * @brief Function prototypes and macro definitions (if required) for "stats.c" 
 *
 * This file provides function prototypes and macro definitions for
 * the "stats.c" file, which implements the mentioned prototypes to perform
 * statistical computation of a given array of values.
 *
 * @author Luis Eduardo Archundia Picazzo
 * @date 09/09/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Sorts array from MAX to MIN values
 *
 * Using a pointer to an array, performs unsigned char sorting from
 * largest (zeroeth index) value within the array, to the smallest 
 * ((n-1) index) possible value within the array.
 *
 * @param int arrSize            ,the actual size of the array.
 * @param unsigned char* arrPtr  ,pointer to the array of values.
 * @param int* isSortedFlag      ,pointer to a Flag to determine array sorting state
 *
 * @return n/a
 */
 void sort_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag);
 
/**
 * @brief Finds the smallest value of a given data sample.
 *
 * Determines the smallest possible value, given an array. After
 * being sorted, returns the smallest value.
 *
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 * @param int* isSortedFlag     ,pointer to a Flag to determine array sorting state
 *
 * @return float number value
 */
  float find_minimum(int arrSize, unsigned char* arrPtr, int* isSortedFlag);
  
/**
 * @brief Finds the largest value of a given data sample.
 *
 * Determines the largest possible value, given an array. After
 * being sorted, returns the largest value.
 *
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 * @param int* isSortedFlag     ,pointer to a Flag to determine array sorting state
 *
 * @return float number value
 */
 float find_maximum(int arrSize, unsigned char* arrPtr, int* isSortedFlag);
 
/**
 * @brief Finds the average of a given set of data.
 *
 * Given an array of data, finds the average value of the input data
 * by dividing its total sum over its sample count.
 *
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 *
 * @return float number value
 */ 
 float find_mean(int arrSize, unsigned char* arrPtr);
 
 /**
 * @brief Finds the middle number of a sorted data set.
 *
 * Given a sorted data set, finds the middle number within. If
 * the input array is odd it takes the middle number otherwise it will
 * perform the average of the two inner numbers within the data set.
 *
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 * @param int* isSortedFlag     ,pointer to a Flag to determine array sorting state
 *
 * @return float number value
 */
 float find_median(int arrSize, unsigned char* arrPtr, int* isSortedFlag);
 
 /**
 * @brief Prints the array data sets both sorted and unsorted.
 *
 * Prints both the unsorted and sorted array datasets in an
 * easy-to-read format.
 *
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 * @param int* isSortedFlag     ,pointer to a Flag to determine array sorting state
 *
 * @return n/a
 */
 void print_array(int arrSize, unsigned char* arrPtr, int* isSortedFlag);
 
 /**
 * @brief Prints all the calculated statistics from a given dataset.
 *
 * Prints all the statistics required for the analysis rounded down to its
 * nearest integer.
 * 
 * @param int arrSize           ,the actual size of the array.
 * @param unsigned char* arrPtr ,pointer to the array of values.
 * @param int* isSortedFlag     ,pointer to a Flag to determine array sorting state
 *
 * @return n/a
 */
 void print_statistics(int arrSize, unsigned char* arrPtr, int* isSortedFlag);



#endif /* __STATS_H__ */
