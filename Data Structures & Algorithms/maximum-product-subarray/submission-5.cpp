class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());

        if(nums.size() == 1) return nums[0];

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int mx = -1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                int temp = dp_max[i - 1];
                dp_max[i - 1] = dp_min[i - 1];
                dp_min[i - 1] = temp;
            }

            dp_max[i] = max(dp_max[i - 1] * nums[i], nums[i]);
            dp_min[i] = min(dp_min[i - 1] * nums[i], nums[i]);

            mx = max(mx, dp_max[i]);
            mx = max(mx, dp_min[i]);
        }

        return mx;
    }
};
