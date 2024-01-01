#include <stdio.h>
int DigitSum(int num)
{
    if (num > 9)
    {
        return DigitSum(num / 10) + num % 10;
    }
    else
    {
        return num;
    }
}
int main()
{
    unsigned int num = 0;
    scanf("%d", &num);
    printf("%d", DigitSum(num));
    return 0;
}