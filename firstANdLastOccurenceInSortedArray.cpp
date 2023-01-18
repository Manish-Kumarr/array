#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;
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
int lastOccurence(int arr[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            res = mid;
            lo = mid + 1;
        }
        else if (x < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return res;
}

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 67, 455, 500};
    int x = 5;
    int f = firstOccurence(arr, 8, x);
    int l = lastOccurence(arr, 8, x);

    cout << f << " " << l << endl;
    cout << "Number of occurence of " << x << " is : " << l - f;

    return 0;
}
