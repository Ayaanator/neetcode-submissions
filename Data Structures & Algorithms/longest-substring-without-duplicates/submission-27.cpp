class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = -1;
        vector<int> count(128, 0);

        int l = 0;
        int r = -1;

        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;

        while(r + 1 < s.size()) {
            r++;
            int idx = s[r];
            count[idx]++;

            while(count[idx] > 1) {
                count[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};
