class Solution {
public:
    string longestPalindrome(string s) {
        int mx = -1;
        int max_l = 0;
        int max_r = 0;

        if(s.size() == 1) return s;
        if(s.size() == 2)  {
            if(s[0] == s[1]) {
                return s;
            } else {
                return string(1, s[0]);
            }
        }
        

        for(int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            bool flag = true;

            while(l >= 0 && r < s.size() && flag) {
                if(s[l] == s[r]) {
                    if(r - l + 1 > mx) {
                        mx = r - l + 1;
                        max_l = l;
                        max_r = r;
                    }
                } else {
                    flag = false;
                }

                l--;
                r++;
            }

            l = i;
            r = i + 1;
            flag = true;

            while(l >= 0 && r < s.size() && flag) {
                if(s[l] == s[r]) {
                    if(r - l + 1 > mx) {
                        mx = r - l + 1;
                        max_l = l;
                        max_r = r;
                    }
                } else {
                    flag = false;
                }

                l--;
                r++;
            }
        }

        string res = "";

        for(int i = max_l; i <= max_r; i++) {
            res += s[i];
        }

        return res;
    }
};
