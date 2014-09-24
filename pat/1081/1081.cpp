#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    while (b != 0)
    {
        long long int c = a % b;
        a = b;
        b = c; 
    }
    return a;
}

int main()
{
    int n;
    vector<long long int> va, vb;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int t1, t2;
        scanf("%d/%d", &t1, &t2);
        va.push_back(t1);
        vb.push_back(t2);
    }
    long long int common = 1;
    for (vector<long long int>::iterator iter = vb.begin();
            iter != vb.end(); ++iter)
        common = common * (*iter) / gcd(common, *iter);
    long long int sum = 0;
    for (vector<long long int>::iterator iter_a = va.begin(), iter_b = vb.begin();
            iter_a != va.end(); ++iter_a, ++iter_b)
    {
        long long int t = common / *iter_b;
        sum += t * (*iter_a); 
    }
    long long int t = gcd(abs(sum), common);
    sum /= t;
    common /= t;
    if (sum > common)
    {
        long long int x = sum / common;
        long long int y = sum % common;
        printf("%lld", x);
        if (y != 0)
            printf(" %lld/%lld", y, common);
        printf("\n");
    }
    else
    {
        if (sum != 0)
            printf("%lld/%lld", sum, common);
        else
            printf("0");
        printf("\n");
    }
    return 0;
}

