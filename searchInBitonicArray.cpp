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

int ascendingBinarySearch(vector<int> arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descendingBinarySearch(vector<int> arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int searchBitonic(vector<int> arr, int n, int key, int index)
{
    if (key > arr[index])
        return -1;
    else if (key == arr[index])
        return index;
    else
    {
        int temp = ascendingBinarySearch(arr, 0, index - 1, key);
        if (temp != -1)
            return temp;
        return descendingBinarySearch(arr, index + 1, n - 1, key);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 11, 19, 14, 13, 12, 10, 9};
    int peakElement = findPeakElementInBiotonic(arr);
    cout << searchBitonic(arr, arr.size(), 20, peakElement);
    return 0;
}
