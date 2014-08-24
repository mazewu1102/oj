#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void count_leaf(const vector<int> vf[100], queue<int>& leaf)
{
    queue<int> tree;
    tree.push(-1);
    tree.push(1);
    int cnt = -1;
    int last = 0;
    for (;;)
    {
       int r = tree.front();
       tree.pop();
       if (r == -1)
       {
           if (last == -1)break;
           leaf.push(cnt);
           cnt = 0;
           tree.push(-1);
       }
       else
       {
           if (vf[r].empty())
               cnt += 1;
           else
               for (vector<int>::const_iterator citer = vf[r].begin();
                        citer != vf[r].end(); ++citer)
                    tree.push(*citer);
       }
       last = r;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> vf[100];
    queue<int> leaf;
    for (int i = 0; i < m; ++i)
    {
        int k;
        int id;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j)
        {
            int child;
            scanf("%d", &child);
            vf[id].push_back(child); 
        }
    }
    count_leaf(vf, leaf);
    leaf.pop();
    while ((int)leaf.size() != 1)
    {
        printf("%d ", leaf.front());
        leaf.pop();
    }
    printf("%d\n", leaf.front());
    return 0;
}

