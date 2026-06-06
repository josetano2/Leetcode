class Solution {
public:
    vector<string> boardBuilder(vector<int>& colPlacement, int& n) {
        vector<string> v(n, string(n, '.'));
        for(int i = 0; i < n; i++) v[i][colPlacement[i]] = 'Q';
        return v;
    }

    void backtrack(int row, int&n, vector<int>& colPlacement, unordered_set<int>& cs, unordered_set<int>& lds, unordered_set<int>& rds, vector<vector<string>>& ans) {
        if(row == n) {
            // found a solution
            ans.push_back(boardBuilder(colPlacement, n));
            return;
        }

        for(int col = 0; col < n; col++) {
            if(cs.count(col) || lds.count(row + col) || rds.count(col - row)) continue;

            // insert
            cs.insert(col);
            lds.insert(row + col);
            rds.insert(col - row);
            colPlacement[row] = col;
            
            // call backtrack
            backtrack(row + 1, n, colPlacement, cs, lds, rds, ans);

            // remove
            cs.erase(col);
            lds.erase(row + col);
            rds.erase(col - row);
            colPlacement[row] = -1;
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> colPlacement(n, -1);

        unordered_set<int> cs;
        unordered_set<int> lds;
        unordered_set<int> rds;

        backtrack(0, n, colPlacement, cs, lds, rds, ans);
        return ans;
    }
};