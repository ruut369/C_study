#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    // int i = b;
    // while (1)
    // {
    //     if (i % b == 0 && i % a == 0)
    //     {
    //         printf("%d和%d的最小公倍数是：%d", a, b, i);
    //         break;
    //     }
    //     i++;
    // }
    int i = 1;
    while (b * i % a != 0)
    {
        i++;
    }
    printf("%d和%d的最小公倍数是：%d", a, b, b * i);
    return 0;
}