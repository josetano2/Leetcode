class Solution {
public:

    int ans(int x, int y, int c, int m, int n, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
        if(x >= m || y >= n) return INT_MIN;
        if(grid[x][y] != 0 && c <= 0) return INT_MIN;
        if(x == m - 1 && y == n - 1) return grid[x][y];

        if(dp[x][y][c] != INT_MIN + 1) return dp[x][y][c];

        int cost = grid[x][y] == 0 ? 0 : 1;
        dp[x][y][c] = max(ans(x + 1, y, c - cost, m, n, dp, grid) + grid[x][y], ans(x, y + 1, c - cost, m, n, dp, grid) + grid[x][y]);
        return dp[x][y][c];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN + 1)));
        int maxNum = ans(0, 0, k, m, n, dp, grid);
        return maxNum < 0 ? -1 : maxNum;
    }
};