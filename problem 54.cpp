#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSub(vector<int> &arr, int n, long long x)
    {
        int a = 0;
        int b = 0;
        long long s = 0;
        long long c = 0;
        while (b < n)
        {
            s += arr[b];
            while (a <= b && s > x)
            {
                s -= arr[a];
                a++;
            }
            c += (b - a + 1);
            b++;
        }
        return c;
    }

    long long countSubarray(int N, vector<int> A, long long L, long long R)
    {
        long long r = countSub(A, N, R);
        long long l = countSub(A, N, L - 1);
        return r - l;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        long long L, R;
        cin >> N >> L >> R;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        Solution obj;
        auto ans = obj.countSubarray(N, A, L, R);
        cout << ans << endl;
    }
}
