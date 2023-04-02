#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        sort(arr, arr + n);
        int i = 0, j = n - 1;
        int s = arr[i] + arr[j];
        int d = abs(s);
        while (i < j)
        {
            if (arr[i] + arr[j] == 0)
                return 0;
            if (abs(arr[i] + arr[j]) < abs(d))
            {
                d = (arr[i] + arr[j]);
                s = arr[i] + arr[j];
            }
            else if (abs(arr[i] + arr[j]) == abs(d))
            {
                s = max(s, arr[i] + arr[j]);
            }
            if (arr[i] + arr[j] > 0)
                j--;
            else
                i++;
        }
        return s;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
    return 0;
}
