#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<long long> v, long long n, long long x)
{
    long long lo = 0;
    long long hi = n - 1;
    if (x < v[lo])
        return lo;
    if (x > v[hi])
        return hi + 1;
    int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (v[mid] == x)
            return mid;
        else if (x > v[mid])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return mid;
}

int main()
{
    vector<long long> v = {1, 2, 3, 4, 5, 9, 11};
    long long n = v.size();
    int target = 12;
    cout << findCeil(v, n, target);
    return 0;
}
