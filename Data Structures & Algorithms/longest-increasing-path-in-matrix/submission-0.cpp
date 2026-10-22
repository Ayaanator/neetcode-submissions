class Solution {
public:
    int ROWS = 0;
    int COLS = 0;
    vector<vector<int>> dp;
    vector<vector<int>> m;

    bool inRange(int x, int y) { return x >= 0 && y >= 0 && x < ROWS && y < COLS; }

    int dfs(int prev, int x, int y) {
        if (!inRange(x, y) || m[x][y] <= prev) return 0;
        if (dp[x][y] != 0) return dp[x][y];

        int best = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            best = max(best, 1 + dfs(m[x][y], x + dx[d], y + dy[d]));
        }

        dp[x][y] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix;
        ROWS = m.size();
        COLS = m[0].size();
        dp = vector<vector<int>>(ROWS, vector<int>(COLS, 0));

        int result = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                result = max(result, dfs(-1, r, c));
            }
        }
        return result;
    }
};