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

//专属代码
#define MAXSIZE 100
typedef char ElemType;//#define ElemType char
typedef int Status;

typedef struct StackNode{
	ElemType data;
	struct StackNode* next;
} StackNode, * LinkStack;//后面这个一般不用，因为不够可视化
//__declspec(selectany) LinkStack S=NULL;//这里应该要进行防重复引用的前缀。

__declspec(selectany) int length=0;

//函数声明
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
