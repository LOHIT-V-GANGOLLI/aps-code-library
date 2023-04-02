#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int c = 0, ans = -1;
        queue<vector<int>> q;
        vector<vector<int>> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] > 0)
                    c++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        while (!q.empty())
        {
            ans++;
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                vector<int> u = q.front();
                c--;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = u[0] + v[i][0], y = u[1] + v[i][1];
                    if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        if (c == 0)
            return max(0, ans);
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
