#include"Tree.h"

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

   

    printf("这里测试查找功能，以70为例: ");
    if (search(root, 70) != NULL) {
        printf("找到了\n");
    }
    else {
        printf("找不到这个元素\n");
    }

    printf("删除40\n");
    root = deleteNode(root, 40);
    printf("删除操作后的树用中序遍历的结果: ");
    inorderTraversal(root);
    printf("\n");


    printf("先序遍历（递归方法）的结果: ");
    preorderTraversal(root);
    printf("\n");

    printf("中序遍历（递归方法）的结果: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("后续遍历（递归方法）的结果: ");
    postorderTraversal(root);
    printf("\n------------------------------------------");


    printf("先序遍历（非递归方法）的结果: ");
    iterativePreorder(root);
    printf("\n");


    printf("中序遍历（非递归方法）的结果: ");
    iterativeInorder(root);
    printf("\n");


    printf("后续遍历（非递归方法）的结果: ");
    iterativePostorder(root);
    printf("\n");



    printf("层序遍历的结果: ");
    levelOrderTraversal(root);
    printf("\n");


    return 0;
}
