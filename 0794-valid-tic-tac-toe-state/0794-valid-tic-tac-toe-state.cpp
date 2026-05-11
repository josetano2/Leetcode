class Solution {
public:

    bool hasWon(vector<string>& board, char c) {
        string winningPiece = "";
        winningPiece.append(3, c);

        for(int i = 0; i < 3; i++) {
            if(board[i] == winningPiece) return true;
        }

        for(int j = 0; j < 3; j++) {
            string s = "";
            s += board[0][j];
            s += board[1][j];
            s += board[2][j];
            if(s == winningPiece) return true;
        }

        // diagonal
        string s = "";
        s += board[0][0];
        s += board[1][1];
        s += board[2][2];
        if(s == winningPiece) return true;

        s = "";
        s += board[2][0];
        s += board[1][1];
        s += board[0][2];        
        if(s == winningPiece) return true;

        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X') x++;
                if(board[i][j] == 'O') o++;
            }
        }
        
        bool xWon = hasWon(board, 'X');
        bool oWon = hasWon(board, 'O');

        if(xWon && oWon) return false;
        if(xWon) {
            if(x == o + 1) return true;
            else return false;
        }

        if(oWon) {
            if(x == o) return true;
            else return false;
        }

        if(x == 0 && o == 1) return false;
        if(x == o || x == o + 1) return true;
        return false;
    }
};