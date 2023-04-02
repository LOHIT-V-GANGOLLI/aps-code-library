#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> s;
        for (int i = 0; x[i]; i++)
        {
            if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                s.push(x[i]);
                continue;
            }
            if (s.empty())
                return false;
            char c = s.top();
            s.pop();
            if ((x[i] == ')' && c != '(') || (x[i] == ']' && c != '[') || (x[i] == '}' && c != '{'))
                return false;
        }
        return s.empty();
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
    return 0;
}
