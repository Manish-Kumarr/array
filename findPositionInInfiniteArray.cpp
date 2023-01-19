#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int findPosition(vector<int> arr, int target)
{
    int l = 0;
    int h = 1;
    int n = arr.size();
    while (target > arr[h] && h != n - 1)
    {
        l = h;
        h = (n - 1 >= h * 2) ? h * 2 : n - 1;
    }
    return binarySearch(arr, l, h, target);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int ans = findPosition(arr, 9);
    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans << endl;
    return 0;
}
