#include "Calculators.h"
//��Ҫ�޸���ջ��Ԫ�ص�ʱ�򣬾�Ҫ��ָ���ָ�� ��Ҫ�鿴���޸ĵ�ʱ�����ָ��
//����һ���ṹ�����͵�ָ���ʱ�������StackNode* p = *S;��������ռ䡣��ջ��ʱ��Ҫ¼�����ݲ�Ҫ��malloc������ռ�
Status StackEmpty(LinkStack S) {//(ע�⣬�����LinkStack����һ��ָ�����͵�)
	if (S == NULL)return TRUE;
	else return FALSE;
}

Status InitStack(LinkStack *S) {//�״���⣬���ﲻ������ռ䣬ֻ����ͷ�ļ�������һ��S�Ϳ�����
	S = NULL;
	return OK;
}

Status Push(LinkStack* S, ElemType e) {//���ú�����ʱ�������&S
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL) {
		printf("p�ռ�����ʧ��");
		return ERROR; 
	}
	/*if (S == NULL || *S == NULL)//������ڵ�һ�ε�¼��#
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


Status Pop(LinkStack* S,ElemType *e) {//��ջ�ĳ�ջ
	if (S == NULL) {
		printf("��ջ�ˣ�������");
		return ERROR;
	}
	StackNode* p = *S;// �����ͷ��ڴ����ʱָ��
	*e = (*S)->data;//�����״�*e = *S->data;����������С�����Ǵ��
	*S = (*S)->next;
	free(p);
	return OK;
}



ElemType GetTop(StackNode *S) {//ȡջ��Ԫ��
	if (S != NULL)
		return S->data;
}



Status clearLStack(StackNode** S) {// �����ջ
	if (*S == NULL) {
		printf("���������ջ");
		return ERROR;
	}

	StackNode* p, * temp;
	p = *S;

	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp); // �ͷŽڵ���ڴ�
	}

	*S = NULL; // ��ջ��ָ����Ϊ��

	return OK;
}


Status destroyLStack(StackNode** S) {// ������ջ
	if (clearLStack(S) == OK) {
		free(*S); // �ͷ�ջ��ָ����ڴ�
		return OK;
	}
	return ERROR;
}


int LStackLength(StackNode* S) {// ��ȡ��ջ�ĳ���
	int length = 0;
	StackNode* p = S;

	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}






