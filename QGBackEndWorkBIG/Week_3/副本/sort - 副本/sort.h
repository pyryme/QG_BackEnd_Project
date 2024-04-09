#ifndef __SORT_H_
#define __SORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

void insertsort(int* arr, unsigned int n);
void _mergesort(int* arr, int* arrtmp, int start, int end);
void mergesort(int* arr, unsigned int len);
void quicksort(int* arr, unsigned int n);
int arrmax(int* arr, unsigned int len);
void countsort(int* arr, unsigned int len);
void _radixsort(int* arr, unsigned int len, unsigned int exp);
void radixsort(int* arr, unsigned int len);

void generateTestData(const char* filename, int count);
int* readDataFromFile(const char* filename, int count);
void printSortedArray(int* arr, int count);
void generateRandomNumbers(int* arr, int count);
void evaluateSortingAlgorithm(void (*sortFunction)(int*, unsigned int), int count);
void evaluateSortingAlgorithmSmallData(void (*sortFunction)(int*, unsigned int), int dataSize, int numIterations);



#endif
