class Solution {
public:

    vector<int> xArr = {-1, 1, 0, 0};
    vector<int> yArr = {0, 0, -1, 1};

    int m = 0, n = 0;
    bool ans = false;
    bool isValid(int x, int y, char curr, vector<vector<char>>& grid) {
        if(x < 0 || y < 0  || x >= m || y >= n || grid[x][y] != curr) return false;
        return true;
    }
    void dfs(int x, int y, int parentX, int parentY, char curr, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(ans) return;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int newX = x + xArr[i], newY = y + yArr[i];
            if(isValid(newX, newY, curr, grid)) {
                if(visited[newX][newY] && !(newX == parentX && newY == parentY)) ans = true;
                if(!visited[newX][newY]) dfs(newX, newY, x, y, curr, grid, visited);
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    dfs(i, j, i, j, grid[i][j], grid, visited);
                }
                if(ans) return true;
            }
        }

        return ans;
    }
};