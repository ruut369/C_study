#include <stdio.h>
#include <string.h>
// 递归字符串倒置
int my_strlen(char arr[])
{
    int count = 0;
    int i = 0;
    do
    {
        if (arr[i] != '\0')
        {
            count++;
        }
        i++;
    } while (arr[i] != '\0');
    return count;
}
void reverse(char *p)
{
    int sz = my_strlen(p);
    char tmp = *p;
    *p = *(p + sz - 1);
    *(p + sz - 1) = '\0';
    if (my_strlen(p + 1) >= 2)
    {
        reverse(p + 1);
    }
    *(p + sz - 1) = tmp;
}
void reverse2(char *p, int left, int right)
{
    int tmp = *(p + left);
    *(p + left) = *(p + right);
    *(p + right) = tmp;
    left++;
    right--;
    if (right > left)
    {
        reverse2(p, left, right);
    }
}
int main()
{
    char arr[] = "abcdefgh";
    printf("%d\n", my_strlen(arr));
    reverse(arr);
    for (int i = 0; i < my_strlen(arr); i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    printf("%s\n", arr);
    int left = 0;
    int right = my_strlen(arr) - 1;
    reverse2(arr, left, right);
    printf("%s\n", arr);
    return 0;
}