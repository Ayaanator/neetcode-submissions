class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size() - 1;

        int mx = -1;

        mx = max(min(heights[p1], heights[p2]) * (p2 - p1), mx);

        while(p1 < p2) {
            if(heights[p2] > heights[p1]) {
                p1++;
            } else {
                p2--;
            }

            mx = max(min(heights[p1], heights[p2]) * (p2 - p1), mx);
        }

        return mx;
    }
};
