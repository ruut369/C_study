// #include <stdio.h>

// int main()
// {
//     char arr[20] = {0};
//     strcpy(arr, "zhangsan");

//     return 0;
// }

// // 模拟实现strcpy()
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
// char *my_strcpy(char *p1, const char *p2)
// {
//     assert(p1); // 为空指针报错
//     assert(p2);
//     char *ret = p1;
//     while (*p2 != '\0')
//     {
//         *p1++ = *p2++;
//     }
//     *p1 = *p2;
//     return ret;
// }
// int main()
// {
//     char a[20] = {0};
//     char b[] = "hello world";
//     char arr[20] = "hello";
//     char arr2[20] = "world";
//     strcat(arr, arr2); // strcat追加字符串
//     my_strcpy(a, b);
//     return 0;
// }

// #include <stdio.h>
// // 模拟strcmp(),比较两个字符串大小
// #include <assert.h>
// int strcmp(const char *str1, const char *str2)
// {
//     assert(str1 && str2);
//     while (*str1 == *str2)
//     {
//         if (*str1 == '\0')
//         {
//             return 0;
//         };
//         str1++;
//         str2++;
//     }
//     return (*str1 - *str2);
// }
// int main()
// {
//     char arr1[] = "abd";
//     char arr2[] = "abc";
//     int ret = strcmp(arr1, arr2);
//     if (ret < 0)
//     {
//         printf("arr1 < arr2");
//     }
//     else if (ret > 0)
//     {
//         printf("arr1 > arr2");
//     }
//     else
//     {
//         printf("arr1 == arr2");
//     }
//     return 0;
// }

// 长度受限的字符串函数
// num为执行的长度
// strncpy(char*str1,const char*str2,unsigned int num)  作用是将str2的前num个字符拷贝到str1中
// strncat(char*str1,const char*str2,unsigned int num)  作用是str1追加str2的前num个字符
// strncmp(const char*str1,const char*str2,unsigned int num) 作用是比较str1和str2的前num个字符

// #include <stdio.h>
// // 模拟实现strstr()
// #include <assert.h>
// char *my_strstr(const char *str1, const char *str2) // const char *str1 中*str1不可修改，str1可修改
// {
//     assert(str1 && str2);
//     const char *tmp2 = str2;
//     while (*str1 != '\0')
//     {
//         while (*str1 != *str2 && *str1 != '\0')
//         {
//             str1++;
//         }
//         if (*str1 == '\0')
//         {
//             break;
//         }

//         const char *tmp = str1;
//         while (*str1 == *str2)
//         {
//             str1++;
//             str2++;
//             if (*str2 == '\0')
//             {
//                 return (char *)tmp;
//             }
//         }
//         str1 = tmp + 1;
//         str2 = tmp2;
//     }
//     return NULL;
// }
// int main()
// {
//     char arr1[] = "abbbcde";
//     char arr2[] = "bcd";
//     char *p = my_strstr(arr1, arr2);
//     printf("%s", p);
//     return 0;
// }

// // strtok(char* str1,char* str2)  str1是要切割的字符串，str2是切割的标志
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char arr[] = "ab-cd-ef";
//     char *p = strtok(arr, "-");
//     while (p != NULL)
//     {
//         printf("%s\n", p);
//         p = strtok(NULL, "-");
//     }
//     return 0;
// }

// // strerror()是一个函数，用来获取错误码对应的错误信息
// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// int main()
// {
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         printf("%s\n", strerror(errno)); // errno是全局变量，表示错误码
//     }
//     return 0;
// }

// 字符分类函数
//  isalpha() 判断是否为字母 用法：
//  isdigit() 判断是否为数字
//  isalnum() 判断是否为字母或数字
//  isspace() 判断是否为空格
//  isupper() 判断是否为大写字母
//  islower() 判断是否为小写字母
//  toupper() 小写转大写
//  tolower() 大写转小写

// memcpy() // 内存拷贝函数,不能自我拷贝使用
// void* memcpy(void* dest,const void* src,size_t count)
// dest 目的地 src 源头 count 拷贝的字节数
// 返回值：目的地的起始地址
