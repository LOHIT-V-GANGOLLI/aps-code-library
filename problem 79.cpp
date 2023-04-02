#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int len(vector<int> &v)
    {
        if (v.size() == 0)
            return 0;
        vector<int> u(v.size(), 0);
        int l = 1;
        u[0] = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            auto b = u.begin(), e = u.begin() + l;
            auto it = lower_bound(b, e, v[i]);
            if (it == u.begin() + l)
                u[l++] = v[i];
            else
                *it = v[i];
        }
        return l;
    }

    int minInsAndDel(int A[], int B[], int N, int M)
    {
        map<int, int> m;
        for (int i = 0; i < M; i++)
            m.insert({B[i], i});
        vector<int> v;
        for (int i = 0; i < N; i++)
            if (m.find(A[i]) != m.end())
                v.push_back(m[A[i]]);
        int ans = (N - len(v)) + (M - len(v));
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];
        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
}
