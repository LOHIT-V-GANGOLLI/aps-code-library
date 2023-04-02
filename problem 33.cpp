#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    return 0;
}

struct Heap
{
    int val;
    int r;
    int c;
};

void swap(Heap *x, Heap *y)
{
    Heap z = *x;
    *x = *y;
    *y = z;
}

void minHeapify(Heap h[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int s = i;
    if (l < heap_size && h[l].val < h[i].val)
        s = l;
    if (r < heap_size && h[r].val < h[s].val)
        s = r;
    if (s != i)
    {
        swap(&h[i], &h[s]);
        minHeapify(h, s, heap_size);
    }
}

void buildHeap(Heap h[], int n)
{
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        minHeapify(h, i, n);
        i--;
    }
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    if (k <= 0 || k > n * n)
        return INT_MAX;
    Heap h[n];
    for (int i = 0; i < n; i++)
        h[i] = {mat[0][i], 0, i};
    buildHeap(h, n);
    Heap hr;
    for (int i = 0; i < k; i++)
    {
        hr = h[0];
        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c] : INT_MAX;
        h[0] = {nextval, (hr.r) + 1, hr.c};
        minHeapify(h, 0, n);
    }
    return hr.val;
}
