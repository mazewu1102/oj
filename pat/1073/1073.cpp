#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char c;
    int e;
    bool flg = true;
    vector<char> vc;
    vector<char> vr;
    scanf("%c", &c);
    if (c == '-')
        printf("%c", c);
    scanf("%c", &c);
    while (c != 'E')
    {
        if (c != '.')
            vc.push_back(c);
        scanf("%c", &c);
    }
    scanf("%c", &c);
    if (c == '-')
        flg = false;
    scanf("%d", &e);
    
    
    if (e == 0) 
    {
        printf("%c.", *vc.begin());
        for (vector<char>::iterator iter = vc.begin() + 1;
                iter != vc.end(); ++iter)
            printf("%c", *iter);
    }
    else if (flg)
    {
        bool tag = true;
        int point = e + 1;
        e -= vc.size()-1;
        int i = 0;
        for (; i < vc.size(); ++i)
        {
            if (i == point)
                printf(".");
            if (vc[i] == '0')
            {
                if (!tag)
                    printf("0");
                else if (i == point - 1)
                {
                    printf("0");
                    tag = false;
                }
            }
            else
            {
                printf("%c", vc[i]);
                tag = false;
            }
        }
        while (e > 0)
        {
            if (i == point)
                printf(".");
            printf("0");
            ++i;
            --e;
        }
    }
    else
    {
        printf("0.");
        while (e != 1)
        {
            printf("0");
            --e;
        }
        for (vector<char>::iterator iter = vc.begin();
                iter != vc.end(); ++iter)
            printf("%c", *iter);
    }
    printf("\n");

    return 0;
}
