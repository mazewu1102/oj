#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <iostream>

#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        bool flg = true;
        long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        cout << a << " " << b << endl;
        long res = a + b;
        if(a > 0 && b > 0 && res <= 0)
            flg = true;  
        else if(a < 0 && b < 0 && res >= 0)
            flg = false;  
        else if (res <= c)
            flg = false;  
        
        if (flg)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
