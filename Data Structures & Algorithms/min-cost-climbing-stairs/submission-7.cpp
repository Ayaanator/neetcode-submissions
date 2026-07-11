class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        int n = cost.size();
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = min(cost[i] + dp[i - 1], cost[i] + dp[i - 2]);
        }

        return min(dp[n - 2], dp[n - 1]);
    }
};
