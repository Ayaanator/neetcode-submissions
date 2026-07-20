class Solution {
public:
    int mx = 0;
    int count = 0;

    void dfs(vector<vector<int>>& g, vector<vector<bool>>& v, int x, int y) {
        if(inRange(g, x, y) && !v[x][y] && g[x][y] == 1) {
            v[x][y] = true;
            count++;
            mx = max(count, mx);

            dfs(g, v, x + 1, y);
            dfs(g, v, x - 1, y);
            dfs(g, v, x, y + 1);
            dfs(g, v, x, y - 1);
        }
    }

    bool inRange(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    count = 0;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return mx;
    }
};
