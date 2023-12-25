#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = {'我', 'z'};
    char arr2[] = "我z";
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(arr2));
    int sz = sizeof(arr) / sizeof(arr[0]);
    int sz2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", sz);
    printf("%d\n", sz2);
    printf("%d\n", sizeof(arr));
    printf("%d\n", strlen(arr));
    return 0;
}