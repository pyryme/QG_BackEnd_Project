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
void insertNode2() {//尾插法
   
    int num = 0;
    int pnewData = 0;
    char comma;

    while (1) {//这里是新加的错误反馈；
        printf("请输入新增结点的内容 和 放置的位置（格式为 数字,数字）\n(如果位置大于长度则默认放到最后)：");

        // 尝试读取第一个整数
        if (scanf("%d", &pnewData) != 1) {
            printf("请输入有效的数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }

        // 尝试读取逗号
        if (scanf("%c", &comma) != 1 || comma != ',') {
            printf("输入格式不正确，应该是数字,数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }

        // 尝试读取第二个整数
        if (scanf("%d", &num) != 1) {
            printf("请输入有效的数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }

        // 输入格式正确，输出并退出循环
        printf("您输入的是：新数据：%d，位置：%d\n", pnewData, num);
        break;
    }



    // 清空输入缓冲区
    while (getchar() != '\n');
    
    
    
    
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
int showLength2(struct Node2* phead) {//phead表示参数head
    int length2 = 0;
    if (phead == NULL) {
        printf("当前的链表长度为0\n");
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

//删除结点,就是先定位 后删除
void deleteNode2(int num) {
    if (head2 == NULL) {
        printf("链表长度为0，删除不了\n");
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
        printf("位置 %d 超出链表长度，无法删除\n", num);
        return;
    } 
    if (pt->next != NULL) {
        pt->next->prior = pt->prior;
        free(pt);
    } 
    else {//这个就是用于刚刚pt(指向删除的元素)刚好是最后一个的时候的额操作
        pt->prior->next = NULL;
        free(pt);
    }
    }
    

  




//更改结点的信息，先定位 后更改(这个也是差不多的，只不过head不是参数，所以写多一遍)
void change2() {//这里有bug，有问题，就是尾指针没有跟随上去
    int data = 0;
    int num = 0;
    char comma;
    while (1) {//这里是新加的错误反馈；
        printf("请输入改变结点的内容 和 放置的位置（格式为 数字,数字）\n：");

        // 尝试读取第一个整数
        if (scanf("%d", &data) != 1) {
            printf("请输入有效的数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }

        // 尝试读取逗号
        if (scanf("%c", &comma) != 1 || comma != ',') {
            printf("输入格式不正确，应该是数字,数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }

        // 尝试读取第二个整数
        if (scanf("%d", &num) != 1) {
            printf("请输入有效的数字。\n");
            // 清空输入缓冲区
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        // 输入格式正确，输出并退出循环
        printf("您输入的是：新数据：%d，位置：%d\n", data, num);
        break;
    }
    
    
    

    ////以上是新加的错误反馈
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
            if (pt->next == NULL) { // 如果 num 大于链表长度，直接将新节点插入到尾部
                printf("你选的位置大于目前链表的长度，无法修改\n");
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

// 判断链表是否有环
void hasCycle2(struct Node2* phead) {
    if (phead == NULL)
    {
        printf("长度为0，没环\n");
        return;
    }
    if (showLength2(phead) == 1)
    {
        printf("长度为1，成不了环\n");
        return;
    }


    struct Node2* slow = phead;
    struct Node2* fast = phead->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            printf("链表成环");
            return;
        }


        slow = slow->next;
        fast = fast->next->next;
    }
    printf("链表不成环");
    return;

}


// 反转双链表函数,这个就不搞返回值了，方便一点
struct Node2* ReverseList2(struct Node2* phead) {

    if (phead == NULL)
    {
        printf("长度为0，反转不了\n");
        return NULL;
    }
    if (showLength2(phead) == 1)
    {
        printf("长度为1，反转不了\n");
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
    printf("反转完成");
    head2 = prev;
    return;
}

