class Solution {
public:

    int MOD = 1000000007;

    int dp(int i, int j, int s, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& cache) {
        int x = grid.size(), y = grid[0].size();

        if(i == x - 1 && j == y - 1) return (s + grid[i][j]) % k == 0 ? 1 : 0;
        if(i >= x || j >= y) return 0;

        if(cache[i][j][s] != -1) return cache[i][j][s];

        int newSum = (grid[i][j] + s) % k;
        cache[i][j][s] = (dp(i + 1, j, newSum, k, grid, cache) + dp(i, j + 1, newSum, k, grid, cache)) % MOD;

        return cache[i][j][s]; 
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int x = grid.size(), y = grid[0].size();
        vector<vector<vector<int>>> cache(x, vector<vector<int>>(y, vector<int>(k, -1)));

        return dp(0, 0, 0, k, grid, cache);
        
        
    }
};