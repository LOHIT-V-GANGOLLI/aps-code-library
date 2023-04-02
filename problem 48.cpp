#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        long long int low = 1, high = m, mid;
        long long int ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            long long int x = mid;
            for (int i = 1; i < n; i++)
            {
                x *= mid;
                if (x > m * 1)
                    break;
            }
            if (x == m * 1)
            {
                ans = mid;
                break;
            }
            else if (x > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return int(ans);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
