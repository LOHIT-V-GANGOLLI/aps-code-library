#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        int s = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long q = 0, n = 0;
        for (int i = 31; i >= 0; --i)
            if (n + (divisor << i) <= dividend)
            {
                n += divisor << i;
                q |= 1LL << i;
            }
        return s * q;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.divide(a, b) << "\n";
    }
    return 0;
}
