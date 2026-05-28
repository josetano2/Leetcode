class Solution {
public:
    vector<int> xArr = {1, -1, 0, 0};
    vector<int> yArr = {0, 0, 1, -1};

    bool isValid(int x, int y, int m, int n, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || mat[x][y] == 0) return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(mat[i][j] == 0) q.push({i, j});

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newX = x + xArr[i], newY = y + yArr[i];
                if(isValid(newX, newY, m, n, mat, visited)) {
                    ans[newX][newY] = ans[x][y] + 1;
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }

            visited[x][y] = true;
        }

        return ans;
    }
};