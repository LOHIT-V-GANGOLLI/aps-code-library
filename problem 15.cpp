#include <bits/stdc++.h>
using namespace std;
#define N 1000

struct Heap
{
    int data;
    int i;
    int j;
};

void swap(Heap *x, Heap *y);

class MinHeap
{
    Heap *harr;
    int hsize;

public:
    MinHeap(Heap a[], int size);
    void heapify(int);
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    Heap getMin() { return harr[0]; }
    void replaceMin(Heap x)
    {
        harr[0] = x;
        heapify(0);
    }
};

MinHeap::MinHeap(Heap a[], int size)
{
    hsize = size;
    harr = a;
    int i = (hsize - 1) / 2;
    while (i >= 0)
    {
        heapify(i);
        i--;
    }
}

void MinHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int s = i;
    if (l < hsize &&
        harr[l].data < harr[i].data)
        s = l;
    if (r < hsize &&
        harr[r].data < harr[s].data)
        s = r;
    if (s != i)
    {
        swap(harr[i], harr[s]);
        heapify(s);
    }
}

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        int range = INT_MAX;
        int min = INT_MAX, max = INT_MIN;
        int start, end;
        Heap *harr = new Heap[k];
        for (int i = 0; i < k; i++)
        {
            harr[i].data = arr[i][0];
            harr[i].i = i;
            harr[i].j = 1;
            if (harr[i].data > max)
                max = harr[i].data;
        }
        MinHeap hp(harr, k);
        while (true)
        {
            Heap root = hp.getMin();
            min = hp.getMin().data;
            if (range > max - min + 1)
            {
                range = max - min + 1;
                start = min;
                end = max;
            }
            if (root.j < n)
            {
                root.data = arr[root.i][root.j];
                root.j += 1;
                if (root.data > max)
                    max = root.data;
            }
            else
                break;
            hp.replaceMin(root);
        }
        return {start, end};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
