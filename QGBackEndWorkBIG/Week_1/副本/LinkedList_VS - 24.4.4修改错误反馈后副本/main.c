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
                //int num = 0;
                //int newData = 0;//这里可以根据不同类型的数据域改变不同类型的定义类型
                showLength(head);
                //printf("请输入在新增的结点的内容 和 放在第几个结点的位置上。输入格式如 2,2\n");
               // scanf("%d,%d", &newData, &num);//这里易错点，要有个逗号
                // 清空输入缓冲区
               // while (getchar() != '\n');
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
        case 3:
            printf("时间比较紧，还没开始做");
            break;


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
