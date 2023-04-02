#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_min(int a[], int n, int k)
    {
        int sum = 0, pair = 0;
        for (int i = 0; i < n; i++)
        {
            pair += a[i] / 2;
            if (a[i] % 2 == 0)
                sum += (a[i] - 2) / 2;
            else
                sum += (a[i] - 1) / 2;
        }
        if (k > pair)
            return -1;
        if (k <= sum)
            return 2 * (k - 1) + n + 1;
        return 2 * sum + n + (k - sum);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
