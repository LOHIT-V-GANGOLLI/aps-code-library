#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
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
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    int count(struct Node *root)
    {
        if (root == NULL)
            return (0);
        return (1 + count(root->left) + count(root->right));
    }

    bool valid(Node *tree, int l, int n)
    {
        if (tree == NULL)
            return true;
        if (l >= n)
            return false;
        return valid(tree->left, 2 * l + 1, n) and
               valid(tree->right, 2 * l + 2, n);
    }

    bool prop(Node *root)
    {
        if (!root->left and !root->right)
            return true;
        if (root->right == NULL)
            return root->data > root->left->data;
        else
        {
            if (root->data >= root->left->data and
                root->data >= root->right->data)
                return prop(root->left) and prop(root->right);
            else
                return false;
        }
    }

    bool isHeap(struct Node *tree)
    {
        if (tree == NULL)
            return true;
        int no_of_nodes = count(tree);
        if (valid(tree, 0, no_of_nodes) && prop(tree))
            return true;
        return false;
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
