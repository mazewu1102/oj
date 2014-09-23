#include <cstdio>
#include <iostream>

using namespace std;

const char Week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    char w[100];
    char h[100];
    char m1[100];
    char m2[100];
    scanf("%s%s%s%s", w, h, m1, m2);
    int i = 0;
    while (w[i] != 0 && h[i] != 0)
    {
        if (w[i] == h[i] && w[i] <= 'G' && w[i] >= 'A')
        {
            printf("%s ", Week[w[i]-'A']);
            ++i;
            break;
        }
        ++i;
    }
    while (w[i] != 0 && h[i] != 0)
    {
        if (w[i] == h[i] && ((w[i] <= 'N' && w[i] >= 'A') || (w[i] <= '9' && w[i] >= '0')))
            break;
        ++i;
    }
    if (w[i] >= 'A' && w[i] <= 'N')
        printf("%d", w[i]-'A'+10);
    else if (w[i] >= 'a' && w[i] <= 'n')
        printf("%d", w[i]-'a'+10);
    else
        printf("0%c", w[i]);
    i = 0;
    while (m1[i] != 0 && m2[i] != 0)
    {
        if (m1[i] == m2[i] && ((m1[i] >= 'A' && m1[i] <= 'Z') || (m1[i] >= 'a' && m1[i] <= 'z')))
            break;
        ++i;
    }
    if (i < 10)
        printf(":0%d\n", i);
    else
        printf(":%d\n", i);
    return 0;
}
