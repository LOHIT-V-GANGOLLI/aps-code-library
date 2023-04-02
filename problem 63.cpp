#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isInterleave(string A, string B, string C)
    {
        int M = A.size(), N = B.size();
        bool leave[M + 1][N + 1];
        memset(leave, 0, sizeof(leave));
        if ((M + N) != C.size())
            return false;
        for (int i = 0; i <= M; ++i)
            for (int j = 0; j <= N; ++j)
            {
                if (i == 0 && j == 0)
                    leave[i][j] = true;
                else if (i == 0 && B[j - 1] == C[j - 1])
                    leave[i][j] = leave[i][j - 1];
                else if (j == 0 && A[i - 1] == C[i - 1])
                    leave[i][j] = leave[i - 1][j];
                else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                    leave[i][j] = leave[i - 1][j];
                else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    leave[i][j] = leave[i][j - 1];
                else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    leave[i][j] = (leave[i - 1][j] || leave[i][j - 1]);
            }
        return leave[M][N];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    return 0;
}
