#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d\n", sizeof(arr)); // 20
    // sizeof(数组名)，数组名表示整个数组，所以sizeof(数组名)表示整个数组的大小，单位是字节。
    printf("%d\n", sizeof(arr + 0)); // 4/8
    // sizeof(数组名+0)，数组名单独使用表示整个数组，数组名+0表示数组首元素的地址，所以sizeof(数组名+0)表示指针变量大小，单位是字节。
    printf("%d\n", sizeof(*arr)); // 4
    // 这里arr表示数组首元素的地址，*arr表示数组首元素的值，所以sizeof(*arr)表示数组首元素的值所占内存大小，是int类型,占4个字节。
    printf("%d\n", sizeof(arr + 1)); // 4/8
    // arr+1表示数组第二个元素的地址，所以sizeof(arr+1)表示第二个元素的地址所占内存大小，是指针类型，占4/8字节。
    printf("%d\n", sizeof(arr[1])); // 4
    // arr[1]表示数组第二个元素的值，所以sizeof(arr[1])表示第二个元素的值所占内存大小，是int类型,占4个字节。
    printf("%d\n", sizeof(&arr)); // 4/8
    // &arr表示数组的地址，所以sizeof(&arr)表示数组的地址所占内存大小，是指针类型，占4/8字节。
    printf("%d\n", sizeof(*&arr)); // 20
    //&arr拿到的是int (*)[5]类型的数组名地址，一种数组指针，*&arr表示数组的地址所指向的值，所以sizeof(*&arr)表示数组的地址所指向的值所占内存大小，是int[5]类型，占20个字节。
    printf("%d\n", sizeof(&arr + 1)); // 4/8
    //&arr表示数组的地址，&arr+1表示数组的地址+1，跳过一个数组的地址，所以sizeof(&arr+1)表示地址内存大小，是指针类型，占4/8字节。
    printf("%d\n", sizeof(&arr[0])); // 4/8
    //&arr[0]表示数组第一个元素的地址，所以sizeof(&arr[0])表示数组第一个元素的地址所占内存大小，是指针类型，占4/8字节。
    printf("%d\n", sizeof(&arr[0] + 1)); // 4/8
    //&arr[0]表示数组第一个元素的地址，&arr[0]+1表示数组第二个元素的地址，所以sizeof(&arr[0]+1)表示数组第二个元素的地址所占内存大小，是指针类型，占4/8字节。
    return 0;
}