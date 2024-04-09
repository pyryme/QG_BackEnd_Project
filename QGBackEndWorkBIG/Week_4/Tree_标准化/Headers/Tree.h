#ifndef __TREE_H_
#define __TREE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100


// 二叉树节点的结构
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data);
struct TreeNode* insert(struct TreeNode* root, int data);
struct TreeNode* search(struct TreeNode* root, int data);
struct TreeNode* deleteNode(struct TreeNode* root, int data);
void inorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);

struct Stack* createStack();
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, struct TreeNode* node);
struct TreeNode* pop(struct Stack* stack);
void iterativePreorder(struct TreeNode* root);
void iterativeInorder(struct TreeNode* root);
void iterativePostorder(struct TreeNode* root);


struct Queue* createQueue();
int isQEmpty(struct Queue* queue);
int isFull(struct Queue* queue);
void enqueue(struct Queue* queue, struct TreeNode* node);
struct TreeNode* dequeue(struct Queue* queue);
void levelOrderTraversal(struct TreeNode* root);



#endif

