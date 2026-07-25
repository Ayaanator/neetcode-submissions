class Solution {
public:
    int ROWS = 0;
    int COLS = 0;

    bool inRange(int x, int y) {
        return x >= 0 && x < ROWS && y >= 0 && y < COLS;
    }

    void dfs(vector<vector<bool>>& s, vector<vector<int>>& g, int x, int y, int par) {
        if(inRange(x, y) && !s[x][y] && par <= g[x][y]) {
            s[x][y] = true;

            dfs(s, g, x + 1, y, g[x][y]);
            dfs(s, g, x - 1, y, g[x][y]);
            dfs(s, g, x, y + 1, g[x][y]);
            dfs(s, g, x, y - 1, g[x][y]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        
        vector<vector<int>> res;


        for(int i = 0; i < ROWS; i++) {
            dfs(pacific, heights, i, 0, -1);
            dfs(atlantic, heights, i, COLS - 1, -1);
        }

        for(int i = 0; i < COLS; i++) {
            dfs(pacific, heights, 0, i, -1);
            dfs(atlantic, heights, ROWS - 1, i, -1);
        }

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
