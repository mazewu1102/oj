#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

#include <stack>
#include <queue>

using namespace std;

struct Person
{
    char usr[20];
    char psw[20];
};

bool change(Person& p)
{
    bool tag = false;
    int len = strlen(p.psw);
    for (int i = 0; i < len; ++i)
        switch (p.psw[i])
        {
        case '1':
            p.psw[i] = '@';
            tag = true;
            break;
        case '0':
            p.psw[i] = '%';
            tag = true;
            break;
        case 'l':
            p.psw[i] = 'L';
            tag = true;
            break;
        case 'O':
            p.psw[i] = 'o';
            tag = true;
            break;
        }
    return tag;
}

int main()
{
    int n;
    scanf("%d", &n);
    queue<Person> q;
    for (int i = 0; i < n; ++i)
    {
        Person t;
        scanf("%s %s", t.usr, t.psw);
        if (change(t))
            q.push(t);
    }
    int size = q.size();
    if (size == 0)
    {
        if (n == 1)
            printf("There is %d account and no account is modified\n", n);
        else
            printf("There are %d account and no account is modified\n", n);
    }
    else
    {
        printf("%d\n", size);
        while (!q.empty())
        {
            Person t = q.front();
            printf("%s %s\n", t.usr, t.psw);
            q.pop();
        }
    }
    return 0;
}


