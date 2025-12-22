class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> cache(m, vector<bool>(n, false));
        int x = 0, y = 0, state = 0;
        vector<int> ans;

        while (ans.size() < m * n) {
            ans.push_back(matrix[x][y]);
            cache[x][y] = true;

            int nextX = x, nextY = y;

            if (state == 0) {
                nextY = y + 1;
                if (nextY >= n || cache[nextX][nextY]) {
                    state = 1; 
                    nextX = x + 1;
                    nextY = y;
                }
            } 
            else if (state == 1) {
                nextX = x + 1;
                if (nextX >= m || cache[nextX][nextY]) {
                    state = 2;
                    nextX = x;
                    nextY = y - 1;
                }
            }
            else if (state == 2) {  
                nextY = y - 1;
                if (nextY < 0 || cache[nextX][nextY]) {
                    state = 3;  
                    nextX = x - 1;
                    nextY = y;
                }
            } else { 
                nextX = x - 1;
                if (nextX < 0 || cache[nextX][nextY]) {
                    state = 0;
                    nextX = x;
                    nextY = y + 1;
                }
            }

            x = nextX;
            y = nextY;
        }

        return ans;
    }
};