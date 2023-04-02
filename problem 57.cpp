#include <bits/stdc++.h>
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    int l, i, n = key.size();
    struct TrieNode *p = root;
    for (l = 0; l < n; l++)
    {
        i = CHAR_TO_INDEX(key[l]);
        if (!p->children[i])
            p->children[i] = getNode();
        p = p->children[i];
    }
    p->isLeaf = true;
}

bool search(struct TrieNode *root, string key)
{
    int l, i, n = key.size();
    struct TrieNode *p = root;
    for (l = 0; l < n; l++)
    {
        i = CHAR_TO_INDEX(key[l]);
        if (!p->children[i])
            return false;
        p = p->children[i];
    }
    return (p != NULL && p->isLeaf);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++)
            insert(root, keys[i]);
        string abc;
        cin >> abc;
        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
