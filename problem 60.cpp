#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
    {
        if (a.first.second != b.first.second)
            return a.first.second < b.first.second;
        return a.second < b.second;
    }

public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({{start[i], end[i]}, i + 1});
        sort(v.begin(), v.end(), cmp);
        int last = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (v[i].first.first > last)
            {
                ans++;
                last = v[i].first.second;
            }
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
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
