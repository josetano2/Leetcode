class Solution {
public:

    bool validate(int row, int col, vector<vector<char>>& board) {
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == 'X' || board[row][col] == 'T') {
            return false;
        }
        return true;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int, int>> edges;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !(i > 0 && j > 0 && i < m - 1 && j  < n - 1)) {
                    edges.push( {i, j });
                }
            }
        }

        while(!edges.empty()) {
            pair<int, int> curr = edges.front();
            int x = curr.first, y = curr.second;

            board[x][y] = 'T';

            edges.pop();
            for(int i = 0; i < directions.size(); i++) {
                auto [adjX, adjY] = directions[i];

                int newX = x + adjX;
                int newY = y + adjY;

                if(validate(newX, newY, board)) {
                    board[newX][newY] = 'T';
                    edges.push({ newX, newY });
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }

        
    }
};