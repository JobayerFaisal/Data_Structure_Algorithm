#include <bits/stdc++.h>
using namespace std;

void lcs(string S)
{
    int n = S.length();
    cout << n << endl;

    int dp[n][n];
    int start = n-1, len = 0 ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = 0;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (S[i] == S[j])
            {
                if (( (j-i) == 1) || dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1;
                    start -- ;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string S = "BBABCBCAB";
    lcs(S);
    return 0;
}
