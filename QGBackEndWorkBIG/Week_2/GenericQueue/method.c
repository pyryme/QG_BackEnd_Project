#include"GenericQueue.h"



// 初始化队列
Queue *initQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 入队
void enQueue(Queue *queue, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存请求失败.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) { // 队列为空时，队头和队尾都指向新节点
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队
void *deQueue(Queue *queue) {
    if (queue->front == NULL) {
        printf("队列是空的.\n");
        return NULL;
    }
    Node *temp = queue->front;
    void *data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) { // 如果队头为空，队尾也应为空
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// 销毁队列
void destroyQueue(Queue *queue) {
    while (queue->front != NULL) {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

//求链式队列的队头元素
Status GetHead(Queue Q, void* *e) {
    if (Q.front == Q.rear)
        return ERROR;
    *e = Q.front->next->data;
    return OK;
}

