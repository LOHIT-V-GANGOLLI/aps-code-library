#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {
        n += 1;
        int c = 0;
        for (int x = 2; x < n * 2; x = x * 2)
        {
            int q = n / x;
            c += q * x / 2;
            int r = n % x;
            if (r > x / 2)
                c += r - x / 2;
        }
        return c;
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
        cout << ob.countSetBits(n) << endl;
    }
    return 0;
}
