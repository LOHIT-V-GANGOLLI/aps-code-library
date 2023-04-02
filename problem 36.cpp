#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < n; i++)
            v.push_back({end[i], {start[i], i}});
        sort(v.begin(), v.end());
        int count = 1;
        int curr = v[0].first;
        for (int i = 1; i < n; i++)
            if (curr < v[i].second.first)
            {
                curr = v[i].first;
                count++;
            }
        return count;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
