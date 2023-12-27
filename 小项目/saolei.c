#include <stdio.h>
#include "function.h"
int main()
{
    int input = 0;
    do
    {
        printf("****************************\n");
        printf("*****  1.play  2.exit  *****\n");
        printf("****************************\n");
        printf("请选择>");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("开始运行\n");
            game();
        }
        else if (input != 1 && input != 2)
        {
            printf("输入非法，请重新输入\n");
        }
    } while (input != 2);
    printf("游戏结束\n");
    return 0;
}