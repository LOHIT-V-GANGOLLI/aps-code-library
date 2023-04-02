#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int t = 0;
        int l = 0;
        int r = m - 1;
        int b = n - 1;
        int c = 0;
        int d = 0;
        while (t <= b and l <= r)
        {
            if (d == 0)
            {
                for (int i = l; i <= r; i++)
                {
                    k--;
                    if (!k)
                        return (a[t][i]);
                }
                t++;
                d = 1;
            }
            if (d == 1)
            {
                for (int i = t; i <= b; i++)
                {
                    k--;
                    if (!k)
                        return (a[i][r]);
                }
                r--;
                d = 2;
            }
            if (d == 2)
            {
                for (int i = r; i >= l; i--)
                {
                    k--;
                    if (!k)
                        return (a[b][i]);
                }
                b--;
                d = 3;
            }
            if (d == 3)
            {
                for (int i = b; i >= t; i--)
                {
                    k--;
                    if (!k)
                        return (a[i][l]);
                }
                l++;
                d = 0;
            }
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        int k = 0;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution obj;
        cout << obj.findK(a, n, m, k) << "\n";
    }
}
