#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    vector<int> ve;
    ve.push_back(0);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        sum += t;
        ve.push_back(sum);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        int t1 = min(n1, n2);
        int t2 = max(n1, n2);
        int dis = ve[t2-1] - ve[t1-1];
        printf("%d\n", dis < sum - dis ? dis : sum - dis);
    }

    return 0;
}
