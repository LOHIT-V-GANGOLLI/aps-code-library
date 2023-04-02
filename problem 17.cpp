#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using ll = long long int;
    ll MOD = 1e9 + 7;
    void fibo(ll n, vector<long long int> &ans)
    {
        if (n == 0)
        {
            ans[0] = 0;
            ans[1] = 1;
            return;
        }
        fibo((n / 2), ans);
        ll a = ans[0];
        ll b = ans[1];
        ll c = 2 * b - a;
        if (c < 0)
            c += MOD;
        c = (a * c) % MOD;
        ll d = (a * a + b * b) % MOD;
        if (n % 2 == 0)
        {
            ans[0] = c;
            ans[1] = d;
        }
        else
        {
            ans[0] = d;
            ans[1] = c + d;
        }
    }

    int TotalAnimal(long long int N)
    {
        vector<long long int> ans(2, 0);
        fibo(N + 1, ans);
        return (int)ans[0];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        int ans = ob.TotalAnimal(N);
        cout << ans << "\n";
    }
    return 0;
}
