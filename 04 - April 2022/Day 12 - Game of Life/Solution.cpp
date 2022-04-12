class Solution {
public:
    // Initialise variables to store the dimensions of the matrix.
    int m, n;
    // Initialise a direction array.
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    // Function to count the number of live neighbours.
    int count(vector<vector<int>>& board, int i, int j) {
        int res = 0;
        // Check in all directions.
        for (auto d:dir) {
            // Get the new row and column.
            int row = i + d[0], col = j + d[1];
            // If the absolute value of cell is '1', increment 'res'.
            if (row >= 0 && row < m && col >= 0 && col < n && abs(board[row][col]) == 1)
                res++;
        }
        return res;
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        // Traverse the matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Get the count of live neighbours.
                int cnt = count(board, i, j);
                // If the cell is '1'.
                if (board[i][j] == 1) {
                    // If the count is less than 2 or greater than 3, we mark it as negative.
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = -board[i][j];
                }
                // If the cell is '0'.
                else {
                    // We change it to 2.
                    board[i][j] = 2;
                    // If the count is not equal to 3, we mark it as negative.
                    if (cnt != 3)
                        board[i][j] = -board[i][j];
                }
            }
        }
        // Now we convert all the positive values to '1' and negative values to '0'.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
        }
    }
};