class Solution {
public:
    vector<vector<char>> globalBoard;
    bool ans = false;
    int xBoard = 0, yBoard = 0;

    bool isValid(int x, int y, vector<vector<bool>>& isChecked) {
        if (x < 0 || y < 0 || x >= xBoard || y >= yBoard) return false;
        if (isChecked[y][x])return false;
        return true;
    }
    void backtrack(int x, int y, int currIdx, string word, vector<vector<bool>>& isChecked) {

        if (!isValid(x, y, isChecked)) return;
        if (globalBoard[y][x] != word[currIdx]) return;
        if (currIdx == word.size() - 1) {
            ans = true;
            return;
        }
        isChecked[y][x] = true;
        
        backtrack(x + 1, y, currIdx + 1, word, isChecked);
        backtrack(x - 1, y, currIdx + 1, word, isChecked);
        backtrack(x, y + 1, currIdx + 1, word, isChecked);
        backtrack(x, y - 1, currIdx + 1, word, isChecked);
        
        isChecked[y][x] = false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {

        xBoard = board[0].size();
        yBoard = board.size();
        globalBoard = board;

        vector<vector<bool>> isChecked(yBoard, vector<bool>(xBoard, false));

        for (int i = 0; i < yBoard; i++) {
            for (int j = 0; j < xBoard; j++) {
                if (board[i][j] == word[0]) {
                    backtrack(j, i, 0, word, isChecked);
                }
            }
        }
        return ans;
    }
};