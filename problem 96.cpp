#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int countSubtreesWithSumXUtil(Node *root, int &c, int x)
{
    if (!root)
        return 0;
    int l = countSubtreesWithSumXUtil(root->left, c, x);
    int r = countSubtreesWithSumXUtil(root->right, c, x);
    int s = l + r + root->data;
    if (s == x)
        c++;
    return s;
}

int countSubtreesWithSumX(Node *root, int x)
{
    if (!root)
        return 0;
    int c = 0;
    int l = countSubtreesWithSumXUtil(root->left, c, x);
    int r = countSubtreesWithSumXUtil(root->right, c, x);
    if ((l + r + root->data) == x)
        c++;
    return c;
}

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        int x;
        cin >> x;
        getchar();
        cout << countSubtreesWithSumX(root, x) << endl;
    }
    return 0;
}
