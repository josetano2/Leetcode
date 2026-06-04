class Solution {
public:

    bool isValid(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isValid(i, j - 1, m, n)) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j - 1]);
                if(isValid(i - 1, j, m, n)) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][j]);
            }
        }

        return dp[m - 1][n - 1];
    }
};