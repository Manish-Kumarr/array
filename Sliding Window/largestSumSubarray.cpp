// Return total no. of subarray with sum k
#include <bits/stdc++.h>
using namespace std;

// Brure force
// time o(n^2)
int largestSum(vector<int> arr, int k)
{
    int count = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

//aditya verma approach
// Not work for all case
// time o(n)
int largestSum1(vector<int> arr, int k)
{
    int mx = 0, sum = 0, i = 0, j = 0;
    while (j < arr.size() && i < arr.size())
    {
        sum += arr[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            mx++;
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
                mx++;
            j++;
        }
    }
    return mx;
}

// with map
// time = space = o(n)
//tech dose
int largestSum2(vector<int> arr, int k)
{
    int count = 0, sum = 0;
    map<int, int> m;
    int i = 0;
    while (i < arr.size())
    {
        sum += arr[i];
        if (sum == k)
            count++;
        if (m.find(sum - k) != m.end())
            count += m[sum - k];
        m[sum]++;
        i++;
    }
    return count;
}

int main()
{
    vector<int> nums = {0, 0, 0};
    int k = 0; // sum
    cout << largestSum(nums, k) << endl;
    cout << largestSum1(nums, k) << endl;
    cout << largestSum2(nums, k) << endl;
    return 0;
}
