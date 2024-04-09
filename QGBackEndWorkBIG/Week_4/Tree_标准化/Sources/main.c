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

   

    printf("������Բ��ҹ��ܣ���70Ϊ��: ");
    if (search(root, 70) != NULL) {
        printf("�ҵ���\n");
    }
    else {
        printf("�Ҳ������Ԫ��\n");
    }

    printf("ɾ��40\n");
    root = deleteNode(root, 40);
    printf("ɾ���������������������Ľ��: ");
    inorderTraversal(root);
    printf("\n");


    printf("����������ݹ鷽�����Ľ��: ");
    preorderTraversal(root);
    printf("\n");

    printf("����������ݹ鷽�����Ľ��: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("�����������ݹ鷽�����Ľ��: ");
    postorderTraversal(root);
    printf("\n------------------------------------------");


    printf("����������ǵݹ鷽�����Ľ��: ");
    iterativePreorder(root);
    printf("\n");


    printf("����������ǵݹ鷽�����Ľ��: ");
    iterativeInorder(root);
    printf("\n");


    printf("�����������ǵݹ鷽�����Ľ��: ");
    iterativePostorder(root);
    printf("\n");



    printf("��������Ľ��: ");
    levelOrderTraversal(root);
    printf("\n");


    return 0;
}
