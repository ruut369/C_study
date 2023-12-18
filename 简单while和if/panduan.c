#include <stdio.h>
int main()
{
    int i = 0;
    while (i < 5)
    {
        i++;
        int num = 0;
        printf("请输入一个数：");
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            printf("是偶数\n");
        }
        else
            printf("是奇数\n");
    }
    int a = 0;
    while (a <= 100)
    {
        printf("%d\n", a);
        a = a + 2;
    }
    return 0;
}