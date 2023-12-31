#include <stdio.h>
int my_strlen(char *p)
{
    char *star = p;
    char *end = p;
    while (*end != '\0')
    {
        end++;
    };
    return end - star;
}
int main()
{
    char arr[] = "hello world";
    int len = my_strlen(arr);
    printf("%d", len);
    return 0;
}