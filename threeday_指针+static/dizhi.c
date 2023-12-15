#include <stdio.h>
int main()
{
    char ch = 'w';   // 字符变量,char类型占一个字节,8位,无法存储中文，一个字母占一个字节
    char *ch2 = &ch; // 指针变量
    *ch2 = 'h';      // 通过指针变量修改ch的值
    printf("%c\n", ch);
    printf("%d\n", sizeof(ch2));
    return 0;
}