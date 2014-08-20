#include <cstdio>

int main()
{
    int n = 0;
    int cur = 0;
    int floor = 0;
    int time = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &floor);
        if (cur <= floor)
            time += (floor - cur) * 6;
        else
            time += (cur - floor) * 4;
        cur = floor;
    }
    printf("%d\n", time+n*5);
    return 0;
}

