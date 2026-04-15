class Solution {
public:

    vector<int> xArr = {-1, 1, 0, 0};
    vector<int> yArr = {0, 0, -1, 1};
    bool checker(int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        deque<pair<int,int>> d;
        d.push_front({0, 0}); 

        while(!d.empty()) {
            auto [x, y] = d.front();
            d.pop_front();

            for(int i = 0; i < 4; i++) {
                int newX = x + xArr[i], newY = y + yArr[i];
                if(checker(newX, newY, m, n)) {
                    int newCost = dist[x][y] + grid[newX][newY];
                    if(newCost < dist[newX][newY]) {
                        dist[newX][newY] = newCost;
                        if(dist[newX][newY] == 0) d.push_front({newX, newY});
                        else d.push_back({newX, newY});
                    }
                }
            }

        }
        return dist[m - 1][n - 1] < health ? true : false; 
    }
};