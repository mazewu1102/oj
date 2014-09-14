#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i < n / 2; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool judge(int n, int d)
{
    int len = 0;
    stack<int> si;
    for (; n != 0; ++len, n /= d)
        si.push(n % d);
    int reverse = 0;
    int t = 1;
    while (!si.empty())
    {
        reverse += t*si.top();
        si.pop();
        t *= d;
    }
    return is_prime(reverse);
}

int main()
{
    for (;;)
    {
        int n, d;
        scanf("%d", &n);
        if (n < 0)
            break;
        scanf("%d", &d);
        if (judge(n, d))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

