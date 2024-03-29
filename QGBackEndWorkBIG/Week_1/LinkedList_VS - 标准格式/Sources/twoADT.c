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

// 向链表中插入一个新节点
void insertNode2(int pnewData, int num) {//尾插法
    struct Node2* newNode = createNode2(pnewData);
    struct Node2* pt = head2;


    if (head2 == NULL) {
        head2 = newNode;
        tail2 = newNode;
    }
    else {
        if (num == 1) { // 在头部插入
            newNode->next = head2;
            newNode->prior = NULL;
            head2 = newNode;
        }
        else {
            struct Node* temp = NULL;
            for (int i = 1; i < num - 1 && pt != NULL; i++) {
                pt = pt->next;
            }
            if (pt == NULL) { // 如果 num 大于链表长度，直接将新节点插入到尾部
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


// 显示链表中的元素
void showList2(struct Node2* phead) {//phead表示参数head
    if (phead == NULL) {
        printf("当前的链表长度为0");
    }
    else {
        struct Node2* pt = phead;
        printf("链表内容为: ");
        while (pt != NULL) {
            printf("%d ", pt->data);
            pt = pt->next;
        }
        printf("\n");
    }
}


// 显示链表的长度, 这个单双链表都通用
void showLength2(struct Node2* phead) {//phead表示参数head
    int length2 = 0;
    if (phead == NULL) {
        printf("当前的链表长度为0");
    }
    else {
        struct Node2* pt = phead;
        printf("链表长度为: ");
        while (pt != NULL) {
            pt = pt->next;
            length2++;
        }
        printf("%d\n", length2);
    }
}

//删除结点,就是先定位 后删除
void deleteNode2(int num) {
    struct Node2* pt = head2;
    if (head2 == NULL) {
        printf("链表长度为0，删除不了");
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


//更改结点的信息，先定位 后更改(这个也是差不多的，只不过head不是参数，所以写多一遍)
void change2(int data, int num) {//这里有bug，有问题，就是尾指针没有跟随上去
    struct Node2* pt = head2;

    if (head2 == NULL) {
        printf("链表的长度为0，改不了");
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
            if (pt == NULL) { // 如果 num 大于链表长度，直接将新节点插入到尾部
                tail->data = data;
            }
            else {
                pt->next->data = data;//因为结构用了尾插的函数，所以这里要加上一个next

            }
        }
    }
}


//销毁链表
void destroy2(struct Node2* phead) {
    struct Node2* pt = phead;
    struct Node2* temp = pt;
    while (pt != NULL) {
        temp = pt->next;
        free(pt);
        pt = temp;
    }
    printf("链表销毁完成");
    head2 = NULL;//易错，这里要把参数改为phead,防止全局变量和局部变量混淆
    tail2 = NULL;
}




