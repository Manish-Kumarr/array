#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {2,3};
    vector<int> arr2 = {3};

    pair<int, int> p;
    unordered_set<int> s;
    for (int i = 0; i < arr1.size(); i++)
        s.insert(arr1[i]);
    for (int i = 0; i < arr2.size(); i++)
        s.insert(arr2[i]);

    p.second = s.size();
    
    for (int i = 0; i < arr1.size(); i++)
    {
        auto x = s.find(arr1[i]);
        s.erase(x);
    }

    int fi = arr2.size() - s.size();
    p.first = fi;

    cout << p.first << " " << p.second << endl;

    return 0;
}
