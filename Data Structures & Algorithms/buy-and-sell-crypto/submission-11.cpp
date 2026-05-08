class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int mx = -1e8;

        while(right <= prices.size() - 1) {
            mx = max(mx, prices[right] - prices[left]);
            right++;

            if(right <= prices.size() - 1) {
                mx = max(mx, prices[right] - prices[left]);

                if(prices[right] - prices[left + 1] > mx) {
                    left++;
                    mx = prices[right] - prices[left];
                }

                if(prices[right] < prices[left]) {
                    left = right - 1;
                }
            }
        }

        return mx > 0 ? mx : 0;
    }
};
