#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void palindrome(Node *head, stack<int> &s, stack<int> &t)
    {
        if (head)
        {
            s.push(head->data);
            palindrome(head->next, s, t);
            t.push(head->data);
        }
    }

    bool isPalindrome(Node *head)
    {
        stack<int> s, t;
        palindrome(head, s, t);
        while (!s.empty())
        {
            if (s.top() != t.top())
                return 0;
            s.pop();
            t.pop();
        }
        return true;
    }
};

int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}
