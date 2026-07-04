class Solution {
public:
    vector<vector<int>> res;
    vector<int> lst;
    int targ = 0;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset = {};

        targ = target;
        lst = nums;

        dfs(subset, 0);
        return res;
    }

    void dfs(vector<int>& s, int total) {
        if(total < targ) {
            for(int i = 0; i < lst.size(); i++) {
                if(s.size() > 0 && s[s.size() - 1] < i) return;

                total += lst[i];
                s.push_back(i);
                dfs(s, total);

                total -= lst[s[s.size() - 1]];
                s.pop_back();
            }
        }
        if(total == targ) {
            vector<int> sub;
            for(auto n : s) sub.push_back(lst[n]);
            res.push_back(sub);
        }
    }
};
