#include <stdio.h>

#define MAX 100

typedef struct
{
    int u, v, w;
} Edge;

Edge edge[MAX];
int parent[MAX];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void kruskal(int n, int m)
{
    int i, count = 0, sum = 0;

    for (i = 1; i <= n; i++)
        parent[i] = i;

    for (i = 0; i < m; i++)
    {
        int pu = find(edge[i].u);
        int pv = find(edge[i].v);

        if (pu != pv)
        {
            parent[pv] = pu;

            printf("Chon canh (%d,%d) = %d\n",
                   edge[i].u, edge[i].v, edge[i].w);

            sum += edge[i].w;
            count++;

            if (count == n - 1)
                break;
        }
    }

    printf("Tong trong so = %d\n", sum);
}

int main()
{
    int n = 6, m = 5;

    edge[0] = (Edge){1, 3, 1};
    edge[1] = (Edge){6, 4, 2};
    edge[2] = (Edge){2, 5, 3};
    edge[3] = (Edge){3, 6, 4};
    edge[4] = (Edge){3, 2, 5};

    kruskal(n, m);

    return 0;
}