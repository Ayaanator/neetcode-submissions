class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int mn = 9999999999;
        //vector<int> answers;

        while (left <= right) {
            mid = left + (right - left) / 2;
            mn = min(mn, nums[right]);
            mn = min(mn, nums[left]);
            mn = min(mn, nums[mid]);

            if (nums[mid] > nums[right]) {
                //answers.push_back(nums[mid]);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        //int res = answers[answers.size() - 1];
        return mn;
    }
};
