#ifndef __DECLARATION_H_
#define __DECLARATION_H_
//ѧ���ļ��ɣ�������������ݱ���LNK2005�������Դ�ļ�Ӧ�����ͷ�ļ����µķ������壬�Ϳ��Լ���__declspec(selectany)�����ǰ׺
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//__declspec(selectany) int option1 = 0;
//__declspec(selectany) int length = 0;
// ��������ڵ�ṹ
struct Node {
    int data;
    struct Node* next;
};

struct Node2 {
    int data;
    struct Node2* prior;
    struct Node2* next;
};

// ������ĺ�������
struct Node* createNode(int data);
void insertNode();
void showList(struct Node* head);
int showLength(struct Node* phead);
void deleteNode(int num);
void change();
void destroy(struct Node* head);
__declspec(selectany) struct Node* head, * tail = NULL;

void OddEvenChange(struct Node** head);
void ShowMiddle(struct Node* phead);
void hasCycle1(struct Node* phead);
struct Node* ReverseList1(struct Node* phead);


//˫����ĺ�������
struct Node2* createNode2(int data);
void insertNode2();
void showList2(struct Node2* phead);
__declspec(selectany) struct Node2* head2, * tail2 = NULL;
void change2();
void deleteNode2(int num);
void destroy2(struct Node2* phead);
int showLength2(struct Node2* phead);
void hasCycle2(struct Node2* phead);
struct Node2* ReverseList2(struct Node2* phead);




#endif