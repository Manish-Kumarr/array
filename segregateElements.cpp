#include <bits/stdc++.h>
using namespace std;

void segregateElements(int *arr, int n)
{
    //Without space -ve number in last
    // int i = 0, j = n - 1;
    // while (i < j)
    // {
    //     if (arr[i] < 0 && arr[j] > 0)
    //         swap(arr[i], arr[j]);
    //     else if (arr[i] > 0)
    //         i++;
    //     if (arr[j] < 0)
    //         j--;
    // }
    //=======================================================================
    //With space
    // int ans[n];
    // int k = 0;
    // for (int i = 0; i < n; i++)
    //     if (arr[i] >= 0)
    //         ans[k++] = arr[i];

    // for (int i = 0; i < n; i++)
    //     if (arr[i] < 0)
    //         ans[k++] = arr[i];

    // for (int i = 0; i < n; i++)
    //     arr[i] = ans[i];
    //=======================================================================

    // Without space -ve number in start
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] >= 0 && arr[j] < 0)
            swap(arr[i], arr[j]);
        else if (arr[i] < 0)
            i++;
        if (arr[j] >= 0)
            j--;
    }
}

int main()
{
    int arr[] = {1,-4,-2,5,3};
    segregateElements(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
