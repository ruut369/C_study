#include <stdio.h>
// 计算二进制中1的个数
int main()
{
    int a = 7; // 111
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a & 1 == 1)
        {
            count++;
        }
        a = a >> 1;
    }
    int x = 1, y = 3;
    // if(x ==y){
    //     y = 5;
    // }
    // else{
    //     y = 10;
    // }
    y = (x == y ? 5 : 10); // 三目操作符
    // 逗号表达式
    int k = (x > y, x = y + 3, x, y = x + 2); // 结果从左到右计算，值取最右边的结果
    printf("%d\n", count);
    return 0;
}