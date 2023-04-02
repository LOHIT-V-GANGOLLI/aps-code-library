#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int count(int arr[], int n, int val)
    {
        sort(arr, arr + n);
        int ans = 0, j, k, s;
        for (int i = 0; i < n - 2; i++)
        {
            j = i + 1;
            k = n - 1;
            while (j != k)
            {
                s = arr[i] + arr[j] + arr[k];
                if (s > val)
                    k--;
                else
                {
                    ans += (k - j);
                    j++;
                }
            }
        }
        return ans;
    }

public:
    int countTriplets(int Arr[], int N, int L, int R)
    {
        int ans;
        ans = count(Arr, N, R) - count(Arr, N, L - 1);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
