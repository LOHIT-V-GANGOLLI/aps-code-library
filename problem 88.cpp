#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> arr, int n)
    {
        long long mn = arr[0];
        long long mx = arr[0];
        long long m = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
                swap(mx, mn);
            mx = max((long long)arr[i], mx * arr[i]);
            mn = min((long long)arr[i], mn * arr[i]);
            m = max(m, mx);
        }
        return m;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
