#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n)
{
    // code here
    int mx = INT_MIN;
    long long ans = 0;
    int maxRight[n] = {arr[0]}; // left to right
    int maxLeft[n];             // right to left
    maxLeft[n - 1] = {arr[n - 1]};

    for (int i = 1; i < n; i++)
        maxRight[i] = max(maxRight[i - 1], arr[i]);

    for (int i = n - 2; i >= 0; i--)
        maxLeft[i] = max(maxLeft[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        ans += min(maxRight[i], maxLeft[i]) - arr[i];

    return ans;
}

//time - O(N)
int trap(vector<int> &height)
{
    int l, r, leftMax, rightMax, ans;
    l = leftMax, rightMax = ans = 0;
    r = height.size() - 1;

    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= leftMax)
                leftMax = height[l];
            else
                ans +=( leftMax - height[l]);
            l++;
        }
        else
        {
            if (height[r] >= rightMax)
                rightMax = height[r];
            else
                ans += (rightMax - height[r]);
            r--;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {3, 0, 8, 2, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << trappingWater(arr, n);
    return 0;
}
