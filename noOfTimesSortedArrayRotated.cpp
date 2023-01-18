#include <bits/stdc++.h>
using namespace std;

int rotated(int arr[], int n)
{
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1) % n;
        if (arr[mid] <= prev && arr[mid] <= next)
            return mid;
        if (arr[lo] < arr[mid])
            lo = mid + 1;
        else if (arr[mid] < arr[hi])
            hi = mid - 1;
    }
}

int main()
{
    int arr[] = {11, 12, 13, 0, 1, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << rotated(arr, n);
    return 0;
}
