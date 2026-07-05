class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1) return {nums};
        
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> copy1 = nums;
            copy1.erase(copy1.begin() + i);
            vector<vector<int>> res2 = permute(copy1);

            for(auto &v : res2) {
                v.insert(v.begin(), nums[i]);
                res.push_back(v);
            }
        }

        return res;
    }
};
