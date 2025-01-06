            dp[i][j] = dp[i - 1][j];

            if ((j - coins[i - 1]) >= 0) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
