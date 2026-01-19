class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        //m = 3, n = 7
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + mat[i - 1][j - 1];
                cout << x[i][j] << " ";
            }
            cout << endl;
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 1; k <= min(m - i, n - j); k++) {
                    int sum = x[i + k][j + k] - x[i][j + k] - x[i + k][j] + x[i][j];
                    if(sum <= threshold) {
                        ans = max(ans, k);
                    }
                }
            }
        }

        return ans;
        
        
    }
};