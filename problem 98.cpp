#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        long long tp, ar, mx = 0, i = 0;
        while (i < n)
        {
            if (s.empty() || arr[s.top()] <= arr[i])
                s.push(i++);
            else
            {
                tp = s.top();
                s.pop();
                ar = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if (mx < ar)
                    mx = ar;
            }
        }
        while (!s.empty())
        {
            tp = s.top();
            s.pop();
            ar = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            if (mx < ar)
                mx = ar;
        }
        return mx;
    }
};

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
