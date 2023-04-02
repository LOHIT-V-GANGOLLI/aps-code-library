#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unsigned int swapBits(unsigned int n)
    {
        unsigned int e = n & 0xAAAAAAAA;
        unsigned int o = n & 0x55555555;
        e >>= 1;
        o <<= 1;
        return (e | o);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned int n;
        cin >> n;
        Solution ob;
        cout << ob.swapBits(n) << endl;
    }
    return 0;
}
