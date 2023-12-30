#include <stdio.h>

int main()
{
    // 交换两个整数数值的三种方法
    int a = 1;
    int b = 2;
    // 方法一.缺陷：当a和b的值过大时，可能会导致溢出
    a = a + b;
    b = a - b;
    a = a - b;
    // 方法二.缺陷：可读性差
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // 方法三
    int temp = a;
    a = b;
    b = temp;
    return 0;
}