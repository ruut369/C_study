// Created by 1051380 on 2020/04/01.
#include <stdio.h>
int main() // main函数程序必须有且只有一个
// main函数是程序的入口，程序的执行从main函数开始，main函数结束，程序结束
{
    // %d是整型占位符，%c是字符型占位符，%f是浮点型占位符，%s是字符串占位符，%p是指针占位符，%x是十六进制占位符。
    printf("Hello, World!\n");
    printf("666666\n");
    char ch = 'A';
    int bh = 20.9;
    printf("%d\n", bh);
    printf("%c\n", ch);
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(long long));
    return 0;
}