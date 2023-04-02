#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> v;
        v.push_back(1);
        for (int i = 2; i <= N; i++)
        {
            int carry = 0;
            for (int j = 0; j < v.size(); j++)
            {
                int num = i * v[j];
                v[j] = (num + carry) % 10;
                carry = (num + carry) / 10;
            }
            while (carry)
            {
                v.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(v.begin(), v.end());
        return v;
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
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i];
        cout << endl;
    }
    return 0;
}
