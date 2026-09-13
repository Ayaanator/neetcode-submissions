class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;

        while(l <= r) {
            if(numbers[l] + numbers[r] == target) {
                res.push_back(l);
                res.push_back(r);
                res[0]++;
                res[1]++;
                return res;
            } else if(numbers[l] + numbers[r] > target) {
                r--;
            } else if(numbers[l] + numbers[r] < target) {
                l++;
            }
        }

        return res;
    }
};
