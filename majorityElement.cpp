#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> nums = {1, 1, 1, 2, 5, 1};
    cout << majorityElement1(nums);
    return 0;
}
