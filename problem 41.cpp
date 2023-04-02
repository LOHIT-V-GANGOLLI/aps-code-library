#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        string a = A;
        int c = ceil(B.length() / double(A.length()));
        for (int i = 1; i < c; i++)
            A += a;
        if (A.find(B) != string::npos)
            return c;
        else if ((A + A).find(B) != string::npos)
            return c + 1;
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    }
    return 0;
}
