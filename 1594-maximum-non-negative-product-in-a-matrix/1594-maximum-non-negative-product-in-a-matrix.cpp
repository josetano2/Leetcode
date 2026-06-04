class Solution {
public:
    using ll = long long;
    bool isValid(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), MOD = 1e09 + 7;
        
        vector<vector<ll>> dpMax(m, vector<ll>(n, INT_MIN));
        vector<vector<ll>> dpMin(m, vector<ll>(n, INT_MAX));

        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // candidates left and above
                if(isValid(i, j - 1, m, n)) {
                    dpMin[i][j] = min({dpMin[i][j], dpMin[i][j - 1] * grid[i][j], dpMax[i][j - 1] * grid[i][j]});
                    dpMax[i][j] = max({dpMax[i][j], dpMin[i][j - 1] * grid[i][j], dpMax[i][j - 1] * grid[i][j]});
                }

                if(isValid(i - 1, j, m, n)) {
                    dpMin[i][j] = min({dpMin[i][j], dpMin[i - 1][j] * grid[i][j], dpMax[i - 1][j] * grid[i][j]});
                    dpMax[i][j] = max({dpMax[i][j], dpMin[i - 1][j] * grid[i][j], dpMax[i - 1][j] * grid[i][j]});
                }
            }
        }

        return dpMax[m - 1][n - 1] < 0 ? -1 : dpMax[m - 1][n - 1] % MOD;
    }
};