#include <stdio.h>

int main()
{
    // 1 2 3 4 0
    // 7 8 9 9 5
    // 0 0 0 0 0
    int arr[3][5] = {{1, 2, 3, 4}, {7, 8, 9, 9, 5}};
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
}