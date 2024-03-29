#include"Declaration.h"


struct Node2* createNode2(int data) {
    struct Node2* newNode = (struct Node2*)malloc(sizeof(struct Node2));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prior = NULL;
    return newNode;
}

// �������в���һ���½ڵ�
void insertNode2(int pnewData, int num) {//β�巨
    struct Node2* newNode = createNode2(pnewData);
    struct Node2* pt = head2;


    if (head2 == NULL) {
        head2 = newNode;
        tail2 = newNode;
    }
    else {
        if (num == 1) { // ��ͷ������
            newNode->next = head2;
            newNode->prior = NULL;
            head2 = newNode;
        }
        else {
            struct Node* temp = NULL;
            for (int i = 1; i < num - 1 && pt != NULL; i++) {
                pt = pt->next;
            }
            if (pt == NULL) { // ��� num ���������ȣ�ֱ�ӽ��½ڵ���뵽β��
                tail2->next = newNode;
                tail2 = newNode;
            }
            else {
                newNode->next = pt->next;
                newNode->prior = pt;
                pt->next = newNode;
            }
        }
    }
}


// ��ʾ�����е�Ԫ��
void showList2(struct Node2* phead) {//phead��ʾ����head
    if (phead == NULL) {
        printf("��ǰ��������Ϊ0");
    }
    else {
        struct Node2* pt = phead;
        printf("��������Ϊ: ");
        while (pt != NULL) {
            printf("%d ", pt->data);
            pt = pt->next;
        }
        printf("\n");
    }
}


// ��ʾ����ĳ���, �����˫����ͨ��
void showLength2(struct Node2* phead) {//phead��ʾ����head
    int length2 = 0;
    if (phead == NULL) {
        printf("��ǰ��������Ϊ0");
    }
    else {
        struct Node2* pt = phead;
        printf("������Ϊ: ");
        while (pt != NULL) {
            pt = pt->next;
            length2++;
        }
        printf("%d\n", length2);
    }
}

//ɾ�����,�����ȶ�λ ��ɾ��
void deleteNode2(int num) {
    struct Node2* pt = head2;
    if (head2 == NULL) {
        printf("������Ϊ0��ɾ������");
        return;
    }
    else if (num == 1 && head2->next==NULL) {
        free(pt);
        head2 = NULL;
    }
    else {
        struct Node2* temp1, * temp2 = NULL;
        for (int i = 1; i < num - 1; i++)
        {
            pt = pt->next;
        }
        if (num == 1) {
            temp1 = pt;
            pt = pt->next;
            head2 = pt;
            free(temp1);
        }
        else {
            temp1 = pt;
            temp2 = pt->next;
            pt = pt->next->next;
            temp1->next = pt;
            pt->prior = temp1;
            free(temp2);
        }
    }

}


//���Ľ�����Ϣ���ȶ�λ �����(���Ҳ�ǲ��ģ�ֻ����head���ǲ���������д��һ��)
void change2(int data, int num) {//������bug�������⣬����βָ��û�и�����ȥ
    struct Node2* pt = head2;

    if (head2 == NULL) {
        printf("����ĳ���Ϊ0���Ĳ���");
    }
    else {
        if (num == 1) {
            head2->data = data;
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
void destroy2(struct Node2* phead) {
    struct Node2* pt = phead;
    struct Node2* temp = pt;
    while (pt != NULL) {
        temp = pt->next;
        free(pt);
        pt = temp;
    }
    printf("�����������");
    head2 = NULL;//�״�����Ҫ�Ѳ�����Ϊphead,��ֹȫ�ֱ����;ֲ���������
    tail2 = NULL;
}




