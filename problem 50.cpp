#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int length(int n)
    {
        int x = 0;
        while (n >= 10)
        {
            x++;
            n /= 10;
        }
        return x;
    }

    int Rotate(int n)
    {
        int x = n % 10;
        int len = length(n);
        for (int i = 0; i < len; i++)
            x *= 10;
        n = x + n / 10;
        return n;
    }

    int isCircularPrime(int n)
    {
        if (n < 2)
            return false;
        vector<bool> prime(100000, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= 100000; i++)
            if (prime[i])
                for (int j = i * i; j <= 100000; j += i)
                    prime[j] = false;
        int len = length(n);
        for (int i = 0; i <= len; i++)
        {
            if (!prime[n])
                return 0;
            n = Rotate(n);
        }
        return 1;
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
        Solution ob;
        int ans = ob.isCircularPrime(n);
        cout << ans << "\n";
    }
    return 0;
}
