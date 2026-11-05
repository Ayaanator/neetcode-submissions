class Solution {
public:
    int ROWS = 0;
    int COLS = 0;
    int mx = 0;
    int ctr = 0;

    bool inRange(int x, int y) {
        return x >= 0 && x < ROWS && y >= 0 && y < COLS;
    }

    void dfs(vector<vector<bool>>& v, vector<vector<int>>& g, int x, int y) {
        if(inRange(x, y) && !v[x][y] && g[x][y] == 1) {
            ctr++;
            v[x][y] = true;
            dfs(v, g, x + 1, y);
            dfs(v, g, x - 1, y);
            dfs(v, g, x, y + 1);
            dfs(v, g, x, y - 1);
            mx = max(ctr, mx);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    ctr = 0;
                    dfs(vis, grid, i, j);
                }
            }
        }


        return mx;
    }
};
