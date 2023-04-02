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

void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {
        vector<int> v;
        map<int, vector<int>> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            pair<Node *, int> ptr = q.front();
            Node *temp = ptr.first;
            int d = ptr.second;
            m[d].push_back(temp->data);
            q.pop();
            if (temp->left)
                q.push({temp->left, d - 1});
            if (temp->right)
                q.push({temp->right, d + 1});
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            vector<int> a = i->second;
            for (auto x : a)
                v.push_back(x);
        }
        return v;
    }
};

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution obj;
        Node *root = buildTree(s);
        vector<int> res = obj.verticalOrder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
