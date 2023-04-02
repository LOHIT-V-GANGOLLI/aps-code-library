#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int modulo(int a, string b)
    {
        int mod = 0;
        for (int i = 0; i < b.length(); i++)
            mod = (mod * 10 + b[i] - '0') % a;
        return mod;
    }

public:
    int getLastDigit(string a, string b)
    {
        int n = a.length(), m = b.length();
        if (n == 1 && m == 1 && b[0] == '0' && a[0] == '0')
            return 1;
        if (m == 1 && b[0] == '0')
            return 1;
        if (n == 1 && a[0] == '0')
            return 0;
        int e = (modulo(4, b) == 0) ? 4 : modulo(4, b);
        int r = pow(a[n - 1] - '0', e);
        return r % 10;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.getLastDigit(a, b) << endl;
    }
    return 0;
}
