#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        map<int, int> pre;
        int len = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (!sum)
                len = i + 1;
            if (pre.find(sum) != pre.end())
                len = max(len, i - pre[sum]);
            else
                pre[sum] = i;
        }
        return len;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin >> array1[i];
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}
