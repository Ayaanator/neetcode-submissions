class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mxP = 0;

        for(int i = 1; i < prices.size(); i++) {
            mn = min(mn, prices[i]);
            mxP = max(mxP, prices[i] - mn);
        }

        return mxP;
    }
};
