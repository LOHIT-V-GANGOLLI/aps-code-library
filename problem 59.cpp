#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string sum(string str1, string str2)
    {
        if (str1.length() > str2.length())
            swap(str1, str2);
        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int d = n2 - n1;
        int c = 0;
        for (int i = n1 - 1; i >= 0; i--)
        {
            int s = ((str1[i] - '0') + (str2[i + d] - '0') + c);
            str.push_back(s % 10 + '0');
            c = s / 10;
        }
        for (int i = n2 - n1 - 1; i >= 0; i--)
        {
            int s = ((str2[i] - '0') + c);
            str.push_back(s % 10 + '0');
            c = s / 10;
        }
        if (c)
            str.push_back(c + '0');
        reverse(str.begin(), str.end());
        return str;
    }

public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        string a, b;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }
        return sum(a, b);
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
