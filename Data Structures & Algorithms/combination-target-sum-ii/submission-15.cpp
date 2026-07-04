class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, cur, target, 0);

        /*vector<vector<int>> trueRes;

        for(auto v : res) {
            vector<int> l;
            for(auto n : v) {
                l.push_back(candidates[n]);
            }
            trueRes.push_back(l);
        }

        return trueRes;*/
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& curr, int targ, int idx) {
        if(targ == 0) {
            res.push_back(curr);
            return;
        } 
        
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            if (nums[i] > targ) continue;

            curr.push_back(nums[i]);
            dfs(nums, curr, targ - nums[i], i + 1);
            curr.pop_back();
        }
    }
};
