class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int layer = 0; layer < n / 2; layer++) {
            for (int col = layer; col < n - 1 - layer; col++) {

                int temp = matrix[layer][col];

                matrix[layer][col] = matrix[n - 1 - col][layer];
                matrix[n - 1 - col][layer] = matrix[n - 1 - layer][n - 1 - col];
                matrix[n - 1 - layer][n - 1 - col] = matrix[col][n - 1 - layer];
                matrix[col][n - 1 - layer] = temp;
            }
        }
    }
};