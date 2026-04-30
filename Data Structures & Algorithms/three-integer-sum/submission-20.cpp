class Solution {
public:
    int findLargest(vector<int>& arr, int upper) {
        int mx = arr[0];
        int idx = 0;

        for(int i = 0; i <= upper; i++) {
            if(mx < arr[i]) {
                mx = arr[i];
                idx = i;
            }
        }

        return idx;
    }

    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void selectionSort(vector<int>& arr) {
        for(int n = arr.size() - 1; n > 0; n--) {
            int k = findLargest(arr, n);
            swap(arr, n, k);
        }
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
        selectionSort(nums);
        vector<vector<int>> result;
        set<vector<int>> answers;

        for(int i = 0; i < nums.size(); i++) {
            vector<vector<int>> res = twoSum(nums, i);
            if(res.size() > 0) {
                for(auto v : res) {
                    vector<int> vals = {nums[i], nums[v[0]], nums[v[1]]};
                    selectionSort(vals);

                    if(answers.find(vals) == answers.end()) {
                        result.push_back(vals);
                        answers.insert(vals);
                    }
                }
            }
        }

        return result;
    }
};
