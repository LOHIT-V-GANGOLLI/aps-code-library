#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n <= 1)
            return 0;
        if (arr[0] == 0)
            return -1;
        int mx = arr[0];
        int c = arr[0];
        int j = 1;
        int i = 1;
        for (i = 1; i < n; i++)
        {
            if (i == n - 1)
                return j;
            mx = max(mx, i + arr[i]);
            c--;
            if (c == 0)
            {
                j++;
                if (i >= mx)
                    return -1;
                c = mx - i;
            }
        }
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
