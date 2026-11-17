class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char c : tasks) freq[c - 'A']++;

        priority_queue<pair<int, char>> pq;
        queue<pair<int, char>> q;

        for(int i = 0; i < 26; i++)  {
            if(freq[i] > 0) pq.push({freq[i], 'A' + i});
        }

        int t = 0;

        while(!pq.empty() || !q.empty()) {
            t++;

            if(!pq.empty()) {
                auto [f, c] = pq.top();
                pq.pop();
                
                f--;
                freq[c - 'A']--;

                if(f > 0) q.push({t + n, c});
            }

            if(!q.empty() && q.front().first == t) {
                pq.push({freq[q.front().second - 'A'], q.front().second});
                q.pop();
            }
        }

        return t;
    }
};