#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to merge the arrays.
    int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }

    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int i = 0, j = 0, gap = ((m + n) / 2) + ((m + n) % 2);
        while (gap > 0)
        {
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);
            for (j = (gap > n) ? (gap - n) : 0; i < n && j < m; i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
            if (j < m)
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            gap = nextGap(gap);
        }
    }
};

int main()
{
    long long arr1[] = {1, 2, 6, 7, 7, 15, 21, 30, 39, 41, 41, 43, 43, 44, 47, 49};
    long long arr2[] = {5, 7, 9, 17, 24, 27, 30, 32, 35, 41, 49};
    Solution s;
    s.merge(arr1, arr2, 16, 11);
    for (int x : arr1)
        cout << x << " ";
    for (int x : arr2)
        cout << x << " ";

    return 0;
}
