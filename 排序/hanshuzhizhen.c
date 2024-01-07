#include <stdio.h>
// 加法函数
int Add(int x, int y)
{
    return x + y;
}
// 减法函数
int Sub(int x, int y)
{
    return x - y;
}
// 乘法函数
int Mul(int x, int y)
{
    return x * y;
}
// 除法函数
int Div(int x, int y)
{
    return x / y;
}
int main()
{
    // 定义一个函数指针数组存放函数指针int（*arr[5]）（int,int）
    int (*arr[5])(int, int) = {0, Add, Sub, Mul, Div};
    int input = 0;
    do
    {
        printf("***********************\n");
        printf("******* 1.+ 2.- *******\n");
        printf("******* 3.* 4./ *******\n");
        printf("******* 0.退出 ********\n");
        printf("***********************\n");
        printf("请输入数字: ");
        scanf("%d", &input);
        if (input == 0)
        {
            break;
        }

        if (input != 1 && input != 2 && input != 3 && input != 4)
        {
            printf("输入错误，请重新输入\n");
        }

    } while (input != 1 && input != 2 && input != 3 && input != 4 && input != 0);
    if (input == 0)
    {
        printf("退出\n");
        return 0;
    }
    else
    {
        int x = 0;
        int y = 0;
        printf("请输入两个操作数: ");
        scanf("%d %d", &x, &y);
        int ret = arr[input](x, y);
        printf("%d\n", ret);
    }
}