class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& curr, vector<int>& arr, int n) {

        if(n < arr.size()) {
            curr.push_back(arr[n]);

            dfs(curr, arr, n + 1);
            
            curr.pop_back();

            while(n + 1 < arr.size() && arr[n] == arr[n + 1]) n++;
            
            dfs(curr, arr, n + 1);
            
        } else {
            res.push_back(curr);
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(temp, nums, 0);
        return res;
    }
};
