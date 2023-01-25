#include <bits/stdc++.h>
using namespace std;

int longSubarrayWithKUniqueChar(string s, int k)
{
    int mx = -1;
    int i = 0, j = 0;
    int n = s.size();
    map<char, int> m;

    while (j < n)
    {
        m[s[j]]++;
        if (m.size() < k)
            j++;
        else if (m.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main()
{
    string s = "aaabb";
    int k = 3;
    cout << longSubarrayWithKUniqueChar(s, k);
    return 0;
}
