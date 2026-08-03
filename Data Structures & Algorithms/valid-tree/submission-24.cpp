class Solution {
public:
    bool cycle(vector<vector<int>>& a, vector<bool>& v, int parent, int n) {
        v[n] = true;

        for(auto x : a[n]) {
            if(!v[x]) {
                if(cycle(a, v, n, x)) return true;
            } else if(parent != x) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<bool> visiting(n, false);

        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        if(cycle(adj, vis, -1, 0)) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                return false;
            }
        }

        return true;
    }
};
