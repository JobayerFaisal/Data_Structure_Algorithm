#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int WT[], int val[], int n)
{
    int i, w;
    int DP[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (WT[i - 1] <= j)
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - WT[i - 1]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    return DP[n][W];
}

int main()
{
    int profit[] = {2, 3, 4, 5};
    int weight[] = {1, 2, 5, 6};
    int W = 8;
    int n = 4;
    cout << knapSack(W, weight, profit, n);
    return 0;
}