#ifndef __ADDITONALPARTSORT_H_
#define __ADDITONALPARTSORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

void NonRecursiveQuickSort(int arr[], int l, int h);
void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);


int RandomPartition(int arr[], int low, int high);
void RandomQuickSort(int arr[], int low, int high);
void triMedian(int arr[], int low, int high);
int partition2(int arr[], int low, int high);
void TriQuickSort(int arr[], int low, int high);//原理不理解??????????

void bubbleSort1(int arr[], int n);
void bubbleSort2(int arr[], int n);
void bubbleSort3(int arr[], int n);

#endif
