class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = -1;

        for(auto n : wordDict) {
            max_len = max(max_len, (int)n.size());
        }

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= max(0, i - max_len); j--) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
