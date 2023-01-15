
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int n = digits.size();
        int carry = 0;
        int dig = digits[n - 1] + 1;
        int temp = dig + carry;
        int valueToBePushed = temp % 10;
        carry = temp / 10;
        res.push_back(valueToBePushed);
        for (int i = n - 2; i >= 0; i--)
        {
            dig = digits[i];
            temp = dig + carry;
            valueToBePushed = temp % 10;
            carry = temp / 10;
            res.push_back(valueToBePushed);
        }
        if (carry != 0)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    vector<int> v = {9};
    vector<int> res;
    Solution s;
    res = s.plusOne(v);
    for (int x : res)
        cout << x << " ";
    return 0;
}
