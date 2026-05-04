class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size() - 1;
        int mx = min(heights[p1], heights[p2]) * (p2 - p1);
        int queries = 0;

        while (p1 < p2) {
            heights[p1] < heights[p2] ? p1++ : p2--;
            mx = max(mx, min(heights[p1], heights[p2]) * (p2 - p1));
        }

        return mx;
    }
};
