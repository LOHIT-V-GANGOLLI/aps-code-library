#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[102][102];
    int edit(string s, string t, int m, int n)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        int &ans = dp[m][n];
        if (ans != -1)
            return ans;
        if (s[m - 1] == t[n - 1])
            return ans = edit(s, t, m - 1, n - 1);
        return ans = min({1 + edit(s, t, m, n - 1),
                          1 + edit(s, t, m - 1, n),
                          1 + edit(s, t, m - 1, n - 1)});
    }

    int editDistance(string s, string t)
    {
        memset(dp, -1, sizeof(dp));
        return edit(s, t, s.size(), t.size());
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
