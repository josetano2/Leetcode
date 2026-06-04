class Solution {
public:
    using ll = long long;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), MOD = 1e09 + 7;
        
        vector<vector<ll>> dpMax(m, vector<ll>(n, INT_MIN));
        vector<vector<ll>> dpMin(m, vector<ll>(n, INT_MAX));

        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // candidates left and above
                if(j - 1 >= 0) {
                    dpMin[i][j] = min({dpMin[i][j], dpMin[i][j - 1] * grid[i][j], dpMax[i][j - 1] * grid[i][j]});
                    dpMax[i][j] = max({dpMax[i][j], dpMin[i][j - 1] * grid[i][j], dpMax[i][j - 1] * grid[i][j]});
                }

                if(i - 1 >= 0) {
                    dpMin[i][j] = min({dpMin[i][j], dpMin[i - 1][j] * grid[i][j], dpMax[i - 1][j] * grid[i][j]});
                    dpMax[i][j] = max({dpMax[i][j], dpMin[i - 1][j] * grid[i][j], dpMax[i - 1][j] * grid[i][j]});
                }
            }
        }
        return dpMax[m - 1][n - 1] < 0 ? -1 : dpMax[m - 1][n - 1] % MOD;
    }
};