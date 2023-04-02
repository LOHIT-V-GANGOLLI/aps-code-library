#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        int a = array1.size();
        int b = array2.size();
        int n = ((a + b) / 2) + 1;
        vector<int> array(n);
        for (int i = 0, j = 0, k = 0; i < n; i++)
        {
            if (k > b - 1)
                array[i] = array1[j++];
            else if (j > a - 1)
                array[i] = array2[k++];
            else if (array1[j] <= array2[k])
                array[i] = array1[j++];
            else if (array1[j] > array2[k])
                array[i] = array2[k++];
        }
        if ((a + b) % 2)
            return array[n - 1];
        else
            return (array[n - 1] + array[n - 2]) / 2.0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin >> array1[i];
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin >> array2[i];
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}
