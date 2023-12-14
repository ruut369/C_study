#include <stdio.h>
int main()
{
    int num1 = 0;
    while (num1 < 200)
    {
        printf("敲了一行代码，一共敲了");
        num1++;
        printf("%d\n", num1);
        if (num1 == 100)
        {
            printf("已经成功一半了\n");
        }
        else
        {
        }
    }
    printf("成功了");
    return 0;
}
