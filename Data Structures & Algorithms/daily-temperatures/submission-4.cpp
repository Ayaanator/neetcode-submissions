class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> nums;

        for(int i = 0; i < temperatures.size(); i++) {
            
            while(!nums.empty() && temperatures[i] > temperatures[nums.top()]) {
                int idx = nums.top();
                nums.pop();
                res[idx] = i - idx;
            }

            nums.push(i);
        }

        return res;
    }
};
