class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ctr = 0;

        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            ctr++;
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ctr++;
                }
            }
        }

        return ctr;
    }
};
