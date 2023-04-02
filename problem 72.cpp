#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int countTriplets(struct Node *head, int x)
{
    struct Node *p, *q, *r;
    int c = 0;
    unordered_map<int, Node *> u;
    for (p = head; p != NULL; p = p->next)
        u[p->data] = p;
    for (q = head; q != NULL; q = q->next)
        for (r = q->next; r != NULL; r = r->next)
        {
            int s = q->data + r->data;
            if (u.find(x - s) != u.end() && u[x - s] != q && u[x - s] != r)
                c++;
        }
    return (c / 3);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, num;
        struct Node *head = NULL;
        cin >> n >> x;
        for (i = 0; i < n; i++)
        {
            cin >> num;
            push(&head, num);
        }
        cout << countTriplets(head, x) << endl;
    }
    return 0;
}
