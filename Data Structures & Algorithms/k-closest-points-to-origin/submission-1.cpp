class Solution {
public:
    double dist(vector<int> p) {
        return 1.0 * sqrt((p[0])*(p[0]) + 
        (p[1])*(p[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, 
        vector<pair<double, pair<int, int>>>, 
        greater<pair<double, pair<int, int>>>> pq;

        for(auto n : points) {
            pq.push(make_pair(dist(n), make_pair(n[0], n[1])));
        }

        vector<vector<int>> res;

        for(int i = 0; i < k; i ++) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};
