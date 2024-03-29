#include "Calculators.h"
//当要修改链栈的元素的时候，就要用指针的指针 ，要查看不修改的时候才用指针
//调用一个结构体类型的指针的时候可以用StackNode* p = *S;不用申请空间。入栈的时候要录入数据才要用malloc来申请空间
Status StackEmpty(LinkStack S) {//(注意，这里的LinkStack就是一个指针类型的)
	if (S == NULL)return TRUE;
	else return FALSE;
}

Status InitStack(LinkStack *S) {//易错：理解，这里不用申请空间，只用在头文件中声明一个S就可以了
	S = NULL;
	return OK;
}

Status Push(LinkStack* S, ElemType e) {//调用函数的时候参数是&S
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL) {
		printf("p空间申请失败");
		return ERROR; 
	}
	/*if (S == NULL || *S == NULL)//这个用于第一次的录入#
	{
		*S = p;
	}
	else {*/
		p->data = e;
		p->next = *S;
		*S = p;
	//}
	
	return OK;
}


Status Pop(LinkStack* S,ElemType *e) {//链栈的出栈
	if (S == NULL) {
		printf("空栈了，出不了");
		return ERROR;
	}
	StackNode* p = *S;// 用于释放内存的临时指针
	*e = (*S)->data;//这里易错，*e = *S->data;这样不加上小括号是错的
	*S = (*S)->next;
	free(p);
	return OK;
}



ElemType GetTop(StackNode *S) {//取栈顶元素
	if (S != NULL)
		return S->data;
}



Status clearLStack(StackNode** S) {// 清空链栈
	if (*S == NULL) {
		printf("不存在这个栈");
		return ERROR;
	}

	StackNode* p, * temp;
	p = *S;

	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp); // 释放节点的内存
	}

	*S = NULL; // 将栈顶指针置为空

	return OK;
}


Status destroyLStack(StackNode** S) {// 销毁链栈
	if (clearLStack(S) == OK) {
		free(*S); // 释放栈顶指针的内存
		return OK;
	}
	return ERROR;
}


int LStackLength(StackNode* S) {// 获取链栈的长度
	int length = 0;
	StackNode* p = S;

	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}






