#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)
{ // const 确保不会用指针对数据进行修改，增加稳定性
    int count = 0;
    assert(str); // 断言，传空数据来会报警告
    while (*str != '\0')
    {
        str++;
        count++;
    }
    return count;
}
int main()
{
    char arr[] = "hello world";
    int len = my_strlen(arr);
    printf("%d \n", len);
    return 0;
}