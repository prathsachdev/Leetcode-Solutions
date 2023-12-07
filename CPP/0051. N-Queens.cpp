class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col) {
        for (int i = 0; i < col; ++i) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
            return false;
            }
        }
        
        for (int i = row, j = col; j >= 0 && i < n; ++i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
    
        for (int row = 0; row < n; ++row) {
            if (isSafe(board, n, row, col)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};