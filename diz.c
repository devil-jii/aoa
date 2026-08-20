#include <stdio.h>

#define INF 999

void dijkstra(int n, int cost[10][10], int source)
{
    int dist[10], visited[10];
    int i, count = 1, min, nextNode;

    // Initialize arrays
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[source][i];
    }

    visited[source] = 1;
    dist[source] = 0;

    while (count < n)
    {
        min = INF;

        // Find minimum distance vertex
        for (i = 1; i <= n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances
        for (i = 1; i <= n; i++)
        {
            if (!visited[i] &&
                (min + cost[nextNode][i] < dist[i]))
            {
                dist[i] = min + cost[nextNode][i];
            }
        }

        count++;
    }

    printf("\nShortest distances from Vertex %d:\n", source);

    for (i = 1; i <= n; i++)
    {
        if (i != source)
        {
            printf("Vertex %d -> Vertex %d = %d\n",
                   source, i, dist[i]);
        }
    }
}

int main()
{
    int n, source;
    int cost[10][10];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix:\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter Source Vertex: ");
    scanf("%d", &source);

    dijkstra(n, cost, source);

    return 0;
}