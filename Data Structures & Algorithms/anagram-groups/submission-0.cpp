class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> indices;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            indices[s].push_back(i);
        }

        vector<vector<string>> res;
        for(auto s : indices) {
            vector<string> lst;
            for(int i = 0; i < s.second.size(); i++) {
                lst.push_back(strs[s.second[i]]);
            }
            res.push_back(lst);
        }

        return res;
    }
};
