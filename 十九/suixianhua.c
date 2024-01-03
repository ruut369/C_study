#include <stdio.h>
// 输入两个数，找到两个数之间的所有水仙花数
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
    for (int i = a; i <= b; i++)
    {
        int count = 0;
        int x = i;
        while (x != 0)
        {
            x = x / 10;
            count++;
        }
        int Sum = 0;
        int y = i;
        while (y != 0)
        {
            int k = 0;
            k = y % 10;
            int sum = 1;
            for (int j = 0; j < count; j++)
            {
                sum *= k;
            }
            Sum += sum;
            y = y / 10;
        }
        if (i == Sum)
        {
            printf("%d ", i);
        }
    }
    return 0;
}