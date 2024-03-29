#ifndef __DECLARATION_H_
#define __DECLARATION_H_
//学到的技巧：怕这个定义数据报错，LNK2005，即多个源文件应用这个头文件导致的反复定义，就可以加上__declspec(selectany)的这个前缀
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//__declspec(selectany) int option1 = 0;
//__declspec(selectany) int length = 0;
// 定义链表节点结构
struct Node {
    int data;
    struct Node* next;
};

struct Node2 {
    int data;
    struct Node2* prior;
    struct Node2* next;
};

// 单链表的函数声明
struct Node* createNode(int data);
void insertNode(int pnewData, int num);
void showList(struct Node* head);
void showLength(struct Node* head);
void deleteNode(int num);
void change(int data, int num);
void destroy(struct Node* head);
__declspec(selectany) struct Node* head, * tail = NULL;




//双链表的函数声明
struct Node2* createNode2(int data);
void insertNode2(int pnewData, int num);
void showList2(struct Node2* phead);
__declspec(selectany) struct Node2* head2, * tail2 = NULL;
void change2(int data, int num);
void deleteNode2(int num);
void destroy2(struct Node2* phead);
void showLength2(struct Node2* phead);





#endif