#include <bits/stdc++.h>
using namespace std;

void merging(vector<int> A, vector<int> B)
{
    int i, j, k;
    i = j = k = 0;
    int n = A.size();
    int m = B.size();
    int C[n + m];

    while (i < n && j < m)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < n)
        C[k++] = A[i++];
    while (j < m)
        C[k++] = B[j++];

    for (int x : C)
        cout << x << " ";
}

int main()
{
    vector<int> A = {1, 4, 7, 10};
    vector<int> B = {2, 6, 9, 12, 19, 34};
    merging(A, B);
    return 0;
}
