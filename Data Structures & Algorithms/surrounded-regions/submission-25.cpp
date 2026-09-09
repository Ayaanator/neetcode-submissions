class Solution {
public:
    int ROWS = 0;
    int COLS = 0;

    bool edge(int x, int y) {
        if(x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1) {
            return true;
        }

        return false;
    }

    bool inRange(int x, int y) {
        return x >= 0 && x < ROWS && y >=0 && y < COLS;
    }

    void dfs(vector<vector<char>>& b, int x, int y, vector<vector<bool>>& vis) {
        if(!inRange(x, y) || vis[x][y] || b[x][y] == 'X') return;

        vis[x][y] = true;
        dfs(b, x + 1, y, vis);
        dfs(b, x - 1, y, vis);
        dfs(b, x, y + 1, vis);
        dfs(b, x, y - 1, vis);
    }



    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0, visited);
            if(board[i][COLS - 1] == 'O') dfs(board, i, COLS - 1, visited);
        }

        for(int i = 0; i < COLS; i++) {
            if(board[0][i] == 'O') dfs(board, 0, i, visited);
            if(board[ROWS - 1][i] == 'O') dfs(board, ROWS - 1, i, visited);
        }

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
