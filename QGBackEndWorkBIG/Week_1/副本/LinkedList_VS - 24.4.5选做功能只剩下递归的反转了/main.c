#include"Declaration.h"
//问题：不知道为什么要加上这个清空缓存区，


int main()
{
    int option1 = 0;

    while (option1 != 4) {
       

        printf("\n**********************************************************************\n 1----单链表的ADT 2----双链表的ADT 3----其他选做功能 4----退出程序 \n ******************************************************************\n ");
        printf("这是1级菜单，请选择：");
        //scanf("%d", &option1);
        //这个防止一开始输入d但是误判的情况
        if (scanf("%d", &option1) != 1) {
            system("cls");
            // 如果未成功读取一个整数，清空输入缓冲区并提示用户重新输入
            printf("请输入一个有效的数字。\n");
            while (getchar() != '\n');
            continue; // 继续下一次循环
        }

        // 清空输入缓冲区
        while (getchar() != '\n');

        switch (option1)
        {
        case 1: {
            int option2 = 0;
            printf("\n**********************************************************************\n 1.查看链表  2.增加结点  3.删除结点  4.更改结点信息  5.销毁链表\n");
            printf("这是单链表的二级菜单，请选择功能\n");

            scanf("%d", &option2);
            // 清空输入缓冲区
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
                if (head == NULL) {
                    printf("链表长度为0\n");
                }
                else {
                    int length = showLength(head);
                    printf("链表长度为%d\n", length);
                }

                insertNode();
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("请输入你要删除的结点的位置");
                if (scanf("%d", &num) != 1) {
                    system("cls");
                    // 如果未成功读取一个整数，清空输入缓冲区并提示用户重新输入
                    printf("请输入一个有效的数字。\n");
                    while (getchar() != '\n');
                    continue; // 继续下一次循环
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
                printf("销毁链表完成\n");
                destroy(head);
                break;
            }
            default:
                system("cls");
                printf("请输入有效的符号或者数字,跳转到1级菜单\n");

            }
        }
              break;
        case 2: {
            int option3 = 0;
            printf("\n**********************************************************************\n 1.查看链表  2.增加结点  3.删除结点  4.更改结点信息  5.销毁链表\n");
            printf("这是双链表的二级菜单，请选择功能\n");
            scanf("%d", &option3);
            // 清空输入缓冲区
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
                printf("请输入你要删除的结点的位置");
                if (scanf("%d", &num) != 1) {
                    system("cls");
                    // 如果未成功读取一个整数，清空输入缓冲区并提示用户重新输入
                    printf("请输入一个有效的数字。\n");
                    while (getchar() != '\n');
                    continue; // 继续下一次循环
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
                printf("销毁链表完成\n");
                break;
            }
            default:
                system("cls");
                printf("请输入有效的数字和符号,跳转到1级菜单\n");
                break;
            }
        }
              break;
        case 3: {
            int option4 = 0;
            printf("\n**********************************************************************\n 1.单链表奇偶调换  2.找到单链表的中点 3.判断单双链表是否有环  4.反转单双链表函数  5.\n");
            printf("这是选做功能的二级菜单，请选择功能\n");

            scanf("%d", &option4);
            while (getchar() != '\n');

            switch (option4)
            {
            case 1: {
                system("cls");
                OddEvenChange(&head);
                break;
            }
            case 2: {
                system("cls");
                ShowMiddle(head);
                break;
            }
            case 3: {
                system("cls");
                printf("单链表：");
                hasCycle1(head);
                printf("\n双向链表:");
                hasCycle2(head2);
                break;
            }
            case 4: {
                system("cls");
                printf("单链表：");
                ReverseList1(head);
                printf("\n双向链表:");
                ReverseList2(head2);
                break;
            }
            case 5: {
                system("cls");
          
                break;
            }
            default:
                system("cls");
                printf("请输入有效的数字和符号,跳转到1级菜单\n");
                break;
            }
            break;
        }
          

        

       
        case 4:
                system("cls");
                printf("退出程序");
                break;
           
          default:
              system("cls");
              printf("请输入有效的符号或者数字");
            break;
        }

    }
    system("pause");
    return 0;
}
