class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;
        int oranges = 0;
        int minutes = 0;

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 1) {
                    oranges++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        vector<int> dirs1 = { 0, 0, 1, -1 };
        vector<int> dirs2 = { 1, -1, 0, 0 };

        while(!q.empty() && oranges > 0) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nx = x + dirs1[i];
                    int ny = y + dirs2[i];

                    if(nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        oranges--;
                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }

        return !oranges ? minutes : -1;
    }
};
