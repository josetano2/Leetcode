class Solution {
public:
    vector<int> xArr = {1, -1, 0, 0};
    vector<int> yArr = {0, 0, 1, -1};
    vector<vector<vector<int>>> dp;

    bool checker(int x, int y, int m, int n, vector<vector<bool>>& visited) {
        if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y]) return false;
        return true;
    } 
    bool dfs(int x, int y, int health, vector<vector<bool>>& visited, int& m, int& n, vector<vector<int>>& grid) {
        if(grid[x][y] == 1) health--;
        if(health == 0) return false;
        if(x == m - 1 && y == n - 1) return true;

        if(dp[x][y][health] != -1) return dp[x][y][health];

        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int newX = x + xArr[i], newY = y + yArr[i];
            if(checker(newX, newY, m, n, visited)) {
                if(dfs(newX, newY, health, visited, m, n, grid)) return dp[x][y][health] = true;
            }
        }
        visited[x][y] = false;

        return dp[x][y][health] = false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, health, visited, m, n, grid);
    }
};