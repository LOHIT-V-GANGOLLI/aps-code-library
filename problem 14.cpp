#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(string S)
    {
        string str;
        int n = S.length();
        for (int i = 1; i < n; i++)
            if (S.substr(0, i) == S.substr(n - i, i))
            {
                str = S.substr(0, i);
                break;
            }
        int ans = 0;
        int m = str.length();
        if (m == 0)
            return 1;
        for (int i = 0; i < n; i++)
            if (str == S.substr(i, m))
                ans++;
        return ans;
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
        Solution obj;
        cout << obj.maxFrequency(str) << "\n";
    }
    return 0;
}
