#include"GenericQueue.h"

int main() {
    Queue* queue1 = initQueue();
    printf("这个是int类型为例子，套用函数进行入队和出队\n");
    // 入队
    int a = 11, b = 22, c = 33;
    enQueue(queue1, &a);
    enQueue(queue1, &b);
    enQueue(queue1, &c);
    // 出队
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    printf("Dequeued: %d\n", *(int*)deQueue(queue1));
    // 销毁队列
    destroyQueue(queue1);



    Queue* queue2 = initQueue();
    printf("这个是char类型为例子，套用函数进行入队和出队\n");
    // 入队
    char A = 'a', B = 'b', C = 'c';
    enQueue(queue2, &A);
    enQueue(queue2, &B);
    enQueue(queue2, &C);
    // 出队
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    printf("Dequeued: %c\n", *(char*)deQueue(queue2));
    // 销毁队列
    destroyQueue(queue2);


    
    return 0;
}
