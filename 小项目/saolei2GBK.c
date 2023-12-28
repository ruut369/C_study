#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define easy_mine 10
int GetRandom(int min, int max)
{
    // 无需在这里初始化随机数生成器
    return rand() % (max - min + 1) + min;
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    for (i = 0; i <= row; i++)
    {
        printf(" %d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        int j = 0;
        for (j = 1; j <= col; j++)
        {
            if (j == 1)
            {
                printf(" %d ", i);
            }
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    for (i = 0; i < ROWS; i++)
    {
        int j = 0;
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = set;
        }
    }
}
void setMine(char board[ROWS][COLS], int row, int col, int easy)
{
    int count = easy;                // 布置的雷数量
    srand((unsigned int)time(NULL)); //  初始化随机数生成器，使用当前时间作为种子
    do
    {
        int i = GetRandom(1, ROW);
        int j = GetRandom(1, COL);
        if (board[i][j] == '0')
        {
            board[i][j] = '1';
            count--;
        }
    } while (count);
}
void move(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *over)
{
    if (x > 0 && x <= ROW && y > 0 && y <= COL)
    {
        if (show[x][y] == '#')
        {
            if (mine[x][y] == '1')
            {
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, ROW, COL);
                printf("\n");
                *over = 0;
                sleep(2);
            }
            else if (mine[x][y] == '0')
            { // 计算相邻地雷的数量并将其转换为字符表示,数字+ '0'转换成字符
                show[x][y] = (mine[x - 1][y - 1] - '0') + (mine[x - 1][y] - '0') +
                             (mine[x][y + 1] - '0') + (mine[x][y - 1] - '0') + (mine[x - 1][y + 1] - '0') +
                             (mine[x + 1][y - 1] - '0') + (mine[x + 1][y] - '0') + (mine[x + 1][y + 1] - '0') + '0';
                char k = show[x][y];
                if (k == '0' && x > 1 && x < ROW && y > 1 && y < COL)
                {
                    int over = 1;
                    move(mine, show, x - 1, y - 1, &over);
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x - 1, y + 1, &over);
                    move(mine, show, x + 1, y - 1, &over);
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x + 1, y + 1, &over);
                }
                if (k == '0' && x == 1 && y == 1)
                {
                    int over = 1;
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x + 1, y + 1, &over);
                }
                if (k == '0' && x == ROW && y == COL)
                {
                    int over = 1;
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x - 1, y - 1, &over);
                }
                if (k == '0' && x == 1 && y == COL)
                {
                    int over = 1;
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x + 1, y - 1, &over);
                }
                if (k == '0' && x == ROW && y == 1)
                {
                    int over = 1;
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x - 1, y + 1, &over);
                }
                if (k == '0' && x == 1 && y > 1 && y < COL)
                {
                    int over = 1;
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x + 1, y - 1, &over);
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x + 1, y + 1, &over);
                }
                if (k == '0' && y == 1 && x > 1 && x < ROW)
                {
                    int over = 1;
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x - 1, y + 1, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x + 1, y + 1, &over);
                }
                if (k == '0' && x == ROW && y > 1 && y < COL)
                {
                    int over = 1;
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x, y + 1, &over);
                    move(mine, show, x - 1, y - 1, &over);
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x - 1, y + 1, &over);
                }
                if (k == '0' && y == COL && x > 1 && x < ROW)
                {
                    int over = 1;
                    move(mine, show, x - 1, y, &over);
                    move(mine, show, x + 1, y, &over);
                    move(mine, show, x - 1, y - 1, &over);
                    move(mine, show, x, y - 1, &over);
                    move(mine, show, x + 1, y - 1, &over);
                }
                // diffusion(mine, show, ROW, COL);
                // DisplayBoard(show, ROW, COL);
            }
        }
    }
}
void JudgeWinner(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int *over)
{
    int i = 0;
    int k = 1;
    for (i = 1; i <= row; i++)
    {
        int j = 0;
        for (j = 1; j <= col; j++)
        {
            if (mine[i][j] == '0')
            {
                if (show[i][j] == '#')
                {
                    k = 0;
                    break;
                }
            }
            if (i == row && j == col && k == 1)
            {
                printf("恭喜你，你赢了！\n");
                DisplayBoard(mine, ROW, COL);
                printf("\n");
                *over = 0;
                sleep(2);
                break;
            }
        }
    }
}
void game()
{
    // 布置雷的位置
    char mine[ROWS][COLS] = {0};
    // 排查雷的位置
    char show[ROWS][COLS] = {0};
    // 初始化棋盘
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '#');
    // 打印棋盘
    // DisplayBoard(show, ROW, COL);
    // DisplayBoard(mine, ROW, COL);
    // 布置雷
    setMine(mine, ROW, COL, easy_mine);
    // 打印棋盘
    DisplayBoard(show, ROW, COL);
    // printf("\n");
    // DisplayBoard(mine, ROW, COL);
    int over = 1;
    do
    {
        printf("请输入位置>");
        int i = 0;
        int j = 0;
        scanf("%d%d", &i, &j);
        // 判断坐标是否合法
        if (i < 1 || i > ROW || j < 1 || j > COL)
        {
            printf("坐标非法，请重新输入\n");
            continue;
        }
        else if (show[i][j] != '#')
        {
            printf("该位置已经被占用，请重新输入\n");
            continue;
        }
        move(mine, show, i, j, &over);
        JudgeWinner(mine, show, ROW, COL, &over); // 判断是否获胜
        DisplayBoard(show, ROW, COL);
    } while (over);
}
int main()
{
    int input = 0;
    do
    {
        printf("****************************\n");
        printf("*****  1.play  2.exit  *****\n");
        printf("****************************\n");
        printf("请选择>");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("开始运行\n");
            game();
        }
        else if (input != 1 && input != 2)
        {
            printf("输入非法，请重新输入\n");
        }
    } while (input != 2);
    printf("游戏结束\n");
    return 0;
}