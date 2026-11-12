class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mx(stones.begin(), stones.end());

        while(mx.size() > 1) {
            int first = mx.top();
            mx.pop();
            int second = mx.top();
            mx.pop();

            if (first != second) {
                mx.push(first - second);
            }
        }

        return mx.empty() ? 0 : mx.top();
    }
};
