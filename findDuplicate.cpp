#include <bits/stdc++.h>
using namespace std;

void findDuplicate(vector<int> v, int n)
{
    int lastDup = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[i + 1] && lastDup != v[i])
        {
            cout << v[i] << " ";
            lastDup = v[i];
        }
    }
}

int main()
{
    vector<int> v = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = v.size();
    findDuplicate(v, n);
    return 0;
}
