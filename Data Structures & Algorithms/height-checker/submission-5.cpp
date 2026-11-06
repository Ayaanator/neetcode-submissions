class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights.size());
        for(int i = 0; i < heights.size(); i++) {
            sorted[i] = heights[i];
        }
        sort(sorted.begin(), sorted.end());

        int ctr = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != sorted[i]) ctr++;
        }

        return ctr;
    }
};