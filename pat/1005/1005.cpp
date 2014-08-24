#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const char trans[10][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"};

int main()
{
    int sum = 0;
    char r[101];
    scanf("%s", r);
    int len = strlen(r);
    for (int i = 0; i < len; ++i)
        sum += r[i]-'0';
    sprintf(r, "%d", sum);
    len = strlen(r);
    for (int i = 0; i < len - 1; ++i)
        printf("%s ", trans[r[i]-'0']);
    printf("%s\n", trans[r[len-1]-'0']);
    return 0;
}

