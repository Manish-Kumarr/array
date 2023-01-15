#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a, int n)
{
    //   Write your code here
    int i = 0, curr = 0;
    int j = n - 1;

    while (curr <= j)
    {
        if (a[curr] == 0)
            swap(a[i++], a[curr++]);
        else if (a[curr] == 1)
            curr++;
        else if (a[curr] == 2)
            swap(a[j--], a[curr]);
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 1, 0};
    sort012(arr, arr.size());
    for (int x : arr)
        cout << x << " ";
    return 0;
}
