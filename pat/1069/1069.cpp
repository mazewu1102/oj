#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char x[5];
    scanf("%s", x);
    int n = 0;
    int m;
    bool tag = true;
    sscanf(x, "%d", &m);
    if (strlen(x) == 4)
    {
        for (int i = 1; i < 4; ++i)
        {
            if (x[i] != x[0])
                tag = false;
        }
        if (tag)
        {
            printf("%0.4d - %0.4d = 0000\n", m, m);
            return 0;
        }
    }
    for (int i = strlen(x); i < 4; ++i)
        x[i] = '0';
    x[4] = 0;

    while (n != 1)
    {
        int a, b;
        sort(x, x+4, greater<char>());
        sscanf(x, "%d", &a);
        sort(x, x+4, less<char>());
        sscanf(x, "%d", &b);
        m = a - b;
        printf("%0.4d - %0.4d = %0.4d\n", a, b, m);
        if (m == 6174)
            n++;
        sprintf(x, "%0.4d", m);
    }
    return 0;
}
