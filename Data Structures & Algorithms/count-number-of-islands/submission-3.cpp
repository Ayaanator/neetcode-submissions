class Solution {
public:
    bool inRange(vector<vector<char>>& g, int x, int y) {
        return x >= 0 && x < g.size() && y >= 0 && y < g[0].size();
    }

    void search(vector<vector<char>>& g, vector<vector<bool>>& v, int x, int y) {
        if(inRange(g, x, y) && !v[x][y] && g[x][y] == '1') {
            v[x][y] = true;

            search(g, v, x + 1, y);
            search(g, v, x - 1, y);
            search(g, v, x, y + 1);
            search(g, v, x, y - 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int ctr = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ctr++;
                    search(grid, vis, i, j);
                }
            }
        }

        return ctr;
    }
};
