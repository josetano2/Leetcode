class Solution {
public:
    int dp(int i, int j, vector<vector<int>>& grid,
           vector<vector<int>>& cache) {
        int m = grid.size(), n = grid[0].size();
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n || grid[i][j] == 1)
            return 0;
        if (cache[i][j] != -1)
            return cache[i][j];

        int down = dp(i + 1, j, grid, cache);
        int right = dp(i, j + 1, grid, cache);
        cache[i][j] = down + right;

        return cache[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1) return 0; 
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dp(0, 0, obstacleGrid, cache);
    }
};