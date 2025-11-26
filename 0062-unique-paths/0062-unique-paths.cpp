class Solution {
public:

    int dp(int m, int n, int i, int j, vector<vector<int>>& cache) {
        if(i == m - 1 && j == n - 1) return 1;
        if(i >= m || j >= n) return 0;
        if(cache[i][j] != -1) return cache[i][j];

        int down = dp(m, n, i + 1, j, cache);
        int right = dp(m, n, i, j + 1, cache);
        cache[i][j] = down + right;

        return cache[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dp(m, n, 0, 0, cache);
    }
};