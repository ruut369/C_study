// #include <stdio.h>
// // 判断一个数组是否有序
// #include <string.h>
// int tell(int arr[], int k)
// {
//     int flag1 = 0; // 判断是否升序
//     int flag2 = 0; // 判断降序
//     for (int i = 0; i < k - 1; i++)
//     {
//         if (arr[i] < arr[i + 1])
//         {
//             flag1 = 1;
//         }
//         else if (arr[i] > arr[i + 1])
//         {
//             flag2 = 1;
//         }
//         if (flag1 + flag2 == 2)
//         {
//             break;
//         }
//     }
//     if (flag1 + flag2 <= 1)
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     int n = 0;
//     int arr[50] = {};
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     int ret = tell(arr, n);
//     if (ret == 1)
//     {
//         printf("有序");
//     }
//     else
//         printf("无序");
//     return 0;
// }