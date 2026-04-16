class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        map<char, int> k;

        for(auto c : s)
            m[c]++;
        for(auto c : t)
            k[c]++;
        
        for(auto [x, y] : m) {
            if(y != k[x])
                return false;
        }

        for(auto [x, y] : k) {
            if(y != m[x])
                return false;
        }

        return true;
    }   
};
