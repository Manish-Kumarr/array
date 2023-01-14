#include <bits/stdc++.h>
using namespace std;

int removeDup(int arr[], int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[i] == arr[j])
            j++;
        else
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDup(arr, n);
    for (int x = 0; x < newSize; x++)
        cout << arr[x] << " ";
    return 0;
}
