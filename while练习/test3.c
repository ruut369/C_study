#include <stdio.h>
int main()
{
    int i = 1;
    int a = 0;
    int num = 1;
    int sum = 0;
    for (i = 1; i <= 4; i++)
    {
        num = num * i; // 求i的阶乘
        sum = sum + num;
    }
    printf("%d\n", num);
    printf("%d", sum);
    return 0;
}