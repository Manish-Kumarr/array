#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
}

bool check(int arr[], int n)
{
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (find(v.begin(), v.end(), sum) != v.end())
            return true;
        v.push_back(sum);
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 3, 2, 10, 10};
    vector<int> ans = majorityElement(nums);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
