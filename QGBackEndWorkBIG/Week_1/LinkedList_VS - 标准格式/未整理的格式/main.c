#include"Declaration.h"
//问题：不知道为什么要加上这个清空缓存区，


int main()
{
    int option1 = 0;

    while (option1 != 4) {
       

        printf("\n**********************************************************************\n 1----单链表的ADT 2----双链表的ADT 3----其他选做功能 4----退出程序 \n ******************************************************************\n ");
        printf("这是1级菜单，请选择：");
        scanf("%d", &option1);
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
                int num = 0;
                int newData = 0;//这里可以根据不同类型的数据域改变不同类型的定义类型
                showLength(head);
                printf("请输入在新增的结点的内容 和 放在第几个结点的位置上。输入格式如 2,2\n");
                scanf("%d,%d", &newData, &num);//这里易错点，要有个逗号
                // 清空输入缓冲区
                while (getchar() != '\n');
                insertNode(newData, num);
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("请输入你要删除的结点的位置");
                scanf("%d", &num);
                while (getchar() != '\n');
                deleteNode(num);
                break;
            }
            case 4: {
                system("cls");
                int data = 0;
                int num = 0;
                printf("请输入在更改的结点的内容 和 更改在第几个结点的位置上。输入格式如 2,2\n");
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
                int num = 0;
                int newData = 0;//这里可以根据不同类型的数据域改变不同类型的定义类型
                showLength2(head2);
                printf("请输入在新增的结点的内容 和 放在第几个结点的位置上。输入格式如 2,2\n");
                scanf("%d,%d", &newData, &num);//这里易错点，要有个逗号
                // 清空输入缓冲区
                while (getchar() != '\n');
                insertNode2(newData, num);
                break;
            }
            case 3: {
                system("cls");
                int num = 0;
                printf("请输入你要删除的结点的位置");
                scanf("%d", &num);
                while (getchar() != '\n');
                deleteNode2(num);
                break;
            }
            case 4: {
                system("cls");
                int data = 0;
                int num = 0;
                printf("请输入在更改的结点的内容 和 更改在第几个结点的位置上。输入格式如 2,2\n");
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
            printf("时间比较紧，还没开始做");
            break;

        default:
            break;
        }

    }
    system("pause");
    return 0;
}
