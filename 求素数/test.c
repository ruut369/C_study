// 求两个数之间的所有素数
#include <stdio.h>
#include <math.h>
int main()
{
    int n = 0;
    int m = 0;
    printf("请输入两个数：");
    scanf("%d%d", &n, &m);
    if (n > m)
    {
        int mid = n;
        n = m;
        m = mid;
    }
    int a = n;
    int sum = 0;
    for (a = n; a <= m; a++)
    {
        int i = 2;
        for (i = 2; i <= sqrt(m); i++)
        {
            if (a % i == 0)
            {
                break;
            }
        }
        if (i > sqrt(m))
        {
            printf("%d  ", a);
            sum++;
        }
    }
    printf("\n一共有%d个素数\n", sum);
    return 0;
}