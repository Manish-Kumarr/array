#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0;
    int n = s.size();
    unordered_map<char, int> umap;
    int mx = 0;

    while (j < n)
    {
        umap[s[j]]++;
        if (umap.size() == j - i + 1)
            mx = max(mx, j - i + 1);
        else if (umap.size() < j - i + 1)
        {
            while (umap.size() < j - i + 1)
            {
                umap[s[i]]--;
                if (umap[s[i]] == 0)
                    umap.erase(s[i]);
                i++;
            }
        }
        j++;
    }

    return mx;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}
