#include <bits/stdc++.h>
using namespace std;

long long int merging(long long A[], long long l, long long mid, long long h)
{
    long long i, j, k;
    i = k = l;
    j = mid + 1;
    long long int count = 0;
    long long B[l + h];
    while ((i <= mid) && (j <= h))
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
        {
            B[k++] = A[j++];
            count = count + (mid - i + 1);
        }
    }

    while (i <= mid)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];

    for (long long i = l; i <= h; i++)
        A[i] = B[i];

    return count;
}

long long int rMergeSort(long long A[], long long low, long long high)
{
    long long int count = 0;
    if (low < high)
    {
        long long mid = (low + high) / 2;
        count += rMergeSort(A, low, mid);
        count += rMergeSort(A, mid + 1, high);
        count += merging(A, low, mid, high);
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    long long int ans = rMergeSort(arr, 0, N - 1);
    return ans;
}

int main()
{
    long long A[] = {5, 4, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    cout << inversionCount(A, n);
    return 0;
}
