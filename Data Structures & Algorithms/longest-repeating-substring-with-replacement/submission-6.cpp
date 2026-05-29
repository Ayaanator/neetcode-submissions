class Solution {
public:
    int findMax(vector<int>& arr) {
        int mx = -1;

        for(auto n : arr) {
            mx = max(mx, n);
        }

        return mx;
    }

    int characterReplacement(string s, int k) {
        
        ("ABBABB", 1);
        vector<int> freq(26);

        int left = 0;
        int mx = 0;
        int ctr = 0;

        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            int max_length = findMax(freq);

            while(k < (right - left + 1) - max_length) {
                left++;
                freq[s[left - 1] - 'A']--;
            }

            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};
