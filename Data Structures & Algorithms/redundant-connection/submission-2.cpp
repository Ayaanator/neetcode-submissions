class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int SIZE = edges.size();
        vector<vector<int>> adj(SIZE + 1);
        vector<int> count(SIZE + 1, 0);
        
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            count[x[0]]++;
            count[x[1]]++;
        }

        queue<int> q;

        for (int i = 1; i <= SIZE; i++) {
            if (count[i] == 1) q.push(i);
        }

        while(!q.empty()) {
            int n = q.front();
            q.pop();
            count[n]--;

            for(int x : adj[n]) {
                count[x]--;
                if(count[x] == 1) q.push(x);
            }
        }

        for (int i = SIZE - 1; i >= 0; i--) {
            if (count[edges[i][0]] == 2 && count[edges[i][1]] == 2) return {edges[i][0], edges[i][1]};
        }

        return {};
    }
};
