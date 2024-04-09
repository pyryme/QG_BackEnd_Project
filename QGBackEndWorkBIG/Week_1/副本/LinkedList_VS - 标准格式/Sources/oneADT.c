#include"Declaration.h"

// 创建一个新的节点
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
// 向链表中插入一个新节点
void insertNode( int pnewData,int num) {//尾插法
    struct Node* newNode = createNode(pnewData);
    struct Node* pt = head;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {//这里还没有搞错误反馈
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


// 向链表中插入一个新节点
void insertNode(int pnewData, int num) {//尾插法
    struct Node* newNode = createNode(pnewData);
    struct Node* pt = head;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        if (num == 1) { // 在头部插入
            newNode->next = head;
            head = newNode;
        }
        else {
            struct Node* temp = NULL;
            for (int i = 1; i < num - 1 && pt != NULL; i++) {
                pt = pt->next;
            }
            if (pt == NULL) { // 如果 num 大于链表长度，直接将新节点插入到尾部
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


// 显示链表中的元素
void showList(struct Node* phead) {//phead表示参数head
    if (phead==NULL) {
        printf("当前的链表长度为0");
    }
    else {
        struct Node* pt = phead;
        printf("链表内容为: ");
        while (pt != NULL) {
            printf("%d ", pt->data);
            pt = pt->next;
        }
        printf("\n");
    }
}

// 显示链表的长度,这个单双链表都通用
void showLength(struct Node* phead) {//phead表示参数head
    int length = 0;
    if (phead == NULL) {
        printf("当前的链表长度为0");
    }
    else {
        struct Node* pt = phead;
        printf("链表长度为: ");
        while (pt != NULL) {
            pt = pt->next;
            length++;
        }
        printf("%d\n",length);
    }
}
//删除结点,就是先定位 后删除
//这里写的很复杂，有时间可以再优化
void deleteNode(int num) {
    struct Node* pt = head;
    if (head == NULL) {
        printf("链表长度为0，删除不了");
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

//更改结点的信息，先定位 后更改
void change(int data, int num) {//这里有bug，有问题，就是尾指针没有跟随上去
    struct Node* pt = head;

    if (head == NULL) {
        printf("链表的长度为0，改不了");
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
void destroy(struct Node * phead) {
    struct Node* pt = phead;
    struct Node* temp = pt;
    while (pt != NULL) {
        temp = pt->next;
        free(pt);
        pt = temp;
    }
    printf("链表销毁完成");
    head = NULL;//易错，这里要把参数改为phead,防止全局变量和局部变量混淆
    tail = NULL;
}

