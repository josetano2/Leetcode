class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        

        for(int i = 0; i < 9; i++){

            unordered_map<char, bool> checker;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(checker[board[i][j]]){
                    return false;
                }
                
                checker[board[i][j]] = true;
            }
        }

        for(int i = 0; i < 9; i++){

            unordered_map<char, bool> checker;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.'){
                    continue;
                }
                if(checker[board[j][i]]){
                    return false;
                }
                
                checker[board[j][i]] = true;
            }
        }

        // 0 0, 0 1, 0 2 | 0 3, 0 4, 0 5
        // 1 0, 1 1, 1 2 | 1 3, 1 4, 1 5
        // 2 0, 2 1, 2 2 | 2 3, 2 4, 2 5

        int xStart = 0, yStart = 0;
        while(xStart < 9 && yStart < 9){
            unordered_map<char, bool> checker;

            for(int i = yStart; i < yStart + 3; i++){
                for(int j = xStart; j < xStart + 3; j++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    if(checker[board[i][j]]){
                        return false;
                    }
                    
                    checker[board[i][j]] = true;
                }
            }

            // 0 0
            // 0 3
            // 0 6
            // 0 9 -> 3 0
            xStart += 3;
            if(xStart == 9 && yStart < 9){
                xStart = 0;
                yStart += 3;
            }

        }

        return true;

    }
};