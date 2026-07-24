class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;
        int minutes = 0;

        vector<vector<int>> dirs = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1} 
        };

        queue<pair<int, int>> q;

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty() && fresh) {
            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

                for(auto& dir : dirs) {
                    int nr = row + dir[0];
                    int nc = col + dir[1];

                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && 
                    grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        if(!fresh) return minutes;
        else return -1;
    }
};
