class Solution {
public:

    vector<int> xArr = {1, -1, 0, 0};
    vector<int> yArr = {0, 0, 1, -1};

    bool isValid(int x, int y, int m, int n, vector<vector<int>>& visited, vector<vector<int>>& isWater) {
        if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] == 1 || isWater[x][y] == 1) return false;
        return true;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> grid(isWater.size(), vector<int>(isWater[0].size(), 0));
        vector<vector<int>> visited(isWater.size(), vector<int>(isWater[0].size(), 0));

        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) q.push({i, j});
            }
        }


        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newX = x + xArr[i], newY = y + yArr[i];
                if(isValid(newX, newY, m, n, visited, isWater)) {
                    grid[newX][newY] = grid[x][y] + 1;
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
            visited[x][y] = 1;
        }

        return grid;
    }
};