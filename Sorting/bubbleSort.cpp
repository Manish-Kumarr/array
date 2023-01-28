#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    vector<int> nums = {1, 2, 4, 3};
    bubbleSort(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
