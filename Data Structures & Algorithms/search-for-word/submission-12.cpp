class Solution {
public:
    bool flag = false;

    void inBoard(vector<vector<char>>& arr, string w, int idx, int i, int j, vector<vector<bool>>& vis) {
        if(i > -1 && j > -1 && i < arr.size() && j < arr[0].size() && !vis[i][j]) {
            if(w[idx] == arr[i][j]) {
                vis[i][j] = true;
                if(idx == w.size() - 1) {
                    flag = true;
                } else {
                    inBoard(arr, w, idx + 1, i - 1, j, vis);
                    inBoard(arr, w, idx + 1, i + 1, j, vis);
                    inBoard(arr, w, idx + 1, i, j - 1, vis);
                    inBoard(arr, w, idx + 1, i, j + 1, vis);
                    // A B C D 
                    // S A A T 
                    // A C A E
                }
                vis[i][j] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        flag = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    inBoard(board, word, 0, i, j, visited);
                }
            }
        }

        return flag;
    }
};
