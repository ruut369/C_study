#include <stdio.h>
double pow(n, k)
{
    if (k > 0)
    {
        return pow(n, k - 1) * n;
    }
    else if (k == 0)
        return 1;
    else
        return 1.0 / pow(n, -k);
}
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    printf("%lf\n", pow(n, k));
    int a = -1;
    a = a >> 2;
    printf("%d", a);

    return 0;
}