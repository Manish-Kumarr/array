
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIndex(vector<int> arr, int N)
    {
        if (N == 2 && arr[1] < arr[0])
            return 1;
        int lo = 0;
        int hi = N - 1;
        int mid, mn;
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

    int binarySearch(vector<int> arr, int lo, int hi, int x)
    {
        int ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x)
                return mid;
            else if (x < arr[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return ans;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int minIdx = minIndex(nums, n);
        int leftValue = binarySearch(nums, 0, minIdx - 1, target);
        int rightValue = binarySearch(nums, minIdx, n - 1, target);
        if (leftValue == rightValue == -1)
            return -1;
        if (leftValue != -1)
            return leftValue;
        return rightValue;
        return 0;
    }
};

int main()
{
    vector<int> v = {8, 5, 6, 7};
    int n = v.size();
    int target = 7;
    Solution s;
    cout << s.search(v, target);
    return 0;
}