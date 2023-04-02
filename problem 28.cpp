#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        unordered_map<int, int> m;
        vector<int> v;
        for (int i = 0; i < k; i++)
            m[A[i]]++;
        v.push_back(m.size());
        for (int i = 1; i < n - k + 1; i++)
        {
            m[A[i - 1]]--;
            if (m[A[i - 1]] <= 0)
                m.erase(A[i - 1]);
            m[A[i + k - 1]]++;
            v.push_back(m.size());
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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
