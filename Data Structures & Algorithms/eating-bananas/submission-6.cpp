class Solution {
public:
    int findLargest(vector<int>& arr) {
        int mx = -1;

        for(auto x : arr) {
            mx = max(x, mx);
        }

        return mx;
    }

    int findSmallest(vector<int>& arr, int biggest) {
        int mn = biggest;

        for(auto x : arr) {
            mn = min(x, mn);
        }

        return mn;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = findLargest(piles);
        int og_biggest = right;
        int mid = 0;
        vector<int> mids;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            int hours = 0;

            for(int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + mid - 1) / mid;
            }

            if (hours > h) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }

            if(hours <= h) {
                mids.push_back(mid);
            }
        }

        return findSmallest(mids, og_biggest);
    }
};
