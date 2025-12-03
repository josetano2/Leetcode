class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int x = coins.size();
        int y = amount;
        vector<vector<long long int>> dp(x + 1, vector<long long int>(y + 1, 0));

        dp[0][0] = 1;
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 0; j <= amount; j++) {
                int prev = 0;
                if(j - coins[i - 1] >= 0) prev = dp[i][j - coins[i - 1]];
                dp[i][j] = dp[i - 1][j] + prev;
            }
        }
        return dp[x][y];
    }
};