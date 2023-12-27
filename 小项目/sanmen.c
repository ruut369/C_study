#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// 生成[min, max]范围内的随机整数
int getNum(int min, int max)
{
    // 无需在这里初始化随机数生成器
    return rand() % (max - min + 1) + min;
}

int main()
{
    int sum1 = 0;
    int sum2 = 0;
    // 初始化随机数生成器，使用当前时间作为种子
    srand(time(NULL));
    int j = 100000; // 试验次数
    for (int k = 0; k < j; k++)
    {
        int arr[3] = {1, 2, 2}; // 1代表中奖，2代表没中奖
        // 选择一扇门
        int my = getNum(0, 2);
        // 主持人打开一扇没有奖的门
        int he = 0;
        do
        {
            he = getNum(0, 2);
        } while (he == my || arr[he] == 1);
        // 不切换门
        if (arr[my] == 1)
        {
            sum1++;
        };
        // 换门
        for (int i = 0; i < 3; i++)
        {
            if (i != my && i != he)
            {
                if (arr[i] == 1)
                {
                    sum2++;
                    break;
                }
                break;
            }
        }
    }
    // 不切换赢的概率
    double sm1 = (double)sum1 / j; // 注意：在计算概率时，确保使用浮点数除法而非整数除法，
                                   // 否则结果可能会被截断为整数，导致概率计算错误。
                                   // 示例：
                                   // 修改前：double result = sum / total;
                                   // 修改后：double result = (double)sum / total;

    // 切换赢的概率
    double sm2 = (double)sum2 / j;
    printf("不切换赢的概率：%f\n", sm1);
    printf("切换赢的概率：%f\n", sm2);
    // getchar();
    return 0;
}