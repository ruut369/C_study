#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成[min, max]范围内的随机整数
int generateRandomNumber(int min, int max)
{
    // 初始化随机数生成器，使用当前时间作为种子
    srand(time(NULL));

    // 生成[min, max]范围内的随机整数
    int randomNumber = rand() % (max - min + 1) + min;

    return randomNumber;
}

int main()
{
    int i = 0;
    for (i = 0; i < 5; i++)
    { // 生成10到20之间的随机数
        int randomNum = generateRandomNumber(10, 20);

        // 打印生成的随机数
        printf("Random Number: %d\n", randomNum);
        sleep(1);
    }
    return 0;
}
