#include <stdio.h>

void generateMagicSquare(int n)
{
    int magicSquare[n][n];

    // 初始化所有单元格为0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // 初始位置
    int i = n / 2;
    int j = n - 1;

    // 填充魔方阵
    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            // 处理边界条件
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }

        // 如果下一个位置已经被占据
        if (magicSquare[i][j] != 0)
        {
            j -= 2;
            i++;
            continue;
        }
        else
        {
            magicSquare[i][j] = num++;
        }

        j++;
        i--;
    }

    // 打印魔方阵
    printf("Magic Square for n=%d:\nSum of each row/column/diagonal is %d:\n\n", n, n * (n * n + 1) / 2);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            printf("%3d ", magicSquare[x][y]);
        printf("\n");
    }
}

int main()
{
    int n;

    // 获取用户输入的奇数阶
    printf("Enter order (odd number) of magic square: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("Please enter an odd number for the order of magic square.\n");
        return 1;
    }

    generateMagicSquare(n);

    return 0;
}
