#include <bits/stdc++.h>
using namespace std;

char soloDance(string s, int n)
{
    map<char, int> m;
    int countWithOne = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        m[s[i]]++;

    for (auto it : m)
        if (it.second == 1)
            countWithOne++;

    if (countWithOne >= 3)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (m[s[i]] == 1)
                count++;
            if (count == 3)
                return s[i];
        }
    }
    else if (countWithOne == 2)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (m[s[i]] == 1)
                count++;
            if (count == 2)
                return s[i];
        }
    }
    else if (countWithOne == 1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (m[s[i]] == 1)
                count++;
            if (count == 1)
                return s[i];
        }
    }
    else
        return s[0];
}

int main()
{
    string s = "aabdf";
    int n = s.size();
    cout << soloDance(s, n);
    return 0;
}