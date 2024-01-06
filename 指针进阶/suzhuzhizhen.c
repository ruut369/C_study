#include <stdio.h>
// 数组指针
int main()
{
    int arr[10] = {0};
    // 数组指针是指向数组的指针
    // int (*p)[10] = &arr;
    // int指针是指向int类型的指针
    // int *p = a;
    // char指针是指向char类型的指针
    // char *p = &c;
    int(*p)[10] = &arr; // p指针指向数组int*[10]，数组每个元素类型为int
    //&arr是取整个数组的地址，arr是取数组首元素的地址
    // arr在两种特殊情况下是指整个数组，一是sizeof(arr)，二是&arr
    return 0;
}