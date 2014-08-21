#include <cstdio>
#include <cstring>

int main()
{
    long a, b;
    char c[100];
    scanf("%ld%ld", &a, &b);
    sprintf(c, "%ld", a+b);
    long len = strlen(c);
    for (long i = 0; i < len; ++i)
    {
        if (0 == i || '-' == c[i-1] || (len-i)%3 != 0)
            printf("%c", c[i]);
        else 
            printf(",%c", c[i]);
    }
    printf("\n");
    return 0;
}

