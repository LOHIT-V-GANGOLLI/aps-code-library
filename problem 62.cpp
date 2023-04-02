#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long int m = 1000000007;
    long long int power(long long int a, long long int b)
    {
        long long int x = 1;
        while (b > 0)
        {
            if (b % 2 != 0)
                x = (x * a) % m;
            b /= 2;
            a = (a * a) % m;
        }
        return x;
    }
    long long int inverse(long long int a, long long int b)
    {
        return (a * power(b, m - 2)) % m;
    }

public:
    int totalWays(int N, int K)
    {
        N--, K--;
        if (K > N)
            return 0;
        long long int f[N + 1];
        f[0] = 1;
        f[1] = 1;
        for (long long int i = 2; i <= N; i++)
            f[i] = ((f[i - 1] % m) * (i % m)) % m;
        long long int a = 1;
        a = f[N];
        long long int r = (f[K] % m * f[N - K] % m) % m;
        a = inverse(a, r);
        return int(a);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        int ans = ob.totalWays(n, k);
        cout << ans << "\n";
    }
    return 0;
}
