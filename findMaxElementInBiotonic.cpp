#include <bits/stdc++.h>
using namespace std;

int findPeakElementInBiotonic(vector<int> &arr)
{
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;
            else if (arr[mid + 1] > arr[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        else if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return mid;
            else
                return mid + 1;
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return mid;
            else
                return mid - 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 3, 11, 19, 14, 13, 12, 10, 9};
    cout << findPeakElementInBiotonic(arr);
    return 0;
}
