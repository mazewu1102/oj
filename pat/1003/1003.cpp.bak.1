#include <cstdio>

const int  MAXNUM = 500;
const int MAXINT = 999999999;
/*void dijkstra(int n, int v, int *dist, int *prev, int map[MAXNUM][MAXNUM])
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
}*/

/*void short_path(int n, int v, int u, int map[MAXNUM][MAXNUM])
{
    stack<int> st;
    int mask[MAXNUM] = {0};
    int min = MAXINT;
    mask[v] = 1;
    st.push(v);
    while (!st.empty())
    {
        int c = st.top();
        st.pop();
        for (int i = 0; i < n; ++i)
        {
            if (i == u){}
            else if (!mask[i] && map[c][i] < MAXINT)
            {
                st.push(i);
            }
        }
    }
}*/


int count = 0;
int min_path = MAXINT;
int max_hands = 0;
int map[MAXNUM][MAXNUM];
int man[MAXNUM] = {0};
bool mask[MAXNUM] = {false};

void short_path(int n, int v, int u, int len, int hands)
{
    
    if (v == u)
    {
        if (len == min_path)
        {
            ++count;
            max_hands = max_hands > hands ? max_hands : hands;
        }
        else if (len < min_path)
        {
            count = 1;
            min_path = len;
            max_hands = hands;
        }
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!mask[i] && map[v][i] < MAXINT)
        {
            mask[i] = true;
            short_path(n, i, u, len+map[v][i], hands+man[i]);
            mask[i] = false;
        }
    }
}

int main()
{
    int c1, c2;
    int n, m;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            map[i][j] = MAXINT;
    for (int i = 0; i < n; ++i)
        scanf("%d", man+i);
    for (int i = 0; i < m; ++i)
    {
        int x, y, len;
        scanf("%d%d%d", &x, &y, &len);
        map[x][y] = len;
        map[y][x] = len;
    }
    
    short_path(n, c1, c2, 0, man[c1]);
    printf("%d %d\n", count, max_hands);
    return 0;
}
