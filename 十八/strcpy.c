#include <stdio.h>
#include <assert.h>
char *my_strcpy(char *str, const char *str2)
{
    char *p = str;
    assert(str != NULL); // 断言，传空数据来会报警告
    assert(str2 != NULL);
    while (*str++ = *str2++)
    { // 当*str读到'\0'的时候，*str = '\0',为假
        ;
    }
    return p;
}
int main()
{
    char arr[] = "*******************";
    char arr2[] = "hello world";
    printf("%s \n", my_strcpy(arr, arr2));
    printf("%s ", arr);
    return 0;
}