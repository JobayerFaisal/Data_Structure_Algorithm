#include <bits/stdc++.h>
using namespace std;

void isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {

                dp[i][j] = dp[i - 1][j];
            }
            else
            {

                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    /*    for (int i = 0; i <= n; i++) {

            for (int j = 0; j <= sum; j++) {
                cout <<dp[i][j] << " " ;
            }
            cout << endl ;
        }*/

    if (dp[n][sum])
        cout << "True";
    else
        cout << "False";
}

int main()
{

    vector<int> arr = {7, 3, 2, 5, 8};
    int sum = 14;

    /*
    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    */
    isSubsetSum(arr, sum);

    return 0;
}