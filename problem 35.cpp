#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int *a, int *b)
    {
        for (int i = 0; i < 256; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }

    int search(string pat, string txt)
    {
        int count = 0;
        int cp[256] = {0}, ct[256] = {0};
        for (int i = 0; i < pat.length(); i++)
        {
            cp[pat[i]]++;
            ct[txt[i]]++;
        }
        for (int i = pat.length(); i < txt.length(); i++)
        {
            if (check(cp, ct))
                count++;
            ct[txt[i]]++;
            ct[txt[i - pat.length()]]--;
        }
        if (check(cp, ct))
            count++;
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
