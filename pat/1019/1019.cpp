#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

bool judge(int *s, int len)
{
    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len-1-i])
            return false;
    return true;
}

int sep(int n, int d, int *s)
{
    stack<int> si;
    while (n != 0)
    {
        si.push(n%d);
        n /= d;
    }
    int i = 0;
    while (!si.empty())
    {
        s[i++] = si.top();
        si.pop();
    }
    return i;
}

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int s[100];
    int len = sep(n, d, s);
    if (judge(s, len))
        printf("Yes\n");
    else
        printf("No\n");
    for (int i= 0; i < len - 1; ++i)
        printf("%d ", s[i]);
    printf("%d\n", s[len-1]);
    return 0;
}
