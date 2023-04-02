#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycleUtil(int u, int par, vector<int> adj[], vector<bool> &v)
    {
        v[u] = true;
        for (auto a : adj[u])
        {
            if (a == par)
                continue;
            if (v[a])
                return true;
            if (isCycleUtil(a, u, adj, v))
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> v(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!v[i])
            {
                bool f = isCycleUtil(i, -1, adj, v);
                if (f)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
