// #include <stdio.h>
// // 输入34786 输出 10100 奇数化1偶数化0
// int count(int sum)
// {
//     int count = 1;
//     while (sum)
//     {
//         sum = sum / 10;
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     int input = 0;
//     printf("请输入一个整数：\n");
//     scanf("%d", &input);
//     int sz = count(input);
//     int sum = 0;
//     for (int i = 0; i < sz; i++)
//     {
//         if (input % 10 % 2 == 1)
//         {
//             sum = sum + (1 * pow(10, i));
//         }
//         input = input / 10;
//     }
//     printf("%d", sum);
//     return 0;
// }

// #include <stdio.h>
// // 打印三角形
// // 输入5打印：
// //          *
// //        * *
// //      * * *
// //    * * * *
// //  * * * * *
// int main()
// {
//     printf("请输入三角形边长：");
//     int input = 0;
//     scanf("%d", &input);
//     for (int i = 0; i < input; i++)
//     {
//         for (int j = 0; j < 2 * input; j++)
//         {
//             if (j < 2 * (input - i - 1))
//             {
//                 printf(" ");
//             }
//             else
//             {
//                 if (j % 2 == 1)
//                 {
//                     printf("*");
//                 }
//                 else
//                 {
//                     printf(" ");
//                 }
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }
