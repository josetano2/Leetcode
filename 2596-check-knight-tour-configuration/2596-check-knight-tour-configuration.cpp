class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid.size() == 3) return false;
        vector<int> x = {-1, -2, -1, -2, 1, 2, 1, 2};
        vector<int> y = {2, 1, -2, -1, -2, -1, 2, 1};

        int currX = 0, currY = 0, next = 1, n = grid.size(), gridSize = pow(n, 2);
        while(next != gridSize - 1) {
            bool flag = false;
            for(int i = 0; i < 8; i++) {
                int nextX = currX + x[i], nextY = currY + y[i];

                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
                if(grid[nextX][nextY] == next) {
                    flag = true;
                    currX = nextX; currY = nextY;
                    next++;
                    break;
                }
            }

            if(!flag) return false;
        }
        
        return true;
    }
};