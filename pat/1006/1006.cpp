#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Person
{
public:
    Person(char* _id, int _begin, int _end)
        :begin(_begin), end(_end)
    {
        strcpy(id, _id);
    }
public:
    char id[20];
    int begin;
    int end;
};

int main()
{
    int n;
    scanf("%d", &n);
    int min = 86401;
    int max = -1;
    char unlock[20];
    char lock[20];
    for (int i = 0; i < n; ++i)
    {
        char id[20];
        int bh, bm, bs;
        int eh, em, es;
        scanf("%s%d:%d:%d %d:%d:%d", id, &bh, &bm, &bs, &eh, &em, &es);
        int b = bh*3600+bm*60+bs;
        int e = eh*3600+em*60+es;
        if (b < min)
        {
            min = b;
            strcpy(unlock, id);
        }
        if (e > max)
        {
            max = e;
            strcpy(lock, id);
        }
    }
    printf("%s %s\n", unlock, lock);
    return 0;
}
