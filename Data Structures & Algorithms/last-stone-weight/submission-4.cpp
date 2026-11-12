class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mx;
        for(auto n : stones) mx.push(n);

        while(mx.size() > 1) {
            int first = mx.top();
            mx.pop();
            int second = mx.top();
            mx.pop();

            if(mx.size() == 0) return first - second;

            if(first > second) {
                mx.push(first - second);
            }
        }

        return mx.top();
    }
};
