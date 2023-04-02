#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> v;
        for (int i = 0; i < q * 2; i += 2)
        {
            int sum = 0;
            for (int j = queries[i] - 1; j < queries[i + 1]; j++)
                sum += arr[j];
            v.push_back(sum);
        }
        return v;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> q;
        int queries[2 * q];
        for (int i = 0; i < 2 * q; i += 2)
            cin >> queries[i] >> queries[i + 1];
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
