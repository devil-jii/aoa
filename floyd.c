#include <stdio.h>
#define V 4
#define INF 999

void printMatrix(int dist[V][V])
{
    int i, j;

    printf("\nDistance Matrix:\n\n");
    printf(" ");

    for (j = 0; j < V; j++)
        printf("%5d", j);

    printf("\n");

    for (i = 0; i < V; i++)
    {
        printf("%5d", i);

        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }

        printf("\n");
    }
}

void waitForEnter()
{
    printf("\nPress ENTER to start the next iteration...");
    getchar();
}

void floydWarshall(int dist[V][V])
{
    int i, j, k;
    int newDistance;

    printf("\n====================================");
    printf("\n FLOYD-WARSHALL ALGORITHM");
    printf("\n====================================");
    printf("\n\nInitial Matrix:");

    printMatrix(dist);

    for (k = 0; k < V; k++)
    {
        waitForEnter();

        printf("\n\n====================================");
        printf("\nITERATION %d", k + 1);
        printf("\nIntermediate Vertex = %d", k);
        printf("\n====================================\n");

        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    newDistance = dist[i][k] + dist[k][j];

                    printf("\nChecking [%d][%d]\n", i, j);
                    printf("Via Vertex %d : %d + %d = %d\n",
                           k, dist[i][k], dist[k][j], newDistance);

                    if (newDistance < dist[i][j])
                    {
                        printf("Update : %d -> %d\n",
                               dist[i][j], newDistance);

                        dist[i][j] = newDistance;
                    }
                    else
                    {
                        printf("No update required\n");
                    }
                }
            }
        }

        printf("\nMatrix after Iteration %d:", k + 1);
        printMatrix(dist);
    }

    printf("\n\n====================================");
    printf("\n FINAL SHORTEST PATH MATRIX");
    printf("\n====================================");

    printMatrix(dist);

    for (i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            printf("\nNegative Weight Cycle Exists!\n");
            return;
        }
    }

    printf("\n\nNo Negative Weight Cycle Found.\n");
}

int main()
{
    int graph[V][V] =
    {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}