class Solution {
public:
    bool isValid(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                 int x, int y) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() ||
            visited[y][x] || grid[y][x] == 0)
            return false;
        return true;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x,
             int y) {
        visited[y][x] = true;
        int area = 1;
        if (isValid(grid, visited, x + 1, y))
            area += dfs(grid, visited, x + 1, y);
        if (isValid(grid, visited, x - 1, y))
            area += dfs(grid, visited, x - 1, y);
        if (isValid(grid, visited, x, y + 1))
            area += dfs(grid, visited, x, y + 1);
        if (isValid(grid, visited, x, y - 1))
            area += dfs(grid, visited, x, y - 1);
        
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int x = grid[0].size();
        int y = grid.size();
        int ans = 0;
        vector<vector<bool>> visited(y, vector<bool>(x, false));
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, visited, j, i));
                }
            }
        }

        return ans;
    }
};