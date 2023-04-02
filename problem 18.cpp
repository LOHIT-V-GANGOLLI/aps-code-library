#include <bits/stdc++.h>
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *even = NULL, *odd = NULL, *temp = head;
        while (temp)
        {
            if (!even && temp->data % 2 == 0)
                even = new Node(temp->data);
            if (!odd && temp->data % 2 == 1)
                odd = new Node(temp->data);
            temp = temp->next;
        }
        if (!even || !odd)
            return head;
        temp = head;
        Node *eptr = even, *optr = odd;
        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                eptr->next = new Node(temp->data);
                eptr = eptr->next;
            }
            else if (temp->data % 2 == 1)
            {
                optr->next = new Node(temp->data);
                optr = optr->next;
            }
            temp = temp->next;
        }
        eptr->next = odd->next;
        head = even->next;
        return head;
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
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
