#include <stdio.h>
void reverse(int arr[], int sz)
{
    int j = sz;
    for (int i = 0; i < sz; i++)
    {
        j--;
        if (j >= i)
        {
            int num = arr[i];
            arr[i] = arr[j];
            arr[j] = num;
        }
    }
}
void lnlt(int *p, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        *(p + i) = 0;
    }
}
void print(int *p, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", *(p + i));
    }
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int sz = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, sz);
    print(arr, sz);
    lnlt(arr, sz);
    print(arr, sz);
    return 0;
}