#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int i;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (i = 0; i < n - 1; i++)
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                ans.push_back({min(intervals[i][0], intervals[i + 1][0]), max(intervals[i][1], intervals[i + 1][1])});
                i++;
            }
            else
                ans.push_back({intervals[i][0], intervals[i][1]});
        }
        if (i == n - 1)
            ans.push_back({intervals[i][0], intervals[i][1]});
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 4}, {0, 0}};
    // vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans;
    Solution s;
    ans = s.merge(v);
    for (auto x : ans)
        cout << x[0] << " " << x[1] << endl;
    return 0;
}