#include <cstdio>

void dijkstra(int n, int v, int *dist, int *prev, int map[MAXNUM][MAXNUM])
{
    bool mask[MAXNUM] = {false};
    for (int i = 0; i < n; ++i)
    {
        dist[i] = map[v][i];
        prev[i] = (dist[i] == MAXINT ? 0 : v);
    }
    dist[v] = 0;
    mask[v] = true;

    for (int i = 1; i < n; ++i)
    {
        int min = MAXINT;
        int u = v;
        for (int j = 0; j < n; ++j)
        {
            if (!mask[j] && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
        }
        mask[u] = true;
        for (int j = 0; j < n; ++j)
        {
            if (!mask[j] && map[u][j] < MAXINT)
            {
                int update = dist[u] + map[u][j];
                if (update < dist[j])
                {
                    dist[j] = update;
                    prev[j] = u;
            }
        }
    }
}

