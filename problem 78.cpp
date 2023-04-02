#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum(int n)
    {
        int s = 0;
        while (n)
        {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }

    int RulingPair(vector<int> arr, int n)
    {
        unordered_map<int, int> m;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int s = sum(arr[i]);
            if (m[s] != 0)
                ans = max(ans, m[s] + arr[i]);
            m[s] = max(m[s], arr[i]);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.RulingPair(arr, n) << "\n";
    }
    return 0;
}
