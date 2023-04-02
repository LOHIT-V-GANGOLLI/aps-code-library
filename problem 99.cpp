#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, p;
    vector<int> rd;
    vector<int> wt;
    vector<int> cd;
    int ans;

    int dfs(int w)
    {
        if (cd[w] == 0)
            return w;
        if (wt[w] < ans)
            ans = wt[w];
        return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        this->n = n;
        this->p = p;
        rd = vector<int>(n + 1);
        wt = vector<int>(n + 1);
        cd = vector<int>(n + 1);
        vector<vector<int>> res;
        int i = 0;
        while (i < p)
        {
            int q = a[i], h = b[i],
                t = d[i];
            cd[q] = h;
            wt[q] = t;
            rd[h] = q;
            i++;
        }
        for (int j = 1; j <= n; ++j)
            if (rd[j] == 0 && cd[j])
            {
                ans = 1000000000;
                int w = dfs(j);
                res.push_back({j, w, ans});
            }
        return res;
    }
};

int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
            cin >> a[i] >> b[i] >> d[i];
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
    return 0;
}
