#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string a, string b)
    {
        int arr[26] = {};
        for (int i = 0; a[i]; i++)
            arr[a[i] - 'a']++;
        for (int i = 0; b[i]; i++)
            arr[b[i] - 'a']--;
        for (int i = 0; i < 26; i++)
            if (arr[i])
                return false;
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string c, d;
        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
