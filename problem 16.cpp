#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubstring(string S)
    {
        int n = S.size();
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = (S[i] == '0') ? 1 : -1;
        int res = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            res = max(arr[i], res + arr[i]);
            ans = max(ans, res);
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.maxSubstring(s) << "\n";
    }
    return 0;
}
