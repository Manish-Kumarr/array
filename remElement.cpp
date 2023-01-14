#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &arr, int val)
    {
        int count = 0, i = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            if (arr[i] == val)
                count++;
        if (count == n)
            return 0;
        while (i < n - count)
        {
            if (arr[i] == val)
                for (int j = i; j < n - 1; j++)
                    arr[j] = arr[j + 1];
            else
                i++;
        }
        return n - count;
    }
};

int main()
{
    vector<int> v = {3, 2, 3};
    int val = 3;
    Solution s;
    int newSize = s.removeElement(v, val);
    for (int x = 0; x < newSize; x++)
        cout << v[x] << " ";
    return 0;
}