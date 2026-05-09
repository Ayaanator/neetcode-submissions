class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        
        int mx = -1;
        int ctr = 0;

        if(s.size() == 0) {
            return 0;
        } else if(s.size() == 1) {
            return 1;
        }

        int left = 0;
        int right = 0;


        while(right < s.size()) {

            freq[s[right]]++;
            
            while(freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            ctr = right - left + 1;
            mx = max(mx, ctr);

            right++;
        }

        return mx;
    }
};
