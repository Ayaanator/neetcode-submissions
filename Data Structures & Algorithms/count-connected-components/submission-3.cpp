class Solution {
public:
    struct DSU {
        vector<int> par;
        DSU(int n) : par(n) {iota(par.begin(), par.end(), 0);}
        int find(int x) {return par[x] == x ? x : par[x] = find(par[x]);}
        void unite(int x, int y) {par[find(x)] = find(y);}
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto x : edges) {
            dsu.unite(x[0], x[1]);
        }

        set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(dsu.find(i));
        }

        return s.size();
    }
};
