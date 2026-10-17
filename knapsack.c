#include <stdio.h>
#define MAX 20

void waitForEnter()
{
    printf("\nPress ENTER to start the next iteration...");
    getchar();
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void printTable(int dp[MAX + 1][MAX + 1], int n, int capacity)
{
    int i, w;

    printf("\n\nDP TABLE:\n\n");
    printf("Item/Cap ");

    for (w = 0; w <= capacity; w++)
        printf("%4d", w);

    printf("\n");

    for (i = 0; i <= n; i++)
    {
        printf("%8d", i);

        for (w = 0; w <= capacity; w++)
            printf("%4d", dp[i][w]);

        printf("\n");
    }
}

void knapsack(int weight[], int profit[], int n, int capacity)
{
    int dp[MAX + 1][MAX + 1];
    int i, w, include, exclude;

    for (i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (w = 0; w <= capacity; w++)
        dp[0][w] = 0;

    printf("\n========================================");
    printf("\n 0/1 KNAPSACK PROBLEM");
    printf("\n========================================");

    for (i = 1; i <= n; i++)
    {
        waitForEnter();

        printf("\n\n========================================");
        printf("\nITERATION %d", i);
        printf("\nItem %d: Weight = %d, Profit = %d",
               i, weight[i - 1], profit[i - 1]);
        printf("\n========================================\n");

        for (w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                include = profit[i - 1] +
                          dp[i - 1][w - weight[i - 1]];

                exclude = dp[i - 1][w];

                printf("\nCapacity %d:", w);
                printf("\nInclude Item %d = %d", i, include);
                printf("\nExclude Item %d = %d", i, exclude);

                dp[i][w] = max(include, exclude);

                printf("\nSelected Value = %d\n", dp[i][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];

                printf("\nCapacity %d: Item %d is too heavy",
                       w, i);
                printf("\nValue copied = %d\n", dp[i][w]);
            }
        }

        printf("\nTable after Iteration %d:", i);
        printTable(dp, n, capacity);
    }

    printf("\n\n========================================");
    printf("\n FINAL RESULT");
    printf("\n========================================");
    printf("\nMaximum Profit = %d\n", dp[n][capacity]);

    printf("\nSelected Items: ");
    w = capacity;

    for (i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("Item %d ", i);
            w = w - weight[i - 1];
        }
    }

    printf("\n");
}

int main()
{
    int weight[] = {2, 3, 4, 5};
    int profit[] = {3, 4, 5, 6};
    int n = 4;
    int capacity = 5;

    printf("Items:\n");
    printf("Item 1: Weight = 2, Profit = 3\n");
    printf("Item 2: Weight = 3, Profit = 4\n");
    printf("Item 3: Weight = 4, Profit = 5\n");
    printf("Item 4: Weight = 5, Profit = 6\n");

    printf("\nKnapsack Capacity = %d\n", capacity);

    knapsack(weight, profit, n, capacity);

    return 0;
}