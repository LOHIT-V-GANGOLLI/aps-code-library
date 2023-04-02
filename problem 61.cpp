#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Inf
    {
        int dis;
        int hou;
        Inf(int x, int y)
        {
            dis = x;
            hou = y;
        }
    };

    struct Cmp
    {
        bool operator()(Inf const &p1, Inf const &p2)
        {
            if (p1.dis == p2.dis)
                return p1.hou < p2.hou;
            else
                return p1.dis < p2.dis;
        }
    };

public:
    vector<int> Kclosest(vector<int> arr, int n, int x, int k)
    {
        vector<int> v;
        priority_queue<Inf, vector<Inf>, Cmp> pq;
        for (int i = 0; i < k; i++)
        {
            Inf obj(abs(arr[i] - x), arr[i]);
            pq.push(obj);
        }
        for (int i = k; i < n; i++)
        {
            int diff = abs(arr[i] - x);
            if (diff > pq.top().dis)
                continue;
            if (diff == pq.top().dis && arr[i] > pq.top().hou)
                continue;
            pq.pop();
            Inf obj(abs(arr[i] - x), arr[i]);
            pq.push(obj);
        }
        while (pq.empty() == false)
        {
            v.push_back(pq.top().hou);
            pq.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> x >> k;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
            cin >> array[i];
        Solution obj;
        vector<int> result = obj.Kclosest(array, n, x, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << "\n";
    }
    return 0;
}
