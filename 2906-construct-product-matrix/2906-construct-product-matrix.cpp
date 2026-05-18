class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> p(n * m), s(n * m);

        p[0] = 1;
        for(int k = 1; k < n * m; k++) {
            int i = (k - 1) / n, j = (k - 1) % n;
            p[k] = (p[k - 1] * grid[i][j]) % 12345;
        }

        s[n * m - 1] = 1;
        for(int k = (n * m) - 2; k >= 0; k--) {
            int i = (k + 1) / n, j = (k + 1) % n;
            s[k] = (s[k + 1] * grid[i][j]) % 12345;
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            vector<int> c;
            for(int j = 0; j < n; j++) {
                c.push_back(p[i * n + j] * s[i * n + j] % 12345);
            }
            ans.push_back(c);
        }
        return ans;
    }
};