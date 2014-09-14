#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const char Tag[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void to_mars(int n, char *s)
{
    s[0] = Tag[n/13];
    s[1] = Tag[n%13];
    s[2] = 0;
}

int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    char s[3];
    printf("#");
    to_mars(r, s);
    printf("%s", s);
    to_mars(g, s);
    printf("%s", s);
    to_mars(b, s);
    printf("%s\n", s);
    return 0;
}

