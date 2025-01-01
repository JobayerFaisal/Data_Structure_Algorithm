#include <bits/stdc++.h>
using namespace std;

void count(int coins[], int n, int sum) {
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];

            if ((j - coins[i - 1]) >= 0) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}




int main() {
    int coins[] = {1, 3, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 8;

    count(coins, n, sum);
    return 0;
}