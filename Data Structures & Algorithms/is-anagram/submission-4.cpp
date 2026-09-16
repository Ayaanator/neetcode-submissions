class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq1(27, 0);
        vector<int> freq2(27, 0);
        
        for(int i = 0; i < s.size(); i++) {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }

        for(int i = 0; i < 27; i++) {
            if(freq1[i] != freq2[i]) return false;
        }

        return true;
    }
};
