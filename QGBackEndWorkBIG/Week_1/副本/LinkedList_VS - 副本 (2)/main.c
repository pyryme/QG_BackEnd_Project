#include"Declaration.h"
//���⣺��֪��ΪʲôҪ���������ջ�������


int main()
{
    int option1 = 0;

    while (option1 != 4) {
       

        printf("\n**********************************************************************\n 1----�������ADT 2----˫�����ADT 3----����ѡ������ 4----�˳����� \n ******************************************************************\n ");
        printf("����1���˵�����ѡ��");
        //scanf("%d", &option1);
        //�����ֹһ��ʼ����d�������е����
        if (scanf("%d", &option1) != 1) {
            system("cls");
            // ���δ�ɹ���ȡһ��������������뻺��������ʾ�û���������
            printf("������һ����Ч�����֡�\n");
            while (getchar() != '\n');
            continue; // ������һ��ѭ��
        }

        // ������뻺����
        while (getchar() != '\n');

        switch (option1)
        {
        case 1: {
            int option2 = 0;
            printf("\n**********************************************************************\n 1.�鿴����  2.���ӽ��  3.ɾ�����  4.���Ľ����Ϣ  5.��������\n");
            printf("���ǵ�����Ķ����˵�����ѡ����\n");

            scanf("%d", &option2);
            // ������뻺����
            while (getchar() != '\n');

            switch (option2)
            {
            case 1:
            {
                system("cls");
                showList(head);
                break;
            }
            case 2:
            {
                system("cls");
                //int num = 0;
                //int newData = 0;//������Ը��ݲ�ͬ���͵�������ı䲻ͬ���͵Ķ�������
                showLength(head);
                //printf("�������������Ľ������� �� ���ڵڼ�������λ���ϡ������ʽ�� 2,2\n");
               // scanf("%d,%d", &newData, &num);//�����״�㣬Ҫ�и�����
                // ������뻺����
               // while (getchar() != '\n');
                insertNode();
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("��������Ҫɾ���Ľ���λ��");
                if (scanf("%d", &num) != 1) {
                    system("cls");
                    // ���δ�ɹ���ȡһ��������������뻺��������ʾ�û���������
                    printf("������һ����Ч�����֡�\n");
                    while (getchar() != '\n');
                    continue; // ������һ��ѭ��
                }
                while (getchar() != '\n');
                deleteNode(num);
                break;
            }
            case 4: {
                system("cls");
                change();
                break;
            }
            case 5: {
                system("cls");
                printf("�����������\n");
                destroy(head);
                break;
            }
            default:
                system("cls");
                printf("��������Ч�ķ��Ż�������,��ת��1���˵�\n");
            
            }
        }
              break;
        case 2: {
            int option3 = 0;
            printf("\n**********************************************************************\n 1.�鿴����  2.���ӽ��  3.ɾ�����  4.���Ľ����Ϣ  5.��������\n");
            printf("����˫����Ķ����˵�����ѡ����\n");
            scanf("%d", &option3);
            // ������뻺����
            while (getchar() != '\n');

            switch (option3)
            {
            case 1: {
                system("cls");
                showList2(head2);
                break;
            }
            case 2: {
                system("cls");
                showLength2(head2);
                insertNode2();
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("��������Ҫɾ���Ľ���λ��");
                if (scanf("%d", &num) != 1) {
                    system("cls");
                    // ���δ�ɹ���ȡһ��������������뻺��������ʾ�û���������
                    printf("������һ����Ч�����֡�\n");
                    while (getchar() != '\n');
                    continue; // ������һ��ѭ��
                }
                while (getchar() != '\n');
                deleteNode2(num);
                break;
            }
            case 4: {
                system("cls");
                change2();
                break;
            }
            case 5: {
                system("cls");
                destroy2(head2);
                printf("�����������\n");
                break;
            }
            default:
                system("cls");
                printf("��������Ч�����ֺͷ���,��ת��1���˵�\n");
                break;
            }
        }
            break;
        case 3:
            printf("ʱ��ȽϽ�����û��ʼ��");
            break;


        case 4:
                system("cls");
                printf("�˳�����");
                break;
           
          default:
              system("cls");
              printf("��������Ч�ķ��Ż�������");
            break;
        }

    }
    system("pause");
    return 0;
}
