#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    if (s.length() % 2 == 1)
        return -1;
    int l = 0, r = 0;
    int c = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '{')
            l++;
        else
            r++;
        if (r > l)
        {
            c += r - l;
            swap(r, l);
        }
    }
    c += (abs(r - l)) / 2;
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
    return 0;
}
