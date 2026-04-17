class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for(auto n : nums) {
            freq[n]++;
        }

        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto i : freq) {
            pq.push({i.second, i.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res(k);

        for (int i = k-1; i >= 0; i--) {
            res[i] = pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};
