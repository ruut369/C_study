#include <stdio.h>
int main()
{
    int age = 0;
    while (1)
    {
        printf("请输入年龄：");
        scanf("%d", &age);
        if (age >= 0 && age <= 17)
        {
            printf("是未成年人,可以做梦\n");
        }
        else if (age >= 18 && age <= 35)
        {
            printf("是青年人,可以当牛马\n");
        }
        else if (age >= 36 && age <= 55)
        {
            printf("是中年人,可以养家糊口\n");
        }
        else if (age >= 56 && age <= 150)
        {
            printf("是老年人,可以享受天伦之乐\n");
        }
        else
        {
            printf("输入有误\n");
        }
    }

    return 0;
}