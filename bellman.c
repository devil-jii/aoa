#include <stdio.h>
#include <limits.h>

#define V 5
#define E 6

struct Edge
{
    int src;
    int dest;
    int wt;
};

void printDist(int dist[])
{
    int i;

    printf("\nDistance Array: ");

    for (i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");
}

void waitForEnter()
{
    printf("\nPress ENTER to start next iteration...");
    getchar();
}

void bellmanFord(struct Edge edge[], int source)
{
    int dist[V];
    int i, j;

    for (i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    printf("\n========================");
    printf("\nBELLMAN FORD ALGORITHM");
    printf("\n========================");

    printDist(dist);

    for (i = 1; i <= V - 1; i++)
    {
        waitForEnter();

        printf("\n========================");
        printf("\nITERATION %d", i);
        printf("\n========================");

        for (j = 0; j < E; j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            int wt = edge[j].wt;

            printf("\nChecking Edge %d -> %d (Weight=%d)\n",
                   u, v, wt);

            if (dist[u] == INT_MAX)
            {
                printf("Vertex %d is not reachable.\n", u);
                continue;
            }

            printf("Calculation: %d + (%d) = %d\n",
                   dist[u], wt, dist[u] + wt);

            if (dist[u] + wt < dist[v])
            {
                printf("Relaxation Performed\n");
                printf("Distance[%d]: ", v);

                if (dist[v] == INT_MAX)
                    printf("INF");
                else
                    printf("%d", dist[v]);

                dist[v] = dist[u] + wt;

                printf(" -> %d\n", dist[v]);
            }
            else
            {
                printf("No Relaxation Required\n");
            }
        }

        printf("\nAfter Iteration %d", i);
        printDist(dist);
    }

    printf("\n========================");
    printf("\nFINAL SHORTEST PATHS");
    printf("\n========================");

    for (i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("\nVertex %d : INF", i);
        else
            printf("\nVertex %d : %d", i, dist[i]);
    }

    printf("\n");
}

int main()
{
    struct Edge edge[E] =
    {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, -4},
        {1, 4, -1},
        {2, 3, 2},
        {4, 3, -3}
    };

    bellmanFord(edge, 0);

    return 0;
}