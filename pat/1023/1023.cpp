#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    int tag[10] = {0};
    char s[30];
    scanf("%s", s);
    int len = strlen(s);
    stack<int> q;
    int k = 0;
    for(int i = len - 1; i >= 0; --i)
    {
        int t = (int)(s[i]-'0');
        tag[t]++;
        t *= 2;
        int c = t%10 + k;
        q.push(c);
        tag[c]--;
        k = t / 10; 
    }
    if (k != 0)
        q.push(k);
    bool same = true;
    for (int i = 0; i < 10; ++i)
        if (tag[i] != 0)
        {
            same = false;
            break;
        }
    if (same)
        printf("Yes\n");
    else
        printf("No\n");
    while (q.size() > 1)
    {
       printf("%d", q.top());
       q.pop();
    }
    printf("%d\n", q.top());
    return 0;
}

