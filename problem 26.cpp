#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> u, v;
    for (int i = 0; i < n; i++)
        u[a1[i]]++;
    for (int i = 0; i < m; i++)
        v[a2[i]]++;
    int c = 0;
    for (auto it = v.begin(); it != v.end(); it++)
        if (u[it->first] >= it->second)
            c++;
    if (c == m)
        return "Yes";
    else
        return "No";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];
        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
