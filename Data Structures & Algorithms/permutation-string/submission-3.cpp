class Solution {
public:
    bool checkEqual(vector<int>& v1, vector<int>& v2) {
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        vector<int> freq1(27);
        vector<int> freq2(27);

        freq1[s1[0] - 'a']++;

        for(int i = 1; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }

        freq2[s2[0] - 'a']++;

        if(checkEqual(freq1, freq2)) {
            return true;
        }

        for(int i = 1; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;

            if(i >= s1.size()) {
                freq2[s2[i - s1.size()] - 'a']--;
            }

            if(checkEqual(freq1, freq2)) {
                return true;
            }
        }

        return false;
    }
};
