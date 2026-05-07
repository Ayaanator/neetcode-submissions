class Solution {
public:
    int findMinIdx(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int mn = 99999999909;
        int mn_idx;


        while (left <= right) {
            mid = left + (right - left) / 2;

            if(nums[right] < mn) {
                mn_idx = right;
                mn = nums[right];
            }

            if(nums[mid] < mn) {
                mn_idx = mid;
                mn = nums[mid];
            }

            if(nums[left] < mn) {
                mn_idx = left;
                mn = nums[left];
            }

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return mn_idx;
    }

    int search(vector<int>& nums, int target) {
        int cut = findMinIdx(nums);

        int left = cut;
        int right = nums.size() - 1;
        int mid = 0;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        left = 0;
        right = cut - 1;
        mid = 0;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        

        return -1;
    }
};
