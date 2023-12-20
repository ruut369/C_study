#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = sz - 1;
    int n = 6;
    while (right >= left)
    {
        int mid = (left + right) / 2; // int向下取整4.5取4
        if (arr[mid] > n)
        {
            right = mid - 1;
        }
        else if (arr[mid] < n)
        {
            left = mid + 1;
        }
        else if (arr[mid] = n)
        {
            printf("n查找成功，下标为%d\n", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("不存在这个数");
    }

    return 0;
}