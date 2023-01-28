#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (nums[j] < nums[k])
                k = j;
        }
        swap(nums[i], nums[k]);
    }
}

int main()
{
    vector<int> nums = {6, 8, 12, 14, 2, 3};
    selectionSort(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
