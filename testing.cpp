#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string s, string pattern)
{
    int k = 0;
    string temp = "";
    vector<string> v;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(temp);
            k++;
            temp = "";
        }
        else
            temp = temp + s[i];
    }
    v.push_back(temp);

    map<char, string> m;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (m.find(pattern[i]) != m.end())
        {
            if (m[pattern[i]] != v[i])
                return false;
        }
        else
        {
            for (auto x : m)
                if (x.second == v[i])
                    return false;
            m.insert({pattern[i], v[i]});
        }
    }
    return true;
}

int main()
{
    string pattern = "jquery";
    string str = "jquery";
    cout << wordPattern(str, pattern);
    return 0;
}
