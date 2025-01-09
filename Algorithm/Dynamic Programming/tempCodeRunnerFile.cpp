#include <bits/stdc++.h>
using namespace std;

void lcs(string S)
{
    int n = S.length();
    cout << n << endl ;

    int dp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j ) {
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
            if(S[i] == S[j])
            {if ((dp[i][j-1] == 1) || dp[i + 1][j - 1] == 1)
                dp[i][j] = 1;
                }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }



}

int main()
{
    string S = "AAAABBAA";
    lcs(S);
    return 0;
}
