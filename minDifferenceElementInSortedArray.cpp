#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<long long> v, long long n, long long x)
{
    long long lo = 0;
    long long hi = n - 1;
    int mid, temp;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (v[mid] == x)
            return 0;
        else if (x > v[mid])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    temp = min(abs(v[lo] - x), abs(v[hi] - x));
    return temp;
}

int main()
{
    vector<long long> v = {1, 2, 3, 4, 5, 9, 14};
    long long n = v.size();
    int target = 16;
    cout << minDiff(v, n, target);
    return 0;
}
