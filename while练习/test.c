#include <stdio.h>
int main()
{
    int num = 0;
    printf("请输入一个数：");
    scanf("%d", &num);
    int i = num;
    int sum = 1;
    for (; i <= num && i > 0; i--)
    {
        sum = sum * i;
    }
    printf("该数的阶乘为：%d", sum);
    return 0;
}