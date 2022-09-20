#include <stdio.h>
#include <stdlib.h>
int check(int k[9][9][2], int i, int j)
{
    int temp, count = 0;
    temp = k[i][j][0];
    for (int a = 0; a < 9; a++)
    {
        if (k[a][j][0] == temp)
            count++;
    }
    if (count >= 2)
        return 0;
    count = 0;
    for (int a = 0; a < 9; a++)
    {
        if (k[i][a][0] == temp)
            count++;
    }
    if (count >= 2)
        return 0;
    count = 0;
    for (int a = (i / 3) * 3; a <= (i / 3) * 3 + 2; a++)
    {
        for (int b = (j / 3) * 3; b <= (j / 3) * 3 + 2; b++)
        {
            if (k[a][b][0] == temp)
                count++;
        }
    }
    if (count >= 2)
        return 0;
    else
        return 1;
}
void solve(int k[9][9][2], int i, int j)
{

    if (k[i][j][1] == 1)
    {
        if (j != 8)
            solve(k, i, j + 1);
        else if (i != 8)
            solve(k, i + 1, 0);
        if (i == 8 && j == 8)
        {
            printf("\n");
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                    printf("%d ", k[i][j][0]);
                printf("\n");
            }
            exit(0);
        }
    }
    for (int a = 1; a < 10; a++)
    {
        k[i][j][0] = a;
        if (check(k, i, j))
        {
            if (j != 8)
                solve(k, i, j + 1);
            else if (i != 8)
                solve(k, i + 1, 0);
            if (i == 8 && j == 8)
            {
                printf("\n");
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                        printf("%d ", k[i][j][0]);
                    printf("\n");
                }
                exit(0);
            }
        }
        if (a == 9)
        {
            k[i][j][0] = 0;
            return;
        }
    }
}
int main()
{
    int k[9][9][2];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &k[i][j][0]);
            if (k[i][j][0] != 0)
            {
                k[i][j][1] = 1;
            }
            else
                k[i][j][1] = 0;
        }
    }
    solve(k, 0, 0);
    printf("\n");
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //         printf("%d ", k[i][j][0]);
    //     printf("\n");
    // }
}
