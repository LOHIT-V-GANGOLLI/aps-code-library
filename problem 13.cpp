#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestCommonPrefix(string str1, string str2)
    {
        int n = str1.length();
        int k = n;
        vector<int> v(2, -1);
        while (k >= 0)
        {
            string s = str1.substr(0, k);
            if (str2.find(s) > 0 && str2.find(s) < n)
            {
                int i = 0;
                while (str1[i] != s[0])
                    i++;
                v[0] = i;
                v[1] = i + s.size() - 1;
                return v;
            }
            else
                k--;
        }
        return v;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution ob;
        vector<int> p;
        p = ob.longestCommonPrefix(str1, str2);
        if (p[0] == -1)
            cout << "-1\n";
        else
            cout << p[0] << " " << p[1] << "\n";
    }
    return 0;
}
