#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    char c;
    scanf("%d", &n);
    scanf("%c", &c);
    stack<char> ss[100]; 
    stack<char> sr;
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &c);
        while (c != '\n')
        {
            ss[i].push(c);
            scanf("%c", &c);
        }
    }
    while (!ss[0].empty())
    {
        bool tag = true;
        bool flg = true;
        int t = ss[0].top();
        ss[0].pop();
        for (int i = 1; i < n; ++i)
        {
            if (ss[i].empty())
            {
                flg = false;
                break;
            }
            if (t != ss[i].top())
            {
                tag = false;
                break;
            }
            ss[i].pop();
        }
        if (!flg)
            break;
        if (tag)
            sr.push(t);
        else
            break;
    }
    if (sr.empty())
        printf("nai\n");
    else
    {
        while (!sr.empty())
        {
            printf("%c", sr.top());
            sr.pop();
        }
        printf("\n");
    }
    return 0;
}

