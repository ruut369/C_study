#include <stdio.h>
#include <stdlib.h>

// 定义一个指针变量
int main()
{
    // 基本概念
    int x = 42;
    int *ptr = &x; // 指向 x 的地址
    printf("Original value of x: %d\n", x);

    // 修改 x 的值通过传递地址
    *ptr = 30;
    // ptr存储的是x的地址，*ptr解引用，存储的是x的值
    printf("New value of x: %d\n", x);

    // 动态内存分配
    int *arr = malloc(5 * sizeof(int)); // 动态分配一个包含 5 个整数的数组

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    printf("Dynamic array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // 释放动态分配的内存

    // 数组和字符串操作
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr_numbers = numbers;

    printf("Array elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *ptr_numbers);
        ptr_numbers++;
    }
    printf("\n");

    return 0;
}
