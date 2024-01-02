#include <stdio.h>

int main()
{
    const int a = 20;
    const int *p = &a;
    // int **pa = &p;
    // **pa = 30;
    int b = 30;
    int *pi = &b;
    p = &b;
    // *p = 50;
    printf("%d %d\n%p", a, b, p);

    return 0;
}