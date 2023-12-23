#include <stdio.h>
int binary_search(int arr[], int sz, int k)
{
    int left = 0;
    int right = sz - 1;
    int a = 0;
    while (right >= left)
    {
        a = (left + right) / 2;
        if (arr[a] > k)
        {
            right = a - 1;
        }
        else if (arr[a] < k)
        {
            left = a + 1;
        }
        else if (arr[a] == k)
        {
            return a;
        }
    }
    if (right < left)
    {
        return -1;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 4;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_search(arr, sz, k);
    if (ret == -1)
    {
        printf("未找到");
    }
    else
    {
        printf("找到了，下标是%d", ret);
    }
    return 0;
}