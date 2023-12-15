#include <stdio.h>
static int num = 10; // static修饰的全局变量，只能在本文件中使用,改变变量的作用域。
static int fun(int a, int b)
{
    return a + b;
} // static修饰的函数，只能在本文件中使用，改变函数的链接属性，外部链接变为内部链接。
#define max 100                   // #define定义的常量，只能在本文件中使用，改变常量的作用域。
#define min(a, b) (a < b ? a : b) // #define定义的宏.
int main()
{
    int num5 = min(100, 300);
    printf("%d\n", num5);
    int i = 0;
    while (i < 10)
    {
        static int num2 = 15; // static修饰的局部变量，只能在本函数中使用，改变变量的生命周期。
        num2++;
        printf("num2 = %d\n", num2);
        i++;
    }
    // 打印num，num2,num3，num4
    printf("num = %d\n", num);
    return 0;
}