#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool fun(int x, int m, int n, int k)
    {
        int c = 0;
        for (int i = 1; i <= m; i++)
            c += min(x / i, n);
        return c >= k;
    }

public:
    int KthSmallest(int m, int n, int k)
    {
        int l = 1, h = m * n;
        while (l < h)
        {
            int mi = l + (h - l) / 2;
            if (!fun(mi, m, n, k))
                l = mi + 1;
            else
                h = mi;
        }
        return l;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        Solution ob;
        int ans = ob.KthSmallest(m, n, k);
        cout << ans << endl;
    }
    return 0;
}
