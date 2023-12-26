#include <stdio.h>
// 冒泡排序
void mao_pao(int arr[], int sz) // int arr[];or int *arr
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int flag = 1; // 假设有序
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag == 1) // 如果有序，就不用再排了
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {7, 8, 9, 5, 4, 4, 0, 2, 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    mao_pao(arr, sz);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n%d", *(arr + 3)); // arr[3] == *(arr + 3);
    printf("\n%p", &arr[3]);    //&arr[3] == (arr + 3);
    printf("\n%p", (arr + 3));
    printf("\n%p", &arr[0]); // arr == &arr[0];
    printf("\n%p", arr);
    printf("\n%p", &arr);        // &arr == &arr[0];&arr是取整个数组的地址，&arr[0]是取数组第一个元素的地址，他们的值是一样的，但意义不同，
    printf("\n%p", &arr[0] + 1); // 地址跳到下一个元素的地址
    printf("\n%p", &arr + 1);    // 地址跳到下一个数组的地址
    return 0;
}