class Solution {
    public boolean isSafe(char[][] board, int n, int row, int col) {
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
    
    public List<String> construct(char[][] board) {
        List<String> listBoard = new ArrayList<>();
        for (int i = 0; i < board.length; ++i) {
            listBoard.add(String.valueOf(board[i]));
        }
        
        return listBoard;
    }
    
    public void solve(int col, char[][] board, List<List<String>> ans, int n) {
        if (col == n) {
            ans.add(construct(board));
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
    
    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = '.';
            }
        }
        
        List<List<String>> ans = new ArrayList<List<String>>();
        solve(0, board, ans, n);
        return ans;
    }
}