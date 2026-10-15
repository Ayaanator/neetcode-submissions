class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        
        for (auto c : s) {
            if (isalnum(c)) {
                clean.push_back(tolower(c));
            }
        }

        int l = 0;
        int r = clean.size() - 1;

        while(l <= r) {
            if(clean[l] != clean[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
