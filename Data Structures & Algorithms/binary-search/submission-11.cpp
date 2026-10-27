class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (r + l) / 2;

        while(l <= r) {
            if(nums[mid] > target) {
                r = mid - 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }

            mid = (r + l) / 2;
        }

        return -1;
    }
};
