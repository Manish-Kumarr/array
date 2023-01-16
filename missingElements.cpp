#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {6, 7, 8, 10, 11, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int lo = arr[0];
    int hi = arr[n - 1];
    int diff = lo;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
            while (diff < arr[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
    }
    return 0;
}
