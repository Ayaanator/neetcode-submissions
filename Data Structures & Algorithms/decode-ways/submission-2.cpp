class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

    int dfs(string s, int n, vector<int>& dp) {
        if(dp[n] != -1) return dp[n];
        else if(s[n] == '0') return 0;
        
        int ways = dfs(s, n + 1, dp);

        if(n + 1 < s.size() && (s[n] == '1' || (s[n] == '2' && s[n + 1] < '7'))) {
            ways += dfs(s, n + 2, dp);
        }

        dp[n] = ways;
        return ways;
    }
};
