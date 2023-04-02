#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long c = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (arr[i] + arr[j] + arr[k] >= sum)
                    k--;
                else
                {
                    c += (k - j);
                    j++;
                }
            }
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
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.countTriplets(arr, n, sum);
        cout << "\n";
    }
    return 0;
}
