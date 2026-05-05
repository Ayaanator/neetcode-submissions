class Solution {
public:
    bool isValid(string s) {
        map<char, char> chars = { {']', '['}, {'}', '{'}, {')', '('} };
        set<char> add = {'[', '{', '('};

        stack<char> stk;

        for(auto c : s) {
            if(add.find(c) != add.end()) {
                stk.push(c);
            } else if(!stk.empty() && stk.top() == chars[c]) {
                stk.pop();
            } else if(add.find(c) == add.end()) {
                return false;
            }
        }

        return stk.empty();
    }
};
