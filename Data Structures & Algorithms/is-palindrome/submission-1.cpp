class Solution {
public:
    bool isPalindrome(string s) {
        bool flag = true;
        string cleaned = "";
        
        for (auto c : s) {
            if (isalnum(c)) {
                cleaned.push_back(tolower(c));
            }
        }

        int start = 0;
        int end = cleaned.size() - 1;

        while(start <= end) {
            if(cleaned[start] != cleaned[end]) {
                flag = false;
            }

            start++;
            end--;
        }

        return flag;
    }
};
