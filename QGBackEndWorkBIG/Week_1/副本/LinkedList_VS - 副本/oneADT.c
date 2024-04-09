#include"Declaration.h"

// ����һ���µĽڵ�
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
// �������в���һ���½ڵ�
void insertNode( int pnewData,int num) {//β�巨
    struct Node* newNode = createNode(pnewData);
    struct Node* pt = head;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {//���ﻹû�и������
        struct Node* temp = NULL;
        for (int i = 1; i < num-; i++)
        {
            pt = pt->next;
        }
        temp = pt;
        pt = pt->next;
        temp->next = newNode;
        newNode->next = pt;
    }
}*/


// �������в���һ���½ڵ�
void insertNode(int pnewData, int num) {//β�巨
    struct Node* newNode = createNode(pnewData);
    struct Node* pt = head;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        if (num == 1) { // ��ͷ������
            newNode->next = head;
            head = newNode;
        }
        else {
            struct Node* temp = NULL;
            for (int i = 1; i < num - 1 && pt != NULL; i++) {
                pt = pt->next;
            }
            if (pt == NULL) { // ��� num ���������ȣ�ֱ�ӽ��½ڵ���뵽β��
                tail->next = newNode;
                tail = newNode;
            }
            else {
                newNode->next = pt->next;
                pt->next = newNode;
            }
        }
    }
}


// ��ʾ�����е�Ԫ��
void showList(struct Node* phead) {//phead��ʾ����head
    if (phead==NULL) {
        printf("��ǰ��������Ϊ0");
    }
    else {
        struct Node* pt = phead;
        printf("��������Ϊ: ");
        while (pt != NULL) {
            printf("%d ", pt->data);
            pt = pt->next;
        }
        printf("\n");
    }
}

// ��ʾ����ĳ���,�����˫����ͨ��
void showLength(struct Node* phead) {//phead��ʾ����head
    int length = 0;
    if (phead == NULL) {
        printf("��ǰ��������Ϊ0");
    }
    else {
        struct Node* pt = phead;
        printf("������Ϊ: ");
        while (pt != NULL) {
            pt = pt->next;
            length++;
        }
        printf("%d\n",length);
    }
}
//ɾ�����,�����ȶ�λ ��ɾ��
//����д�ĺܸ��ӣ���ʱ��������Ż�
void deleteNode(int num) {
    struct Node* pt = head;
    if (head == NULL) {
        printf("������Ϊ0��ɾ������");
        return;
    }
    else if(num==1&&head-> next == NULL){
        free(pt);
        head = NULL;
    }
    else {
        struct Node* temp1, * temp2 = NULL;
        for (int i = 1; i < num - 1; i++)
        {
            pt = pt->next;
        }
        if (num == 1) {
            temp1 = pt;
            pt = pt->next;
            head = pt;
            free(temp1);
        }
        else {
            temp1 = pt;
            temp2 = pt->next;
            pt = pt->next->next;
            temp1->next = pt;
            free(temp2);
        }
    }

}

//���Ľ�����Ϣ���ȶ�λ �����
void change(int data, int num) {//������bug�������⣬����βָ��û�и�����ȥ
    struct Node* pt = head;

    if (head == NULL) {
        printf("����ĳ���Ϊ0���Ĳ���");
    }
    else {
        if (num == 1) { 
            head->data = data;
        }
        else {
            struct Node* temp = NULL;
            for (int i = 1; i < num - 1 && pt != NULL; i++) {
                pt = pt->next;
            }
            if (pt == NULL) { // ��� num ���������ȣ�ֱ�ӽ��½ڵ���뵽β��
                tail->data = data;
            }
            else {
                pt->next->data = data;//��Ϊ�ṹ����β��ĺ�������������Ҫ����һ��next
      
            }
        }
    }
}

//��������
void destroy(struct Node * phead) {
    struct Node* pt = phead;
    struct Node* temp = pt;
    while (pt != NULL) {
        temp = pt->next;
        free(pt);
        pt = temp;
    }
    printf("�����������");
    head = NULL;//�״�����Ҫ�Ѳ�����Ϊphead,��ֹȫ�ֱ����;ֲ���������
    tail = NULL;
}

