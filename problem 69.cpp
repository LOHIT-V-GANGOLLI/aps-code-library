#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

void insert(stack<int> &s, int t)
{
    if (s.empty() || t > s.top())
    {
        s.push(t);
        return;
    }
    else
    {
        int x = s.top();
        s.pop();
        insert(s, t);
        s.push(x);
    }
}

void SortedStack ::sort()
{
    if (!s.empty())
    {
        int t = s.top();
        s.pop();
        sort();
        insert(s, t);
    }
}
