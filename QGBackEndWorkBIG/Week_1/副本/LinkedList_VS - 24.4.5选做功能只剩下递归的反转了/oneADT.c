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
void insertNode() {//尾插法
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
int showLength(struct Node* phead) {//phead表示参数head
    int length = 0;
    if (phead == NULL) {
        printf("当前的链表长度为0\n");
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
//删除结点,就是先定位 后删除
//这里写的很复杂，有时间可以再优化
void deleteNode(int num) {
    if (head == NULL) {
        printf("链表长度为0，删除不了\n");
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
        printf("位置 %d 超出链表长度，无法删除\n", num);
        return;
    }

    temp = pt->next;
    pt->next = pt->next->next;
    free(temp);
}


//更改结点的信息，先定位 后更改
void change() {//这里有bug，有问题，就是尾指针没有跟随上去
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
            if (pt->next == NULL) { // 如果 num 大于链表长度，表示长度不符合，继续执行break
                printf("你选的位置大于目前链表的长度，无法修改\n");
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



//单链表的奇偶互换，
//规律：通过画图可以知道结论，
// 分奇偶
/*偶数个：(偶)连(偶 - 1)
奇 连 奇 + 3
后面做边际处理就可以了
结尾，开头
奇数个：最后一个不处理就可以了*/
void OddEvenChange(struct Node ** head){
    
    //////////错误判断 0/1都不进行
    if (*head==NULL)
    {
        printf("长度为0，改不了\n");
        return;
    }
    if (showLength(*head) == 1)
    {
        printf("长度为1，改不了\n");
        return;
    }
    struct Node* odd = *head;
    struct Node* even = (*head)->next;
    struct Node* pt1 = odd->next->next;
    struct Node* pt2 =NULL;
    if (pt1 != NULL) {
        pt2 = pt1->next;
    }
    
    

    if (showLength(*head) % 2 == 0) {//-------1-------偶数个
        *head = (*head)->next;
        while (pt2 != NULL) {
           
            even->next = odd;
            even = pt2;
            odd->next = even;//就是pt2
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
    else {//----------1---------奇数个
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

    printf("奇偶更改完成");
}



//找到链表单链表的中点
void ShowMiddle(struct Node* phead) {
    if (phead == NULL)
    {
        printf("长度为0，没中点\n");
        return;
    }
    if (showLength(phead) == 1)
    {
        printf("长度为1，中点为第一个元素\n");
        return;
    }

    if (showLength(phead) % 2 == 0) {
        printf("偶数个结点，中间元素有2个，内容为：");
        struct Node* pt = phead;
        for (int i = 0;i<(showLength(phead)/2-1);i++) {
            pt = pt->next;
        }
        printf("%d,%d",pt->data,pt->next->data);
    }
    else {
        printf("奇数数个结点，中间元素有1个，内容为：");
        struct Node* pt = phead;
        for (int i = 0; i < (showLength(phead) / 2 - 1); i++) {
            pt = pt->next;
        }
        printf("%d,", pt->next->data);
    }
}


// 判断链表是否有环
void hasCycle1(struct Node* phead) {
    if (phead == NULL)
    {
        printf("长度为0，没环\n");
        return;
    }
    if (showLength(phead) == 1)
    {
        printf("长度为1，成不了环\n");
        return;
    }


    struct Node* slow = phead;
    struct Node* fast = phead->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            printf("链表成环");
            return ;
        }
           

        slow = slow->next;
        fast = fast->next->next;
    }
    printf("链表不成环");
    return ;
    
}


// 反转单链表函数,这个就不搞返回值了，方便一点
struct Node* ReverseList1(struct Node* phead) {

    if (phead == NULL)
    {
        printf("长度为0，反转不了\n");
        return NULL;
    }
    if (showLength(phead) == 1)
    {
        printf("长度为1，反转不了\n");
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
    printf("反转完成");
    head = prev;
    return ;
}