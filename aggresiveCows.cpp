#include <bits/stdc++.h>
using namespace std;

bool isValid(int a[], int n, int cows, int dist)
{
    int lastCow = a[0];
    int cow = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastCow >= dist)
        {
            cow++;
            lastCow = a[i];
        }
        if (cow == cows)
            return true;
    }
    return false;
}

int aggresiveCow(int a[], int n, int cow)
{
    if (n < cow)
        return -1;
    int res = -1;
    sort(a, a + n);
    int lo = 1;
    int hi = a[n - 1] - a[0];
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isValid(a, n, cow, mid))
        {
            res = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    return res;
}

int main()
{
    int arr[] = {2, 12, 11, 3, 26, 7};
    int cow = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << aggresiveCow(arr, n, cow);
    return 0;
}
