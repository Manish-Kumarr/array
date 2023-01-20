#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int i = 0;
    int j = m - 1;
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (matrix[i][j] == x)
            return true;
        else if (x > matrix[i][j])
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {27, 29, 37, 48},
                                  {32, 33, 39, 50}};
    int target = 9;
    cout << search(matrix, matrix.size(), matrix[0].size(), target);

    return 0;
}
