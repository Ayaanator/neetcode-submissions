class Solution {
public:
    vector<vector<int>> res;
    int k = 0;

    void backtrack(vector<int> subset, vector<int>& nums, int n) {
        if(n < nums.size()) {
            backtrack(subset, nums, n + 1);
            subset.push_back(nums[n]);
            backtrack(subset, nums, n + 1);
        } else {
            res.push_back(subset);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        k = nums.size();
        vector<int> subset = {};
        backtrack(subset, nums, 0);
        
        return res;
    }
};
