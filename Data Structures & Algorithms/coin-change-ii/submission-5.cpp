    class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
            for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;

            for(int i = 0; i < dp[0].size(); i++) {
                if(i - coins[0] >= 0 && dp[0][i - coins[0]] > 0) {
                    dp[0][i] = 1;
                }
            }

            for(int i = 1; i < dp.size(); i++) {
                for(int j = 0; j < dp[0].size(); j++) {
                    if(j - coins[i] >= 0 && dp[i][j - coins[i]] > 0) {
                        dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            return dp[dp.size() - 1][amount];
        }
    };
