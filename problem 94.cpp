#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> p, r;
    void make(int v)
    {
        p[v] = v;
        r[v] = 0;
    }

    int find(int v)
    {
        if (v == p[v])
            return v;
        return p[v] = find(p[v]);
    }

    void unions(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (r[a] < r[b])
                swap(a, b);
            p[b] = a;
            if (r[a] == r[b])
                r[a]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> v;
        for (int i = 0; i < V; i++)
        {
            vector<int> t;
            for (int j = 0; j < adj[i].size(); j++)
            {
                vector<int> x = adj[i][j];
                t.push_back(x[1]);
                t.push_back(min(i, x[0]));
                t.push_back(max(i, x[0]));
                v.push_back(t);
                t.clear();
            }
        }
        sort(v.begin(), v.end());
        vector<vector<int>> g;
        for (int i = 0; i < v.size(); i += 2)
            g.push_back(v[i]);
        int c = 0;
        p.resize(V);
        r.resize(V);
        for (int i = 0; i < V; i++)
            make(i);
        for (vector<int> e : g)
        {
            if (find(e[1]) != find(e[2]))
            {
                c += e[0];
                unions(e[1], e[2]);
            }
        }
        return c;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }
    return 0;
}
