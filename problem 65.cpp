#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumWalk(vector<vector<int>> &graph, int u, int v, int k)
    {
        int n = graph.size();
        int c[n][n][k + 1];
        for (int l = 0; l <= k; l++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    c[i][j][l] = 0;
                    if (l == 0 && i == j)
                        c[i][j][l] = 1;
                    if (l == 1 && graph[i][j])
                        c[i][j][l] = 1;
                    if (l > 1)
                        for (int a = 0; a < n; a++)
                            if (graph[i][a])
                                c[i][j][l] = c[i][j][l] + c[a][j][l - 1];
                }
        return c[u][v][k];
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
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
        int u, v, k;
        cin >> u >> v >> k;
        Solution obj;
        int ans = obj.MinimumWalk(graph, u, v, k);
        cout << ans << "\n";
    }
    return 0;
}
