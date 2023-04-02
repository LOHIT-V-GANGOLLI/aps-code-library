#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candies(int m, int n)
    {
        return (m - 1) * (n - 1) / 2;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        Solution obj;
        cout << obj.candies(m, n) << endl;
    }
    return 0;
}
