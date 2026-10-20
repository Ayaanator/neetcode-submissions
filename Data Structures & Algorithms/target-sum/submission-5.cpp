class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if (abs(target) > sum) return 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum * 2 + 1, 0));
        int mid = sum;
        dp[0][mid] = 1;

        for(int i = 1; i < nums.size() + 1; i++) {
            for(int j = 0; j < sum * 2 + 1; j++) {
                int num = nums[i - 1];
                if(dp[i - 1][j] == 0) continue;
                if(j + num < sum * 2 + 1) dp[i][j + num] += dp[i - 1][j];
                if(j - num >= 0) dp[i][j - num] += dp[i - 1][j];
            }
        }

        return dp[nums.size()][target + mid];
    }
};
