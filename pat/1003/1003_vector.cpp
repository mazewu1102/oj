#include <cstdio>
#include <vector>

const int  MAXNUM = 500;
const int MAXINT = 999999999;

int count = 0;
int min_path = MAXINT;
int max_hands = 0;
int man[MAXNUM] = {0};
bool mask[MAXNUM] = {false};
std::vector< std::pair<int, int> > map[MAXNUM];

void short_path(int v, int u, int len, int hands)
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
    //for (int i = 0; i < map[v].size(); ++i)
    for (std::vector< std::pair<int, int> >::iterator iter = map[v].begin();
            iter != map[v].end(); ++iter)
    {
        if (!mask[iter->first])
        {
            mask[iter->first] = true;
            short_path(iter->first, u, len+iter->second, hands+man[iter->first]);
            mask[iter->first] = false;
        }
    }
}

int main()
{
    int c1, c2;
    int n, m;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i)
        scanf("%d", man+i);
    for (int i = 0; i < m; ++i)
    {
        int x, y, len;
        scanf("%d%d%d", &x, &y, &len);
        map[x].push_back(std::make_pair(y, len));
        map[y].push_back(std::make_pair(x, len));
    }
    
    short_path(c1, c2, 0, man[c1]);
    printf("%d %d\n", count, max_hands);
    return 0;
}
