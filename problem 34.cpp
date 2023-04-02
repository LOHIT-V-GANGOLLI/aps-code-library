#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int n)
    {
        if (n <= 1)
            return s;
        int l = s.length();
        string *t = new string[n];
        int i = 0, c = 1;
        for (int j = 0; j < l; ++j)
        {
            t[i].push_back(s[j]);
            if (i == 0)
                c = 1;
            else if (i == n - 1)
                c = -1;
            i += c;
        }
        s.clear();
        for (int j = 0; j < n; ++j)
            s.append(t[j]);
        return s;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convert(str, n) << endl;
    }
    return 0;
}
