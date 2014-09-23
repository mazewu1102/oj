#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int m, n;
    map<int, int> mp;
    scanf("%d%d", &m, &n);
    n *= m;
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        if (mp.find(t) == mp.end())
            mp[t] = 1;
        else
            mp[t]++;
    }
    int max_n = -1;
    int pixel;
    for (map<int, int>::iterator iter = mp.begin(); 
            iter != mp.end(); ++iter)
    {
        if (iter->second > max_n)
        {
            pixel = iter->first;
            max_n = iter->second;
        }
    }
    printf("%d\n", pixel); 
    return 0;
}
