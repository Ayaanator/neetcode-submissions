class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;

        int o_left = 0;
        int o_right = matrix.size() - 1;
        int o_mid = o_left + (o_right - o_left) / 2;
        int last = matrix[0].size() - 1;

        while(o_left <= o_right && !flag) {
            int o_mid = o_left + (o_right - o_left) / 2;

            if(matrix[o_mid][last] == target) {
                flag = true;
            } else if(matrix[o_mid][last] > target) {
                o_right = o_mid -1;
            } else {
                o_left = o_mid + 1;
            }
        }

        if(search(matrix[o_mid], target) != -1) {
            flag = true;
        } else if(o_mid > 0 && search(matrix[o_mid - 1], target) != -1) {
            flag = true;
        } else if (o_mid < matrix.size() - 1 && search(matrix[o_mid + 1], target) != -1) {
            flag = true;
        }

        return flag;
    }
};
