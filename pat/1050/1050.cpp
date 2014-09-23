#include <cstdio>
#include <cstdlib>

#include <iostream>

using namespace std;

int main()
{
    char s1[10000];
    short s2[200] = {0};
    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != '\n')
    {
        s1[i++] = c;
        scanf("%c", &c);
    }
    s1[i] = 0;
    scanf("%c", &c);
    while (c != '\n')
    {
        s2[(unsigned int)c] = 1;
        scanf("%c", &c);
    }
    i = 0;
    while (s1[i] != 0)
    {
        if (s2[(unsigned int)(s1[i])] == 0)
            printf("%c", s1[i]);
        ++i;
    }
    printf("\n");
    return 0;
}
