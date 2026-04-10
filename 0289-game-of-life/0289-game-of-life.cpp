class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> prev = board;
        vector<int> x = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> y = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int one = 0, zero = 0;
                for(int k = 0; k < 8; k++) {
                    int newI = i + y[k], newJ = j + x[k];
                    if(newI < 0 || newJ < 0 || newI >= m || newJ >= n) continue;                    
                    prev[newI][newJ] == 0 ? zero++ : one++;
                }
                if(board[i][j] == 0) {
                    if(one == 3) board[i][j] = 1;
                }

                else {
                    if(one > 3 || one < 2) board[i][j] = 0;
                }
            }
        }
    }
};