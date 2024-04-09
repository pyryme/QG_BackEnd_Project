#include"Tree.h"



// 创建新节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// 查找节点
struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// 删除节点
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // 节点包含一个或零个子节点的情况
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 节点包含两个子节点的情况
        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// 中序遍历BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


// 前序遍历BST
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 后序遍历BST
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}



////一下是三序遍历的非递归算法，递归变非递归就是用栈来实现
// 定义栈结构
struct Stack {
    int top;
    struct TreeNode* items[MAX_STACK_SIZE];
};

// 创建栈
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

// 检查栈是否为空,//这里改了一下，可能会发生错误，0，1搞反了，之后出错可以看看这里
int isEmpty(struct Stack* stack) {
    if (stack->top == -1)
    {
        return 1;//空了就放回1
    }
    else {
        return 0;
    }
   
}

// 将元素压入栈
void push(struct Stack* stack, struct TreeNode* node) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = node;
}

// 弹出栈顶元素
struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// 前序遍历的非递归实现
void iterativePreorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(stack);
        printf("%d ", node->data);

        if (node->right != NULL) push(stack, node->right);
        if (node->left != NULL) push(stack, node->left);
    }

    free(stack);
}

// 中序遍历的非递归实现
void iterativeInorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }

    free(stack);
}

// 后序遍历的非递归实现
void iterativePostorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, root);

    while (!isEmpty(stack1)) {
        struct TreeNode* node = pop(stack1);
        push(stack2, node);

        if (node->left != NULL) push(stack1, node->left);
        if (node->right != NULL) push(stack1, node->right);
    }

    while (!isEmpty(stack2)) {
        printf("%d ", pop(stack2)->data);
    }

    free(stack1);
    free(stack2);
}
///////////////////////////////////////////


// 定义队列结构
struct Queue {
    int front, rear, size;
    struct TreeNode* items[MAX_QUEUE_SIZE];
};

// 创建队列
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// 检查队列是否为空
int isQEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// 检查队列是否已满
int isFull(struct Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

// 入队操作
void enqueue(struct Queue* queue, struct TreeNode* node) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        exit(1);
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->items[queue->rear] = node;
    queue->size++;
    if (queue->front == -1) {
        queue->front = queue->rear;
    }
}

// 出队操作
struct TreeNode* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    struct TreeNode* node = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return node;
}

// 层序遍历的非递归实现
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isQEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);/////////////////////////////////////////////这里有点问题，不知道为什么队列空了还会执行这里

        if (current->left != NULL) enqueue(queue, current->left);
        if (current->right != NULL) enqueue(queue, current->right);
        free(current);
    }

    free(queue);

}
