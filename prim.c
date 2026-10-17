#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void displayStatus(int key[], int parent[], bool mstSet[])
{
    int i;

    printf("\nVertex\tKey\tParent\tMST_Set\n");

    for (i = 0; i < V; i++)
    {
        printf("%d\t", i);

        if (key[i] == INT_MAX)
            printf("INF\t");
        else
            printf("%d\t", key[i]);

        if (parent[i] == -1)
            printf("-\t");
        else
            printf("%d\t", parent[i]);

        printf("%s\n", mstSet[i] ? "YES" : "NO");
    }
}

void printMST(int parent[], int graph[V][V])
{
    int total = 0;

    printf("\n\nFINAL MST\n");
    printf("Edge\tWeight\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d-%d\t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("\nTotal Cost = %d\n", total);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    int i, count, v;

    for (i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    printf("\nINITIAL STATUS");
    displayStatus(key, parent, mstSet);

    for (count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        printf("\n\nSTEP %d\n", count + 1);
        printf("Selected Vertex = %d\n", u);

        for (v = 0; v < V; v++)
        {
            if (graph[u][v] &&
                mstSet[v] == false &&
                graph[u][v] < key[v])
            {
                printf("\nUpdating Vertex %d", v);

                printf("\nOld Key = ");
                if (key[v] == INT_MAX)
                    printf("INF");
                else
                    printf("%d", key[v]);

                printf("\nNew Key = %d", graph[u][v]);
                printf("\nParent[%d] = %d\n", v, u);

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }

        displayStatus(key, parent, mstSet);

        if (count < V - 2)
        {
            printf("\nPress ENTER for next step...");
            getchar();
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 0, 0, 4},
        {2, 0, 8, 0, 0, 3},
        {0, 8, 0, 6, 1, 0},
        {0, 0, 6, 0, 12, 0},
        {0, 0, 1, 12, 0, 2},
        {4, 3, 0, 0, 2, 0}
    };

    primMST(graph);

    return 0;
}