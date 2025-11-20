class Solution {
public:

    bool validate(int row, int col, vector<vector<int>>& grid) {
        
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || grid[row][col] == 2) {
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<vector<int>> visited = grid;

        queue<pair<int, int>> rottenQueues;
        int totalNormalOranges = 0;

        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < numCols; col++) {
                if(grid[row][col] == 2) {
                    rottenQueues.push({ row, col });
                }
                else if(grid[row][col] == 1) {
                    totalNormalOranges++;
                }
            }
        }

        if(totalNormalOranges == 0) return 0; 

        int minutes = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while(!rottenQueues.empty()) {
            int size = rottenQueues.size();
            cout << size << endl;

            // Do BFS Here
            while(size > 0) {
                auto [x, y] = rottenQueues.front();
                rottenQueues.pop();
                for(int i = 0; i < directions.size(); i++) {
                    auto [adjX, adjY] = directions[i];

                    int newX = x + adjX;
                    int newY = y + adjY;

                    if(validate(newX, newY, visited)) {
                        visited[newX][newY] = 2;
                        totalNormalOranges--;
                        rottenQueues.push({ newX, newY });
                    }
                }
                size--;
            }
            minutes++;
        }

        if(totalNormalOranges == 0) return minutes - 1;

        return -1;
        
    }
};