class Solution {
public:
    int INF = 1e7;
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);
        vector<pair<int, int>> ans;
        int targ = t.size();
        int ctr = 0;
        int mn = INF;

        int r = 0;
        int l = 0;

        for(auto c : t) {
            if(freq[c] == INF) freq[c] = -1;
            else freq[c]--;
        }

        while(r < s.size()) {
            freq[s[r]]++;

            if(freq[s[r]] <= 0) {
                ctr++;
            }

            while(ctr >= targ) {

                if(mn > r - l + 1) {
                    mn = r - l + 1;
                    ans.push_back({l, r});
                }

                freq[s[l]]--;
                
                if(freq[s[l]] < 0) {
                    ctr--;
                }
                l++;
            }
            r++;
        }

        if(ans.empty()) return "";

        string res;
        auto [rl, rr] = ans[ans.size() - 1];
        for(int i = rl; i <= rr; i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};
