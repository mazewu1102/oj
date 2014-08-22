#include <cstdio>

const int  MAXNUM = 500;
const int MAXINT = 999999999;

class Node
{
public:
    Node():next(NULL){}
    Node(int _city, int _len):
        city(_city), len(_len), next(NULL){}
public:
    int city;
    int len;
    Node *next;
};

class City
{
public:
    City():first(NULL){}
    void insert(int _city, int _len)
    {
        if (first == NULL)
            first = new Node(_city, _len);
        else
        {
            Node *p = first;
            while (p->next != NULL)
                p = p->next;
            p->next = new Node(_city, _len);
        }

    }
    ~City()
    {
        Node *p = first;
        while (p != NULL)
        {
            Node *q = p->next;
            delete p;
            p = q;
        }
    }
public:
    int hands;
    Node *first;
};


int count = 0;
int min_path = MAXINT;
int max_hands = 0;
City map[MAXNUM];
bool mask[MAXNUM] = {false};

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
    for (Node *p = map[v].first; p != NULL; p = p->next)
    {
        if (!mask[p->city])
        {
            mask[p->city] = true;
            short_path(p->city, u, len+p->len, hands+map[p->city].hands);
            mask[p->city] = false;
        }
    }
}


int main()
{
    int c1, c2;
    int n, m;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i)
        scanf("%d", &(map[i].hands));
    for (int i = 0; i < m; ++i)
    {
        int x, y, len;
        scanf("%d%d%d", &x, &y, &len);
        map[x].insert(y, len);
        map[y].insert(x, len);
    }
    
    short_path(c1, c2, 0, map[c1].hands);
    printf("%d %d\n", count, max_hands);
    return 0;
}
