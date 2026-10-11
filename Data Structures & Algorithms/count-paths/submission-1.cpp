class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        if(m == 1) return 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    dp[i][0] = 1;
                } else if(i == 0) {
                    dp[0][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
