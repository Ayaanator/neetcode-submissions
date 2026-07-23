class Solution {
public:
    bool inRange(vector<vector<int>>& g, int x, int y) {
        return x >= 0 && x < g.size() && y >= 0 && y < g[0].size();
    }

    void dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int x, int y, int ctr) {
        if(inRange(g, x, y) && g[x][y] != -1 && g[x][y] > ctr) {
            v[x][y] = true;
            g[x][y] = min(g[x][y], ctr);

            dfs(g, v, x + 1, y, ctr + 1);
            dfs(g, v, x - 1, y, ctr + 1);
            dfs(g, v, x, y + 1, ctr + 1);
            dfs(g, v, x, y - 1, ctr + 1);
        }
    }
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0 && !vis[i][j]) {
                    dfs(grid, vis, i + 1, j, 1);
                    dfs(grid, vis, i - 1, j, 1);
                    dfs(grid, vis, i, j + 1, 1);
                    dfs(grid, vis, i, j - 1, 1);
                }
            }
        }

    }
};
