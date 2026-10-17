#include <stdio.h>
#define MAX 20

int board[MAX][MAX];
int n;

void waitForEnter()
{
    printf("\nPress ENTER to continue...");
    getchar();
}

void printBoard()
{
    int i, j;

    printf("\nChessboard:\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

int isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

int solveNQueen(int row)
{
    int col;

    if (row == n)
    {
        printf("\nSolution Found!");
        printBoard();
        return 1;
    }

    for (col = 0; col < n; col++)
    {
        waitForEnter();

        printf("\nTrying Row %d, Column %d",
               row + 1, col + 1);

        if (isSafe(row, col))
        {
            printf("\nPosition is SAFE. Queen placed.");

            board[row][col] = 1;
            printBoard();

            if (solveNQueen(row + 1))
                return 1;

            board[row][col] = 0;

            printf("\nBacktracking: Queen removed.");
            printBoard();
        }
        else
        {
            printf("\nPosition is NOT SAFE.");
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter the value of N: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > MAX)
    {
        printf("Invalid value of N.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = 0;

    printf("\nN-QUEEN PROBLEM");
    printf("\nN = %d\n", n);

    if (!solveNQueen(0))
        printf("\nNo solution exists for N = %d.\n", n);

    return 0;
}