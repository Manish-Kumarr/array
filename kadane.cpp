#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
            mx = max(ans, mx);
            if (ans < 0)
                ans = 0;
        }

        return mx < 0 ? 0 : mx;
    }
};

int main()
{
    int arr[] = {-3,-5,-6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution s;
    cout << s.maxSubarraySum(arr, n);
    return 0;
}