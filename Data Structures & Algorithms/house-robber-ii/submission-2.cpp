class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size() - 1;
        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        vector<int> dp1(n);
        vector<int> dp2(n);
        
        dp1[0] = first[0];
        dp1[1] = max(first[0], first[1]);

        for(int i = 2; i < n; i++) {
            dp1[i] = max(first[i] + dp1[i - 2], dp1[i - 1]);
        }

        dp2[0] = second[0];
        dp2[1] = max(second[0], second[1]);

        for(int i = 2; i < n; i++) {
            dp2[i] = max(second[i] + dp2[i - 2], dp2[i - 1]);
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};
