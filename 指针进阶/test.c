#include <stdio.h>
// 输入一个整数数组，奇数排左边，偶数排右边
void sorting(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        while (left < right && arr[left] % 2 == 1)
        {
            left++;
        }
        while (left < right && arr[right] % 2 == 0)
        {
            right--;
        }
        int tmp = 0;
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}
int main()
{
    int arr[10] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    // 输入数组
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", arr + i);
    }
    // 整理数组，左奇右偶
    sorting(arr, sz); // 1 2 3 4 5 6 7 8
    // 打印数组
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}