class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for(int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k++] = L[i++];
        }

        while(j < n2) {
            arr[k++] = R[j++];
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if(left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    vector<vector<int>> twoSum(vector<int>& numbers, int offset) {
        int p1 = numbers.size() - 1;
        int p2 = 0;
        vector<vector<int>> results;

        while(p2 < p1) {

            while (p2 == offset || p2 == p1) {
                p2++;
            }

            while (p1 == offset || p2 == p1) {
                p1--;
            }

            if(numbers[p1] + numbers[p2] + numbers[offset] == 0) {
                //return {min(p1, p2), max(p1, p2)};
                results.push_back({min(p1, p2), max(p1, p2)});
                p1--;
                p2++;
            } else if(numbers[p1] + numbers[p2] + numbers[offset] > 0) {
                p1--;

                if(p1 == offset) {
                    p1--;
                }
            } else {
                p2++;

                if(p2 == offset) {
                    p2++;
                }
            }
        }

        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
