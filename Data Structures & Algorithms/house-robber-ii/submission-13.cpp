class Solution {
public:
    int rob(vector<int>& nums) {
        int mx = -1;

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.begin(), nums.end() - 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        mx = dp[nums.size() - 2];

        dp = vector<int>(nums.begin() + 1, nums.end());
        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        for(int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i + 1] + dp[i - 2]);
        }

        mx = max(dp[nums.size() - 2], mx);

        return mx;
    }
};
