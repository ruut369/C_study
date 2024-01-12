#include <stdio.h>
//找出凶手
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 2; b++)
        {
            for (c = 0; c < 2; c++)
            {
                for (d = 0; d < 2; d++)
                {
                    if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3 && a + b + c + d == 1)
                    {
                        printf("%d %d %d %d", a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}