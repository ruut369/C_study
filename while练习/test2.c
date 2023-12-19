#include <stdio.h>
int main()
{
    int sum = 1;
    for (int i = 10; i > 0; i--)
    {
        sum = sum * i;
    }
    printf("%d", sum);
    return 0;
}