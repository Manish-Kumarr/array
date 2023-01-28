#include <bits/stdc++.h>
using namespace std;

void inerstionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = nums[i];
        while (nums[j] > temp && j >= 0)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

int main()
{
    vector<int> nums = {6, 8, 12, 14, 2, 3};
    inerstionSort(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
