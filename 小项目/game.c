#include <stdio.h>
#include <stdlib.h>
// #include "display.c"
#define ROW 3
#define COL 3
#include <time.h>
// 生成[min, max]范围内的随机整数
int generateRandomNumber(int min, int max)
{
    // 无需在这里初始化随机数生成器
    return rand() % (max - min + 1) + min;
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = ' ';
            }
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}
int PlayerMove(char board[ROW][COL], int x, int y, int k)
{
    if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
    {
        if (board[x - 1][y - 1] == ' ')
        {
            board[x - 1][y - 1] = 'X';
            DisplayBoard(board, ROW, COL);
        }
        else
        {
            printf("坐标被占用\n");
            return 1;
        }
    }
    else
    {
        printf("坐标非法\n");
        return 1;
    }
}
void ComputerMove(char board[ROW][COL])
{
    // 电脑随机下棋
    // x,y取值范围[1,3]
    int x = 0;
    int y = 0;
    // 初始化随机数生成器，使用当前时间作为种子
    srand(time(NULL));
    do
    {
        x = generateRandomNumber(1, 3);
        y = generateRandomNumber(1, 3);
        if (board[x - 1][y - 1] == ' ')
        {
            board[x - 1][y - 1] = 'o';
            printf("电脑下棋\n");
            DisplayBoard(board, ROW, COL);
            break;
        }

    } while (board[x - 1][y - 1] != ' ');
}
int JudgeWinner(char board[ROW][COL], int row, int col)
{

    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
        (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
        (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
        (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
        (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        return 1;
    }
    if ((board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') ||
        (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') ||
        (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') ||
        (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') ||
        (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') ||
        (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') ||
        (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
        (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'))
    {
        return -1;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 2;
    // else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
    //          board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
    //          board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
    // {
    //     return 2;
    // }
}
void game()
{
    char board[ROW][COL] = {0};
    DisplayBoard(board, ROW, COL);
    int x = 0;
    int y = 0;
    while (1)
    {
        int k = 0;
        do
        {
            printf("请输入要下的坐标:>");
            scanf("%d%d", &x, &y);
            k = PlayerMove(board, x, y, k);
            int winner = JudgeWinner(board, ROW, COL);
            if (winner == 1)
            {
                printf("恭喜你赢了！\n");
                return;
            }
            else if (winner == -1)
            {
                printf("电脑赢了！\n");
                return;
            }
            else if (winner == 2)
            {
                printf("平局！\n");
                return;
            }
        } while (k == 1);
        ComputerMove(board);
        // 判断输赢
        int winner = JudgeWinner(board, ROW, COL);
        if (winner == 1)
        {
            printf("恭喜你赢了！\n");
            return;
        }
        else if (winner == -1)
        {
            printf("电脑赢了！\n");
            return;
        }
        else if (winner == 2)
        {
            printf("平局！\n");
            return;
        }
    }
}
int main()
{
    int input = 0;
    do
    {
        printf("******************************\n");
        printf("********1. play 2.exit********\n");
        printf("******************************\n");
        printf("Please select:>");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("Play game!\n");
            game();
        }
        if (input == 2)
        {
            printf("Exit game!\n");
        }
        if (input != 1 && input != 2)
        {
            printf("Please select again!\n");
        }
    } while (input != 2);
    return 0;
}