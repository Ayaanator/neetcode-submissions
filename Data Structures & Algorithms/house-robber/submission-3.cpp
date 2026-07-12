class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);

        if(nums.size() == 1) return nums[0];
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        //dp[2] = nums[0] + nums[2];

        for(int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            dp[i] = max(dp[i], dp[i - 1] - nums[i - 1] + nums[i]);
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};
