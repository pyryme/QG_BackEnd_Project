#include"GenericQueue.h"

int main() {
    Queue* queue1 = initQueue();
    printf("�����int����Ϊ���ӣ����ú���������Ӻͳ���\n");
    // ���
    int a = 11, b = 22, c = 33;
    enQueue(queue1, &a);
    enQueue(queue1, &b);
    enQueue(queue1, &c);
    // ����
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    // ���ٶ���
    destroyQueue(queue1);



    Queue* queue2 = initQueue();
    printf("�����char����Ϊ���ӣ����ú���������Ӻͳ���\n");
    // ���
    char A = 'a', B = 'b', C = 'c';
    enQueue(queue2, &A);
    enQueue(queue2, &B);
    enQueue(queue2, &C);
    // ����
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    // ���ٶ���
    destroyQueue(queue2);


    
    return 0;
}
