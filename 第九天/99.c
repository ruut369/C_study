#include <stdio.h>
int main()
{
    // 1*1=1
    // 1*2=2 2*2=2
    // 1*3=3 2*3=4 3*3=3
    int i = 1;
    for (i = 1; i <= 9; i++) // i是行
    {
        int j = 1;
        for (j = 1; j <= i; j++) // j是列
        {
            // int sum = 0;
            // sum = j * i;
            // printf("%d*%d=%-2d ", j, i, sum);
            printf("%d*%d=%-2d ", j, i, j * i);
        }
        printf("\n");
    }
    return 0;
}