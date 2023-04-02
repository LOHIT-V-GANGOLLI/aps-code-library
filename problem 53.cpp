#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxOfMin(int arr[], int n)
    {
        stack<int> s;
        int l[n + 1];
        int r[n + 1];
        for (int i = 0; i < n; i++)
        {
            l[i] = -1;
            r[i] = n;
        }
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                l[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                r[i] = s.top();
            s.push(i);
        }
        int ans[n + 1];
        for (int i = 0; i <= n; i++)
            ans[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int len = r[i] - l[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);
        vector<int> res(n);
        for (int i = 1; i <= n; i++)
            res[i - 1] = ans[i];
        return res;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        vector<int> res = ob.maxOfMin(a, n);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
