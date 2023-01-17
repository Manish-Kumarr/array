#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // int n = prices.size();
        // int mx = 0, ans = 0;
        // for (int i = 0; i < n; i++)
        //     for (int j = i + 1; j < n; j++)
        //         if (prices[i] < prices[j])
        //         {
        //             ans = prices[j] - prices[i];
        //             mx = max(mx, ans);
        //         }

        //========================================================
        int n = prices.size();
        int ans = 0;
        int mn = prices[0];
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, prices[i]);
            ans = max(ans, prices[i] - mn);
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 6, 5, 4, 3, 1};
    Solution s;
    cout << s.maxProfit(v);
    return 0;
}
