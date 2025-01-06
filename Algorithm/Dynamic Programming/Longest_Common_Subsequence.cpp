#include <bits/stdc++.h>
using namespace std;

void lcs(string S1, string S2)
{
    int m = S1.length();
    int n = S2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {

            lcs_str.push_back(S1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs_str.begin(), lcs_str.end());

    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;

    cout << "Longest Common Subsequence is: " << lcs_str << endl;

    // return dp[m][n];
}

int main()
{
    string S1 = "ABCDGH";
    string S2 = "AEDFHR";

    lcs(S1, S2);

    return 0;
}
