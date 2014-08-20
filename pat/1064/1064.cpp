#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int get_root(int l, int r)
{
    int t = (int)pow((int)sqrt(r-l), 2) - 1;
    return t/2 + r - l + 2 - t;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int *data = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", data+i);
    int root = get_root(0, n-1);
    printf("%d", root);
    queue<int> seq;
    stack<int> range;
    seq.push(data[root]);
    range.push(0);
    range.push(root-1);
    range.push(root+1);
    range.push(n-1);
//range.empty();
printf("%lu", range.size());
    while (!range.empty())
    {
        printf("test");
        int l = range.top();
        range.pop();
        int r = range.top();
        range.pop();
        root = get_root(l, r);
        seq.push(data[root]);
        if (l < r)
        {
            range.push(l);
            range.push(root-1);
            range.push(root+1);
            range.push(r);
        }
        else if (l == r)
            seq.push(data[r]);
        return 0;
    }
    
    return 0;
    while (true)
    {
        int res = seq.front();
        seq.pop();
        if (1 == seq.size())
        {
            printf("%d", res);
            break;
        }
        else
            printf("%d ", res);
    }
    delete [] data;
    return 0;
}
