class Solution {
public:
    int ROWS = 0;
    int COLS = 0;

    bool inRange(int x, int y) {
        return x >= 0 && x < ROWS && y >=0 && y < COLS;
    }

    bool atEdge(int x, int y) {
        return x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1;
    }

    void dfs(vector<vector<bool>>& v, vector<vector<bool>>& e, vector<vector<char>>& 
    b, int x, int y) {
        if(inRange(x, y) && !v[x][y]) {
            if(b[x][y] == 'O') {
                e[x][y] = true;
                v[x][y] = true;

                dfs(v, e, b, x + 1, y);
                dfs(v, e, b, x - 1, y);
                dfs(v, e, b, x, y + 1);
                dfs(v, e, b, x, y - 1);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> edge(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(!vis[i][j] && board[i][j] == 'O' && atEdge(i, j)) {
                    dfs(vis, edge, board, i, j);                   
                }
            }
        }

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == 'O' && !edge[i][j]) {
                    board[i][j] = 'X';                 
                }
            }
        }
    }
};
