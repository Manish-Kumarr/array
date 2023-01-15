#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        //Time o(logn * m)
        // if (n == 0)
        //     return;
        // int i, j;
        // i = j = 0;
        // for (i = 0; i < m; i++)
        //     if (nums1[i] > nums2[0])
        //     {
        //         swap(nums1[i], nums2[0]);
        //         sort(nums2.begin(), nums2.end());
        //     }
        // for (j = 0; j < n; j++)
        //     nums1[i++] = nums2[j];
        // return;

        //Time o(m+n)
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[i + j + 1] = nums1[i];
                i--;
            }
            else
            {
                nums1[i + j + 1] = nums2[j];
                j--;
            }
        }
        while (j >= 0)
        {
            nums1[j] = nums2[j];
            j--;
        }
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {4, 5, 6};
    Solution s;
    s.merge(v, 3, v2, 3);
    for (int x : v)
        cout << x << " ";
    return 0;
}
