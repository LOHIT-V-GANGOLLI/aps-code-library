#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCandy(int height[], int n)
    {
        int mx = 0;
        for (int i = 0, j = n - 1; i < n;)
        {
            if (height[i] < height[j])
                mx = max(mx, (j - i - 1) * height[i++]);
            else if (height[i] > height[j])
                mx = max(mx, (j - i - 1) * height[j--]);
            else
            {
                mx = max(mx, (j - i - 1) * height[i]);
                i++;
                j--;
            }
        }
        return mx;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int height[n];
        for (int i = 0; i < n; ++i)
            cin >> height[i];
        Solution obj;
        cout << obj.maxCandy(height, n) << "\n";
    }
    return 0;
}
