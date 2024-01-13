// #include <stdio.h>
// // 左旋字符串k个字符
// #include <string.h>
// void rotate(char arr[], int k)
// {
//     // 判断k是否大于字符，大于时剔除重复运算
//     int len = strlen(arr);
//     k %= len;
//     for (int i = 0; i < k; i++) // 重复k次左旋
//     {
//         char tmp = arr[0];
//         for (int j = 0; j < len - 1; j++)
//         {
//             arr[j] = arr[j + 1]; // 数往前移动一位
//         }
//         arr[len - 1] = tmp;
//     }
// }
// int main()
// {
//     char arr[] = "abcdef";
//     rotate(arr, 9);
//     printf("%s ", arr);
//     return 0;
// }

// #include <stdio.h>
// // 杨氏矩阵查找
// //  1 2  3  4
// //  5 6  7  8
// //  9 10 11 12
// struct point
// {
//     int x;
//     int y;
// };
// struct point find_num(int arr[3][4], int r, int c, int num)
// {
//     struct point p = {-1,-1};
//     for (int i = 0; i < r; i++)
//     {

//         if (arr[i][c] > num)
//         {
//             for (int j = c - 1; j >= 0; j--)
//             {
//                 if (arr[i][j] == num)
//                 {
//                     p.x = i;
//                     p.y = j;
//                     return p;
//                 }
//             }
//         }
//         if (arr[i][c] == num)
//         {
//             p.x = i;
//             p.y = c;
//             return p;
//         }
//     }
//     return p;
// }
// int main()
// {
//     int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//     struct point k = find_num(arr, 3, 4, 7);
//     printf("%d %d", k.x, k.y);
//     return 0;
// }

// // 判断1个字符串是否是另一个字符串左旋得来(方法一)
// #include <stdio.h>
// #include <string.h>
// int tell(char arr1[], char arr2[])
// {
//     int count = 0;
//     int len = strlen(arr1);
//     for (int i = 0; i < len; i++) // 重复k次左旋
//     {
//         char tmp = arr1[0];
//         for (int j = 0; j < len - 1; j++)
//         {
//             arr1[j] = arr1[j + 1]; // 数往前移动一位
//         }
//         arr1[len - 1] = tmp;
//         count++;
//         // if (arr1[0] == arr2[0])
//         // {
//         //     for (int k = 0; k < len; k++)
//         //     {
//         //         if (arr1[k] != arr2[k])
//         //         {
//         //             break;
//         //         }
//         //         if (k == len - 1)
//         //         {
//         //             return count;
//         //         }
//         //     }
//         // }
//         int k = strcmp(arr1, arr2);
//         if (k == 0)
//         {
//             return count;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     char arr1[] = "aaaabcde";
//     char arr2[] = "aabcdeaa";
//     int count = tell(arr1, arr2); // 如果是通过左旋得到返回左旋次数，不是则返回0
//     printf("%d", count);
//     return 0;
// }

// // 判断1个字符串是否是另一个字符串左旋得来(方法二)
// #include <stdio.h>
// #include <string.h>
// int tell2(char arr1[], char arr2[])
// {
//     int len2 = strlen(arr2);
//     int len1 = strlen(arr1);
//     strncat(arr2, arr2, len2);
//     char *p = strstr(arr2, arr1);
//     if (p == NULL)
//     {
//         return 0;
//     }
//     if (len1 == len2)
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     char arr1[] = "aaaabcde";
//     char arr2[] = "aabc";
//     if (tell2(arr1, arr2) == 1)
//         printf("是");
//     else
//         printf("否");

//     return 0;
// }