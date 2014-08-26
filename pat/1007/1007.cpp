#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    vector<int> seq;
    for (int i = 0; i < k; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        seq.push_back(tmp);
    }

    int b = 0;
    int e = 0;
    int sum = -1;
    int tmp_s = 0;
    int tmp_b = 0;
    int tmp_e = 0;
    for (int i = 0; i < k; ++i)
    {
        if (tmp_s > 0)
        {
            tmp_s += seq[i];
            tmp_e = i;
        }
        else
        {
            tmp_s = seq[i];
            tmp_b = tmp_e = i;
        }
        if (sum < tmp_s)
        {
            sum = tmp_s;
            b = tmp_b;
            e = tmp_e;
        }
    }
    if (sum < 0)
        sum = 0;
    printf("%d %d %d\n", sum, seq[b], seq[e]);
    return 0;
}
