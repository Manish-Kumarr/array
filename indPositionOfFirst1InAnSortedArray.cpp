#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> arr, int x, int lo, int hi)
{
    int n = arr.size();
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            res = mid;
            hi = mid - 1;
        }
        else if (x < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return res;
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
    return firstOccurence(arr, target, l, h);
}

int main()
{
    vector<int> arr = {0};
    int ans = findPosition(arr, 1);
    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans << endl;
    return 0;
}
