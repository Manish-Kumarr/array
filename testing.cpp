#include <bits/stdc++.h>
using namespace std;

string camelCase(string s)
{
    int n = s.length();
    int res_ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
            continue;
        }
        else
            s[res_ind++] = s[i];
    }
    return s.substr(0, res_ind);
}

string pascalCase(string s)
{
    int n = s.length();
    int res_ind = 0;
    s[0] = toupper(s[0]);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
            continue;
        }
        else
            s[res_ind++] = s[i];
    }
    return s.substr(0, res_ind);
}

string kebabCase(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == ' ')
            s[i] = '-';

    return s;
}
string snakeCase(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == ' ')
            s[i] = '_';

    return s;
}

int main()
{
    string str = "user login count";
    cout << camelCase(str) << endl;
    cout << kebabCase(str) << endl;
    cout << snakeCase(str) << endl;
    cout << pascalCase(str) << endl;
    return 0;
}
