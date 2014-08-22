#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    float pn[1001] = {0};
    int k;
    int m = -1;
    stack<int> st;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        int a;
        scanf("%d", &a);
        scanf("%f", pn+a);
        m = m > a ? m : a;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        int a;
        float b;
        scanf("%d%f", &a, &b);
        pn[a] += b;
        m = m > a ? m : a;
    }
    for (int i = 0; i <= m; ++i)
    {
        if (pn[i] != 0)
            st.push(i);
    }
    printf("%d", (int)st.size());
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        printf(" %d %.1f", top, pn[top]);
    }
    printf("\n");
    return 0;
}
