#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X)
{
    int l, r, f = 0;
    sort(A, A + n);
    for (int i = 0; i < n - 3; i++)
        for (int j = i + 1; j < n - 2; j++)
        {
            l = j + 1;
            r = n - 1;
            while (l < r)
            {
                if (A[i] + A[j] + A[l] + A[r] == X)
                {
                    f = 1;
                    l++;
                    r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else
                    r--;
            }
        }
    return f;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> x;
        cout << find4Numbers(a, n, x) << endl;
    }
    return 0;
}
