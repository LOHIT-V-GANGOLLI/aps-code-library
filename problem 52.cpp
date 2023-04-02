#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> word;
        for (int i = 0; i < wordList.size(); i++)
            word.insert(wordList[i]);
        vector<vector<string>> a;
        queue<vector<string>> ps;
        ps.push({beginWord});
        int l = 1;
        int ml = INT_MAX;
        unordered_set<string> visit;
        while (!ps.empty())
        {
            vector<string> p = ps.front();
            ps.pop();
            if (p.size() > l)
            {
                for (string w : visit)
                    word.erase(w);
                visit.clear();
                if (p.size() > ml)
                    break;
                else
                    l = p.size();
            }
            string e = p.back();
            for (int i = 0; i < e.size(); ++i)
            {
                string n = e;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    n[i] = c;
                    if (word.find(n) != word.end())
                    {
                        vector<string> np = p;
                        np.push_back(n);
                        visit.insert(n);
                        if (n == endWord)
                        {
                            ml = l;
                            a.push_back(np);
                        }
                        else
                            ps.push(np);
                    }
                }
            }
        }
        return a;
    }
};

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;
    return x < y;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                    cout << ans[i][j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
