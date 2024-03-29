#ifndef __CALCULATORS_H_
#define __CALCULATORS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXQZISE 100


typedef int Status;

typedef struct Node {
    void* data; 
    struct Node* next; 
} Node;

typedef struct {
    Node* front; 
    Node* rear; 
} Queue;



Queue* initQueue();
void enQueue(Queue* queue, void* data);
void* deQueue(Queue* queue);
void destroyQueue(Queue* queue);
Status GetHead(Queue Q, void** e);


#endif