#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    // code here
    int k = pat.size();
    int anagramCount = 0;
    int i = 0, j = 0, n = txt.size();
    map<char, int> m;
    for (int i = 0; i < k; i++)
        m[pat[i]]++;

    int count = m.size();

    while (j < n)
    {
        // Initial Step
        for (auto x : m)
            if (x.first == txt[j])
            {
                m[txt[j]]--;
                if (m[txt[j]] == 0)
                    count--;
            }
        // When size is smaller than k
        if (j - i + 1 < k)
            j++;
        // When size is equal
        else if (j - i + 1 == k)
        {
            if (count == 0)
                anagramCount++;
            for (auto x : m)
            {
                if (x.first == txt[i])
                {
                    m[txt[i]]++;
                    if (m[txt[i]] == 1)
                        count++;
                }
            }
            i++, j++;
        }
    }
    return anagramCount;
}

int main()
{
    string txt = "abcba";
    string pat = "ab";
    cout << search(pat, txt);
    return 0;
}
