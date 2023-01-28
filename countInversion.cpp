#include <bits/stdc++.h>
using namespace std;

void countInversion(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int flag;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                count++;
                flag = false;
            }
        }
        if (flag)
            break;
    }
    cout << count << endl;
}

int main()
{
    vector<int> nums = {8, 4, 2, 1};
    countInversion(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
