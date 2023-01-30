#include <bits/stdc++.h>
using namespace std;

// without space striver leetcode
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
            candidate = num;
        if (num == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

// with space
int majorityElement1(vector<int> &nums)
{
    unordered_map<int, int> umap;
    int mx = -1;
    int ans;
    for (int x : nums)
        umap[x]++;
    for (auto it : umap)
        mx = max(it.second, mx);
    for (auto it : umap)
        if (mx == it.second)
        {
            ans = it.first;
            break;
        }
    return ans;
}

// without space gfg
int majorityElement2(vector<int> &arr)
{
    int count = 1;
    int candidate = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[candidate] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            candidate = i;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[candidate] == arr[i])
            count++;

    if (count <= n / 2)
        return -1;
    else
        return arr[candidate];
}

int main()
{
    vector<int> nums = {3, 1};
    cout << majorityElement2(nums) << endl;
    return 0;
}
