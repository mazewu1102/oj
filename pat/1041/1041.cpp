#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <string>

#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> m;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        q.push(t);
        if (m.find(t) == m.end())
            m[t] = 1;
        else
            m[t]++;
    }

    bool tag = true;
    while (!q.empty())
    {
        if (m[q.front()] == 1)
        {
            printf("%d\n", q.front());
            tag = false;
            break;
        }
        q.pop();
    }
    if (tag)
        printf("None\n");
    return 0;
}

