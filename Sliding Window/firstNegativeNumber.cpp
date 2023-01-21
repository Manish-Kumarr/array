#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> v, int k)
{
    int n = v.size();
    queue<int> q;
    vector<int> ans;
    if (n < k)
        return ans;
    int i = 0, j = 0;
    while (j < n)
    {
        if (v[j] < 0)
            q.push(v[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (q.size() != 0)
                ans.push_back(q.front());
            else
                ans.push_back(0);
            if (q.front() == v[i])
                q.pop();
            i++, j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {11, -16, 28, 0, 80};
    int k = 2;
    vector<int> ans = firstNegative(arr, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}
