#include <iostream>
#include <queue>

using namespace std;

bool in_vector(const vector<char>& v, char c)
{
    for (vector<char>::const_iterator iter = v.begin();
            iter != v.end(); ++iter)
        if (*iter == c)
            return true;
    return false;
}

int main()
{
    queue<char> s;
    vector<char> v;
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        if (c <= 'z' && c >= 'a')
            c = c - 'a' + 'A';
        s.push(c);
        scanf("%c", &c);
    }
    scanf("%c", &c);
    while (c != '\n')
    {
        if (c <= 'z' && c >= 'a')
            c = c - 'a' + 'A';
        while (!s.empty() && s.front() != c)
        {
            if (!in_vector(v, s.front()))
                v.push_back(s.front());
            s.pop();
        }
        if (!s.empty())
            s.pop();
        scanf("%c", &c);
    }
    for (vector<char>::iterator iter = v.begin();
            iter != v.end(); ++iter)
        cout << *iter;
    cout << endl;
    return 0;
}
