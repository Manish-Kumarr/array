#include <bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int N)
{
    int lo = 0;
    int hi = N - 1;
    if (arr[hi] >= arr[lo])
        return 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int prev = (mid + N - 1) % N;
        if (arr[mid] < arr[prev])
            return mid;
        else if (arr[mid] >= arr[0])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return 0;
}

int main()
{
    int arr[] = {8, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findKRotation(arr, n);
    return 0;
}
