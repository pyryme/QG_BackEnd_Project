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

//ר������
#define MAXSIZE 100
typedef char ElemType;//#define ElemType char
typedef int Status;

typedef struct StackNode{
	ElemType data;
	struct StackNode* next;
} StackNode, * LinkStack;//�������һ�㲻�ã���Ϊ�������ӻ�
//__declspec(selectany) LinkStack S=NULL;//����Ӧ��Ҫ���з��ظ����õ�ǰ׺��

__declspec(selectany) int length=0;

//��������
Status StackEmpty(LinkStack S);
Status InitStack(LinkStack* S);
Status Push(LinkStack* S, ElemType e);
Status Pop(StackNode* S, ElemType* e);
ElemType GetTop(StackNode* S);
Status clearLStack(StackNode** S);
Status destroyLStack(StackNode** S);
int LStackLength(StackNode* S);

__declspec(selectany) LinkStack OPND=NULL;
__declspec(selectany) LinkStack OPCH=NULL;

int logicMain();
char Precede(char t, char ch);
int Operate(int a, char c, int b);
int ln(char ch);
#endif
