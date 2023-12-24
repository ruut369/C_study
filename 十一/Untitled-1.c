#include <stdio.h>
int my_len(char *str) // char *str = arr;  char *str = &arr[0];
{
    if (*str != '\0') // *str是值，值不为'\0'，则递归调用
    {
        return 1 + my_len(str + 1); // str + 1是地址，地址+1，指向下一个元素
    }
    return 0;
}
int main()
{
    char arr[] = "hello world";
    int len = my_len(arr); // arr是数组，数组传参，传递的是数组首元素的地址
    printf("len = %d\n", len);
    return 0;
}