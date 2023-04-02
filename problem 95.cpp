#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NumberOfPath(int a, int b)
    {
        int ans[a][b];
        for (int i = 0; i < b; i++)
            ans[0][i] = 1;
        for (int i = 0; i < a; i++)
            ans[i][0] = 1;
        for (int i = 1; i < a; i++)
            for (int j = 1; j < b; j++)
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        return ans[a - 1][b - 1];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.NumberOfPath(a, b) << endl;
    }
}
