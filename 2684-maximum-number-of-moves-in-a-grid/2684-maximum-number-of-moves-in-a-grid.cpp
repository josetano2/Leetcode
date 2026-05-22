class Solution {
public:

    vector<int> ra = {-1, 0, 1};
    bool isValid(int prevRow, int prevCol, int row, int col, int m, int n, vector<vector<int>>& grid) {
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] <= grid[prevRow][prevCol]) return false;
        return true;
    }

    int dfs(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if(dp[row][col] != -1) return dp[row][col];

        int maxCurr = -1;
        for(int i = 0; i < ra.size(); i++) {
            int newRow = row + ra[i], newCol = col + 1;

            if(isValid(row, col, newRow, newCol, m, n, grid)) {
                maxCurr = max(maxCurr, dfs(newRow, newCol, m, n, grid, dp));
            }
        }
        
        if(maxCurr != -1) dp[row][col] = 1 + maxCurr;
        else dp[row][col] = 0;

        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) ans = max(ans, dfs(i, 0, m, n, grid, dp));
        return ans;
    }
};