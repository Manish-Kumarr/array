#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int i = 0, j = -1;
    int n = s.size();
    unordered_map<char, int> umap;
    pair<int, int> p;
    p.first = INT_MAX;
    for (auto x : t)
        umap[x]++;

    int count = umap.size();

    if (n < t.size())
        return "";

    if (s == t)
        return s;

    while (j < n)
    {
        if (count != 0)
        {
            j++;
            if (umap.find(s[j]) != umap.end())
            {
                umap[s[j]]--;
                if (umap[s[j]] == 0)
                    count--;
            }
        }
        while (count == 0 && i < n)
        {
            if (p.first > j - i + 1)
            {
                p = {j - i + 1, i};
            }
            if (umap.find(s[i]) != umap.end())
            {
                umap[s[i]]++;
                if (umap[s[i]] == 1)
                    count++;
            }
            i++;
        }
    }
    if (p.first == INT_MAX)
        return "";
    return s.substr(p.second, p.first);
}

int main()
{
    string s = "ABCGCFAB";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
