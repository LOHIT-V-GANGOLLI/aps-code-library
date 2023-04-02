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
    void storeInOrder(Node *root, int d, vector<int> &v,
                      vector<int> &l)
    {
        if (!root)
            return;
        storeInOrder(root->left, d + 1, v, l);
        v.push_back(root->data);
        l.push_back(d);
        storeInOrder(root->right, d + 1, v, l);
    }

public:
    pair<int, int> shortestRange(Node *root)
    {
        vector<int> v, l;
        storeInOrder(root, 0, v, l);
        int i = 0, j = 0, k = 0, c = 0,
            m = *max_element(l.begin(), l.end()) + 1;
        vector<int> d(m, 0);
        for (k = 0; k < l.size(); k++)
        {
            d[l[k]]++;
            if (l[k] == 0)
            {
                j = k;
                break;
            }
        }
        for (int u : d)
        {
            if (u == 0)
                c++;
        }
        int x = *v.begin(), y = v.back();
        if (c == 0)
            x = v[i], y = v[j];
        while (i <= k && j < v.size())
        {
            while (j < v.size())
            {
                if (c == 0)
                {
                    if ((y - x) > (v[j] - v[i]))
                    {
                        x = v[i];
                        y = v[j];
                    }
                    break;
                }
                j++;
                if (j >= v.size())
                    break;
                if (d[l[j]] == 0)
                    c--;
                d[l[j]]++;
            }
            while (!c && i <= k)
            {
                if ((y - x) > (v[j] - v[i]))
                {
                    x = v[i];
                    y = v[j];
                }
                d[l[i]]--;
                if (d[l[i]] == 0)
                    c++;
                i++;
            }
        }
        return {x, y};
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
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }
    return 0;
}
