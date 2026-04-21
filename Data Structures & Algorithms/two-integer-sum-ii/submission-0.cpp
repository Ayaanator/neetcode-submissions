class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = numbers.size() - 1;
        int p2 = 0;

        while(true) {
            if(numbers[p1] + numbers[p2] == target) {
                return {min(p1 + 1, p2 + 1), max(p1 + 1, p2 + 1)};
            } else if(numbers[p1] + numbers[p2] > target) {
                p1--;
            } else {
                p2++;
            }
        }
    }
};
