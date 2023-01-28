#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    int num1 = INT_MIN;
    int num2 = INT_MAX;
    int c1 = 0;
    int c2 = 0;

    for (int num : nums)
    {
        if (num == num1)
            c1++;
        else if (num == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = num;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = num;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    int count1 = 0, count2 = 0;
    for (int num : nums)
    {
        if (num == num1)
            count1++;
        if (num == num2)
            count2++;
    }

    if (count1 > n / 3)
        ans.push_back(num1);
    if (count2 > n / 3)
        ans.push_back(num2);

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 5, 1};
    vector<int> ans = majorityElement(nums);
    for (int x : ans)
        cout << x << " ";
    return 0;
}
