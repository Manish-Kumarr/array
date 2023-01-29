#include <bits/stdc++.h>
using namespace std;

void merging(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = k = l;
    j = mid + 1;
    int B[l + h];
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

void IMergeSort(int A[], int n)
{
    int pass, i, l, mid, h;

    for (pass = 2; pass <= n; pass = pass * 2)
    {
        for (i = 0; i + pass - 1 < n; i = i + pass)
        {
            l = i;
            h = i + pass - 1;
            mid = l + (h - l) / 2;
            merging(A, l, mid, h);
        }
        // if (n - i > pass / 2)
        //     {
        //         l = i;
        //         h = i + p - 1;
        //         mid = (l + h) / 2;
        //         merging(A, l, mid, n - 1);
        //     }
    }
    if (pass / 2 < n)
        merging(A, 0, (pass / 2) - 1, n - 1);
}

void rMergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        rMergeSort(A, low, mid);
        rMergeSort(A, mid + 1, high);
        merging(A, low, mid, high);
    }
}

int main()
{
    int A[] = {8, 4, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    rMergeSort(A, 0, n - 1);
    // IMergeSort(A, n);
    for (int x : A)
        cout << x << " ";
    return 0;
}
