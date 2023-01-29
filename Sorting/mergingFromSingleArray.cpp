#include <bits/stdc++.h>
using namespace std;
int B[1000];

void merging(vector<int> &A, int l, int mid, int h)
{
    int i, j, k;
    i = k = l;
    j = mid + 1;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];

    for (int i = l; i <= h; i++)
        A[i] = B[i];
}

int main()
{
    vector<int> A = {1, 4, 7, 10, 2, 5, 6, 9};
    int n = A.size();
    int l = 0;
    int h = n - 1;
    int mid = l + (h - l) / 2;
    merging(A, l, mid, h);
    for (int x : A)
        cout << x << " ";
    return 0;
}
