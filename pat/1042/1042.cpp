#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <string>
#include <algorithm>

#include <stack>
#include <queue>
#include <map>

using namespace std;

const char pre[5] = {'S', 'H', 'C', 'D', 'J'};

struct Poke
{
    int a;
    int b;
};

bool cmp(const Poke& x, const Poke& y)
{
    return x.a < y.a;
}


int main()
{
    int n;
    Poke poke[54];
    int order[54];
    scanf("%d", &n);
    for (int i = 0; i < 54; ++i)
    {
        scanf("%d", order+i);
        poke[i].b = i;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 54; ++j)
            poke[j].a = order[j];
        sort(poke, poke+54, cmp);
    }
    for (int i = 0; i < 54; ++i)
    {
        int t1 = poke[i].b % 13;
        int t2 = poke[i].b / 13;
        printf("%c%d", pre[t2], t1+1);
        if (i == 53)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
