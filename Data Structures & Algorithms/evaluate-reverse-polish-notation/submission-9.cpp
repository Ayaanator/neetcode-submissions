class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;

        stack<string> stk;
        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        for(int i = 0; i < tokens.size(); i++) {
            stk.push(tokens[i]);

            if(stk.top() == "+") {
                stk.pop();

                int x = stoi(stk.top());
                stk.pop();
                int y = stoi(stk.top());
                stk.pop();

                res = x + y;
                stk.push(to_string(res));

            } else if(stk.top() == "*") {
                stk.pop();

                int x = stoi(stk.top());
                stk.pop();
                int y = stoi(stk.top());
                stk.pop();

                res = x * y;
                stk.push(to_string(res));
            } else if(stk.top() == "/") {
                stk.pop();

                int x = stoi(stk.top());
                stk.pop();
                int y = stoi(stk.top());
                stk.pop();

                res = y / x;
                stk.push(to_string(res));
            } else if(stk.top() == "-") {
                stk.pop();

                int x = stoi(stk.top());
                stk.pop();
                int y = stoi(stk.top());
                stk.pop();

                res = y - x;
                stk.push(to_string(res));
            }
        }

        return res;
    }
};
