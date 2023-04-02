#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generator(vector<int> v, vector<vector<int>> &ans, int i, vector<int> arr, map<vector<int>, int> &count)
    {
        if (v.size() == arr.size())
        {
            if (count.find(v) == count.end())
            {
                ans.push_back(v);
                count[v] = 1;
            }
            return;
        }
        else
        {
            for (int j = i; j < arr.size(); j++)
            {
                v.push_back(arr[j]);
                swap(arr[i], arr[j]);
                generator(v, ans, i + 1, arr, count);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> arr, int n)
    {
        vector<int> v;
        vector<vector<int>> ans;
        map<vector<int>, int> count;
        generator(v, ans, 0, arr, count);
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr, n);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < n; j++)
                cout << res[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
