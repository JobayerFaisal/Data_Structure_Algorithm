#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalSearchTree(int keys[], int freq[], int n)
{

    int dp[n + 1][n + 1];
    int root[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {   if (j - i == 0)
            {dp[i][j] = 0;}                 // --> O(n^2)
            else
            {dp[i][j] = INT_MAX;}
        }
    }

    for (int i = 0; i < n; i++)
    {   dp[i][i] = freq[i];                 // --> O(n)
        root[i][i] = i; 
        }


    for (int l = 2; l <= n; l++)
    {                                           // --> n
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;                  // --> n
            int fsum = sum(freq, i, j);

            for (int r = i; r <= j; r++)           // --> n         
                                                                    // --> O(n^3)
            {
                int c = ((r > i) ? dp[i][r - 1] : 0) +
                        ((r < j) ? dp[r + 1][j] : 0) + fsum;          
                if (c < dp[i][j])
                {
                    dp[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }


    cout << "Cost Table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                cout << dp[i][j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Root Table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                cout << root[i][j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}

int main()
{

    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << optimalSearchTree(keys, freq, n);
    return 0;
}
