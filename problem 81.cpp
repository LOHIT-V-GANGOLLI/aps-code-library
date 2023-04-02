#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(int N, vector<int> A, int X)
    {
        int pre = 0, ans = N;
        for (int i = 30; i >= 0; i--)
        {
            if ((X >> i) & 1)
            {
                pre ^= (1ll << i);
                continue;
            }
            int ct = 0;
            int p = pre ^ (1ll << i);
            for (auto &j : A)
            {
                if ((j & p) == p)
                    ct++;
            }
            ans = min(ans, N - ct);
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
        int N, X;
        cin >> N >> X;
        vector<int> A(N);
        for (auto &i : A)
            cin >> i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout << ans << endl;
    }
}
