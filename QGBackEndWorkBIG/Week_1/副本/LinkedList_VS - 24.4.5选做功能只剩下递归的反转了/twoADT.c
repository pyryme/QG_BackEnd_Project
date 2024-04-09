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
void insertNode2() {//β�巨
   
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
int showLength2(struct Node2* phead) {//phead��ʾ����head
    int length2 = 0;
    if (phead == NULL) {
        printf("��ǰ��������Ϊ0\n");
        return;
    }
    else {
        struct Node2* pt = phead;
        while (pt != NULL) {
            pt = pt->next;
            length2++;
        }
        return length2;
    }
}

//ɾ�����,�����ȶ�λ ��ɾ��
void deleteNode2(int num) {
    if (head2 == NULL) {
        printf("������Ϊ0��ɾ������\n");
        return;
    }

    struct Node2* pt = head2;
    struct Node2* temp = NULL;

    if (num == 1) {
        head2 = head2->next;
        if (head2 != NULL) {
            head2->prior = NULL;
        }
        free(pt);
        return;
    }

    for (int i = 1; i < num && pt != NULL; i++) {
        pt = pt->next;
    }

    if (pt == NULL) {
        printf("λ�� %d ���������ȣ��޷�ɾ��\n", num);
        return;
    } 
    if (pt->next != NULL) {
        pt->next->prior = pt->prior;
        free(pt);
    } 
    else {//����������ڸո�pt(ָ��ɾ����Ԫ��)�պ������һ����ʱ��Ķ����
        pt->prior->next = NULL;
        free(pt);
    }
    }
    

  




//���Ľ�����Ϣ���ȶ�λ �����(���Ҳ�ǲ��ģ�ֻ����head���ǲ���������д��һ��)
void change2() {//������bug�������⣬����βָ��û�и�����ȥ
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
            if (pt->next == NULL) { // ��� num ���������ȣ�ֱ�ӽ��½ڵ���뵽β��
                printf("��ѡ��λ�ô���Ŀǰ����ĳ��ȣ��޷��޸�\n");
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

// �ж������Ƿ��л�
void hasCycle2(struct Node2* phead) {
    if (phead == NULL)
    {
        printf("����Ϊ0��û��\n");
        return;
    }
    if (showLength2(phead) == 1)
    {
        printf("����Ϊ1���ɲ��˻�\n");
        return;
    }


    struct Node2* slow = phead;
    struct Node2* fast = phead->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            printf("����ɻ�");
            return;
        }


        slow = slow->next;
        fast = fast->next->next;
    }
    printf("�����ɻ�");
    return;

}


// ��ת˫������,����Ͳ��㷵��ֵ�ˣ�����һ��
struct Node2* ReverseList2(struct Node2* phead) {

    if (phead == NULL)
    {
        printf("����Ϊ0����ת����\n");
        return NULL;
    }
    if (showLength2(phead) == 1)
    {
        printf("����Ϊ1����ת����\n");
        return NULL;
    }

    struct Node2* prev = NULL;
    struct Node2* curr = phead;
    struct Node2* nextTemp;

    while (curr != NULL) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    printf("��ת���");
    head2 = prev;
    return;
}

