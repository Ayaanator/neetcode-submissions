class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        for(auto n : points) {
            pq.push(make_pair((n[0])*(n[0]) + 
            (n[1])*(n[1]), 
            make_pair(n[0], n[1])));
        }

        vector<vector<int>> res;

        for(int i = 0; i < k; i ++) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};
