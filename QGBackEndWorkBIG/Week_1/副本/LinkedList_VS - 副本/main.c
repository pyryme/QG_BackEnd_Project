#include"Declaration.h"
//���⣺��֪��ΪʲôҪ���������ջ�������


int main()
{
    int option1 = 0;

    while (option1 != 4) {
       

        printf("\n**********************************************************************\n 1----�������ADT 2----˫�����ADT 3----����ѡ������ 4----�˳����� \n ******************************************************************\n ");
        printf("����1���˵�����ѡ��");
        scanf("%d", &option1);
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
                int num = 0;
                int newData = 0;//������Ը��ݲ�ͬ���͵�������ı䲻ͬ���͵Ķ�������
                showLength(head);
                printf("�������������Ľ������� �� ���ڵڼ�������λ���ϡ������ʽ�� 2,2\n");
                scanf("%d,%d", &newData, &num);//�����״�㣬Ҫ�и�����
                // ������뻺����
                while (getchar() != '\n');
                insertNode(newData, num);
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("��������Ҫɾ���Ľ���λ��");
                scanf("%d", &num);
                while (getchar() != '\n');
                deleteNode(num);
                break;
            }
            case 4: {
                system("cls");
                int data = 0;
                int num = 0;
                printf("�������ڸ��ĵĽ������� �� �����ڵڼ�������λ���ϡ������ʽ�� 2,2\n");
                scanf("%d,%d", &data, &num);
                while (getchar() != '\n');
                change(data,num);
                break;
            }
            case 5: {
                system("cls");
                destroy(head);
            }

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
                int num = 0;
                int newData = 0;//������Ը��ݲ�ͬ���͵�������ı䲻ͬ���͵Ķ�������
                showLength2(head2);
                printf("�������������Ľ������� �� ���ڵڼ�������λ���ϡ������ʽ�� 2,2\n");
                scanf("%d,%d", &newData, &num);//�����״�㣬Ҫ�и�����
                // ������뻺����
                while (getchar() != '\n');
                insertNode2(newData, num);
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("��������Ҫɾ���Ľ���λ��");
                scanf("%d", &num);
                while (getchar() != '\n');
                deleteNode2(num);
                break;
            }
            case 4: {
                system("cls");
                int data = 0;
                int num = 0;
                printf("�������ڸ��ĵĽ������� �� �����ڵڼ�������λ���ϡ������ʽ�� 2,2\n");
                scanf("%d,%d", &data, &num);
                while (getchar() != '\n');
                change2(data, num);
                break;
            }
            case 5: {
                system("cls");
                destroy2(head2);
            }
            }
        }
            break;
        case 3:
            printf("ʱ��ȽϽ�����û��ʼ��");
            break;

        default:
            break;
        }

    }
    system("pause");
    return 0;
}
