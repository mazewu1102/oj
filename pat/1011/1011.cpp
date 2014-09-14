#include <iostream>
#include <cmath>

using namespace std;

int max_index(const float* s)
{
    int tmp = s[0] > s[1] ? 0 : 1;
    return s[tmp] > s[2] ? tmp : 2;
}

const char TAG[3] = {'W', 'T', 'L'};

int main()
{
    float score[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            scanf("%f", score[i]+j);
    }
    float p = 0.65;
    for (int i = 0; i < 3; ++i)
    {
        int t = max_index(score[i]);
        printf("%c ", TAG[t]);
        p *= score[i][t];
    }
    p = (p-1)*2;
    printf("%.2f\n", ceil(p*100)/100);
    return 0;
}

