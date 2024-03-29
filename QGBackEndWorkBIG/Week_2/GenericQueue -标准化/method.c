#include"GenericQueue.h"



// ��ʼ������
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

// ���
void enQueue(Queue *queue, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ�����ʧ��.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) { // ����Ϊ��ʱ����ͷ�Ͷ�β��ָ���½ڵ�
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// ����
void *deQueue(Queue *queue) {
    if (queue->front == NULL) {
        printf("�����ǿյ�.\n");
        return NULL;
    }
    Node *temp = queue->front;
    void *data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) { // �����ͷΪ�գ���βҲӦΪ��
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// ���ٶ���
void destroyQueue(Queue *queue) {
    while (queue->front != NULL) {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

//����ʽ���еĶ�ͷԪ��
Status GetHead(Queue Q, void* *e) {
    if (Q.front == Q.rear)
        return ERROR;
    *e = Q.front->next->data;
    return OK;
}

