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
void insertNode() {//β�巨
    int num = 0;
    int pnewData = 0;
    char comma;

    while (1) {//�������¼ӵĴ�������
        printf("������������������ �� ���õ�λ�ã���ʽΪ ����,���֣�\n(���λ�ô��ڳ�����Ĭ�Ϸŵ����)��");

        // ���Զ�ȡ��һ������
        if (scanf("%d", &pnewData) != 1) {
            printf("��������Ч�����֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }

        // ���Զ�ȡ����
        if (scanf("%c", &comma) != 1 || comma != ',') {
            printf("�����ʽ����ȷ��Ӧ��������,���֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }

        // ���Զ�ȡ�ڶ�������
        if (scanf("%d", &num) != 1) {
            printf("��������Ч�����֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }

        // �����ʽ��ȷ��������˳�ѭ��
        printf("��������ǣ������ݣ�%d��λ�ã�%d\n", pnewData, num);
        break;
    }



    // ������뻺����
    while (getchar() != '\n');


    
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
int showLength(struct Node* phead) {//phead��ʾ����head
    int length = 0;
    if (phead == NULL) {
        printf("��ǰ��������Ϊ0\n");
        return;
    }
    else {
        struct Node* pt = phead;
        while (pt != NULL) {
            pt = pt->next;
            length++;
            
        }
        return length;
    }
}
//ɾ�����,�����ȶ�λ ��ɾ��
//����д�ĺܸ��ӣ���ʱ��������Ż�
void deleteNode(int num) {
    if (head == NULL) {
        printf("������Ϊ0��ɾ������\n");
        return;
    }

    struct Node* pt = head;
    struct Node* temp = NULL;

    if (num == 1) {
        head = head->next;
        free(pt);
        return;
    }

    for (int i = 1; i < num - 1 && pt->next != NULL; i++) {
        pt = pt->next;
    }

    if (pt->next == NULL) {
        printf("λ�� %d ���������ȣ��޷�ɾ��\n", num);
        return;
    }

    temp = pt->next;
    pt->next = pt->next->next;
    free(temp);
}


//���Ľ�����Ϣ���ȶ�λ �����
void change() {//������bug�������⣬����βָ��û�и�����ȥ
    int data = 0;
    int num = 0;
    char comma;
    while (1) {//�������¼ӵĴ�������
        printf("������ı�������� �� ���õ�λ�ã���ʽΪ ����,���֣�\n��");

        // ���Զ�ȡ��һ������
        if (scanf("%d", &data) != 1) {
            printf("��������Ч�����֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }

        // ���Զ�ȡ����
        if (scanf("%c", &comma) != 1 || comma != ',') {
            printf("�����ʽ����ȷ��Ӧ��������,���֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }

        // ���Զ�ȡ�ڶ�������
        if (scanf("%d", &num) != 1) {
            printf("��������Ч�����֡�\n");
            // ������뻺����
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        // �����ʽ��ȷ��������˳�ѭ��
        printf("��������ǣ������ݣ�%d��λ�ã�%d\n", data, num);
        break;
    }
    



    ////�������¼ӵĴ�����
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
            if (pt->next == NULL) { // ��� num ���������ȣ���ʾ���Ȳ����ϣ�����ִ��break
                printf("��ѡ��λ�ô���Ŀǰ����ĳ��ȣ��޷��޸�\n");
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



//���������ż������
//���ɣ�ͨ����ͼ����֪�����ۣ�
// ����ż
/*ż������(ż)��(ż - 1)
�� �� �� + 3
�������߼ʴ���Ϳ�����
��β����ͷ
�����������һ��������Ϳ�����*/
void OddEvenChange(struct Node ** head){
    
    //////////�����ж� 0/1��������
    if (*head==NULL)
    {
        printf("����Ϊ0���Ĳ���\n");
        return;
    }
    if (showLength(*head) == 1)
    {
        printf("����Ϊ1���Ĳ���\n");
        return;
    }
    struct Node* odd = *head;
    struct Node* even = (*head)->next;
    struct Node* pt1 = odd->next->next;
    struct Node* pt2 =NULL;
    if (pt1 != NULL) {
        pt2 = pt1->next;
    }
    
    

    if (showLength(*head) % 2 == 0) {//-------1-------ż����
        *head = (*head)->next;
        while (pt2 != NULL) {
           
            even->next = odd;
            even = pt2;
            odd->next = even;//����pt2
            odd = pt1; 

            
            pt1 = odd->next->next;
            if (pt1 == NULL) {
                break;
            }
            pt2 = pt1->next;
        }
        even->next = odd;
        odd->next = NULL;
        
     }
    else {//----------1---------������
        *head = (*head)->next;
        while (pt2 != NULL) {

            even->next = odd;
            even = pt2;
            odd->next = even;
            odd = pt1;

            pt1 = odd->next->next;
            pt2 = pt1->next;
        }
        even->next = odd;
        odd->next = pt1;
    }

    printf("��ż�������");
}



//�ҵ�����������е�
void ShowMiddle(struct Node* phead) {
    if (phead == NULL)
    {
        printf("����Ϊ0��û�е�\n");
        return;
    }
    if (showLength(phead) == 1)
    {
        printf("����Ϊ1���е�Ϊ��һ��Ԫ��\n");
        return;
    }

    if (showLength(phead) % 2 == 0) {
        printf("ż������㣬�м�Ԫ����2��������Ϊ��");
        struct Node* pt = phead;
        for (int i = 0;i<(showLength(phead)/2-1);i++) {
            pt = pt->next;
        }
        printf("%d,%d",pt->data,pt->next->data);
    }
    else {
        printf("����������㣬�м�Ԫ����1��������Ϊ��");
        struct Node* pt = phead;
        for (int i = 0; i < (showLength(phead) / 2 - 1); i++) {
            pt = pt->next;
        }
        printf("%d,", pt->next->data);
    }
}


// �ж������Ƿ��л�
void hasCycle1(struct Node* phead) {
    if (phead == NULL)
    {
        printf("����Ϊ0��û��\n");
        return;
    }
    if (showLength(phead) == 1)
    {
        printf("����Ϊ1���ɲ��˻�\n");
        return;
    }


    struct Node* slow = phead;
    struct Node* fast = phead->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            printf("����ɻ�");
            return ;
        }
           

        slow = slow->next;
        fast = fast->next->next;
    }
    printf("�����ɻ�");
    return ;
    
}


// ��ת��������,����Ͳ��㷵��ֵ�ˣ�����һ��
struct Node* ReverseList1(struct Node* phead) {

    if (phead == NULL)
    {
        printf("����Ϊ0����ת����\n");
        return NULL;
    }
    if (showLength(phead) == 1)
    {
        printf("����Ϊ1����ת����\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = phead;
    struct Node* nextTemp;

    while (curr != NULL) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    printf("��ת���");
    head = prev;
    return ;
}