// 欢迎效果图
#include <stdio.h>
#include <string.h>
#include <windows.h> //windows.h头文件中定义了很多Windows API函数原型，以及一些数据类型和宏
#include <unistd.h>  // sleep函数头文件
int main()
{
    char arr1[] = "welcome to  fuck bitch!!!!!!";
    char arr2[] = "############################";
    int left = 0;
    int right = strlen(arr1) - 1; // 数组长度
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);
        sleep(1); // 停顿1s
        left++;
        right--;
    }

    return 0;
}