class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        int l = 0; int r = 0;
        int mx = 0;
        while(r < s.size()) {
            freq[s[r]]++;
            
            while(freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};
