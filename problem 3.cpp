#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        int c = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i] <= k)
                ++c;
        int b = 0;
        for (int i = 0; i < c; ++i)
            if (arr[i] > k)
                ++b;
        int a = b;
        for (int i = 0, j = c; j < n; ++i, ++j)
        {
            if (arr[i] > k)
                --b;
            if (arr[j] > k)
                ++b;
            a = min(a, b);
        }
        return a;
    }
};

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
