#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubarray(vector<int> nums, int k)
{
    // code here
    if (k == 1)
        return nums;
    int n = nums.size();
    int i = 0, j = 0;
    list<int> l;
    vector<int> ans;
    while (j < n)
    {
        while (l.back() < nums[j] && l.size() > 0)
            l.pop_back();
        l.push_back(nums[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (nums[i] == l.front())
                l.pop_front();
            i++, j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {7, 2, 4};
    int k = 2;
    vector<int> ans = maxSubarray(v, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}
