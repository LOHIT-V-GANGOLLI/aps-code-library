#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N)
    {
        if (N == 0)
            return 1;
        if (N == 1)
            return (preorder[0] == inorder[0]) && (inorder[0] == postorder[0]);
        int ind = -1;
        for (int i = 0; i < N; ++i)
            if (inorder[i] == preorder[0])
            {
                ind = i;
                break;
            }
        if (ind == -1)
            return 0;
        if (preorder[0] != postorder[N - 1])
            return false;
        int left = checktree(preorder + 1, inorder, postorder, ind);
        int right = checktree(preorder + ind + 1, inorder + ind + 1, postorder + ind, N - ind - 1);
        return (left && right);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int preorder[n];
        int inorder[n];
        int postorder[n];
        for (int i = 0; i < n; ++i)
            cin >> preorder[i];
        for (int i = 0; i < n; ++i)
            cin >> inorder[i];
        for (int i = 0; i < n; ++i)
            cin >> postorder[i];
        Solution obj;
        if (obj.checktree(preorder, inorder, postorder, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
