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
    // �����������ʼ�������������
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
    int count = easy;                // ���õ�������
    srand((unsigned int)time(NULL)); //  ��ʼ���������������ʹ�õ�ǰʱ����Ϊ����
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
                printf("���ź����㱻ը����\n");
                DisplayBoard(mine, ROW, COL);
                printf("\n");
                *over = 0;
                sleep(2);
            }
            else if (mine[x][y] == '0')
            { // �������ڵ��׵�����������ת��Ϊ�ַ���ʾ,����+ '0'ת�����ַ�
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
                printf("��ϲ�㣬��Ӯ�ˣ�\n");
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
    // �����׵�λ��
    char mine[ROWS][COLS] = {0};
    // �Ų��׵�λ��
    char show[ROWS][COLS] = {0};
    // ��ʼ������
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '#');
    // ��ӡ����
    // DisplayBoard(show, ROW, COL);
    // DisplayBoard(mine, ROW, COL);
    // ������
    setMine(mine, ROW, COL, easy_mine);
    // ��ӡ����
    DisplayBoard(show, ROW, COL);
    // printf("\n");
    // DisplayBoard(mine, ROW, COL);
    int over = 1;
    do
    {
        printf("������λ��>");
        int i = 0;
        int j = 0;
        scanf("%d%d", &i, &j);
        // �ж������Ƿ�Ϸ�
        if (i < 1 || i > ROW || j < 1 || j > COL)
        {
            printf("����Ƿ�������������\n");
            continue;
        }
        else if (show[i][j] != '#')
        {
            printf("��λ���Ѿ���ռ�ã�����������\n");
            continue;
        }
        move(mine, show, i, j, &over);
        JudgeWinner(mine, show, ROW, COL, &over); // �ж��Ƿ��ʤ
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
        printf("��ѡ��>");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("��ʼ����\n");
            game();
        }
        else if (input != 1 && input != 2)
        {
            printf("����Ƿ�������������\n");
        }
    } while (input != 2);
    printf("��Ϸ����\n");
    return 0;
}