#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long ValidPair(int a[], int n)
    {
        long long c = 0;
        sort(a, a + n);
        for (int i = 0, j = n - 1; i < j;)
        {
            if (a[i] + a[j] > 0)
                c += (j--) - i;
            else
                i++;
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
        int array[n];
        for (int i = 0; i < n; ++i)
            cin >> array[i];
        Solution obj;
        cout << obj.ValidPair(array, n) << "\n";
    }
    return 0;
}
